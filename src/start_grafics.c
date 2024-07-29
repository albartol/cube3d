/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_grafics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:44:53 by flopez-r          #+#    #+#             */
/*   Updated: 2024/07/29 17:07:29 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>
#define PI 3.1415926
#define INIT_ANGLE 90
#define ROTATION_SPEED 5
typedef	struct s_player
{
	mlx_t	*mlx;
	float	x;
	float	y;
	float	angle;
	float	rotation;
	mlx_image_t	*img;
}	t_player;

void	print_pos(t_game *data)
{
	printf("=============================\n");
	printf("Player pos (window)--> (%d, %d)\n", data->display.grafics.player->instances[0].x, data->display.grafics.player->instances[0].y);
	printf("Player pos (  map )--> (%d, %d)\n", data->display.grafics.player->instances[0].x  / P_SIZE, data->display.grafics.player->instances[0].y  / P_SIZE);
	printf("=============================\n");
}

int	init_images(t_game *data)
{
	data->display.grafics.wall = mlx_new_image(data->display.mlx, P_SIZE, P_SIZE);
	data->display.grafics.player = mlx_new_image(data->display.mlx, 20, 20);

	if (!data->display.grafics.wall || !data->display.grafics.player)
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
	fill_color(data->display.grafics.wall, 255, 255, 255, 255);
	fill_color(data->display.grafics.player, 30, 202, 75, 255);
	return (EXIT_SUCCESS);
}

float	transform_angle(float angle)
{
	if (angle > 360)
		return (angle - 360);
	if (angle < 0)
		return (angle + 360);
	return (angle);
}

float	convert_to_radian(float number)
{
	return (number * (PI / 180));
}

void	wasd_key_functions(void *param)
{
	t_player *player;

	player = (t_player *)param;
	if (mlx_is_key_down(player->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(player->mlx);
	//LEFT AND RIGHT
	if (mlx_is_key_down(player->mlx, MLX_KEY_RIGHT))
		player->angle = transform_angle(player->angle - ROTATION_SPEED);
	if (mlx_is_key_down(player->mlx, MLX_KEY_LEFT))
		player->angle = transform_angle(player->angle + ROTATION_SPEED);
	//WASD
	if (mlx_is_key_down(player->mlx, MLX_KEY_W))
	{
		player->x += cos(convert_to_radian(player->angle)) * SPEED;
		player->y -= sin(convert_to_radian(player->angle)) * SPEED;
	}
	if (mlx_is_key_down(player->mlx, MLX_KEY_S))
	{
		player->x -= cos(convert_to_radian(player->angle)) * SPEED;
		player->y += sin(convert_to_radian(player->angle)) * SPEED;
	}
	if (mlx_is_key_down(player->mlx, MLX_KEY_A))
	{
		player->x -= /* sin(convert_to_radian(player->angle)) */ convert_to_radian(90) * SPEED;
		player->y -= cos(convert_to_radian(player->angle)) * SPEED;
	}
	if (mlx_is_key_down(player->mlx, MLX_KEY_D))
	{
		player->x += /* sin(convert_to_radian(player->angle)) */ convert_to_radian(90) * SPEED;
		player->y += cos(convert_to_radian(player->angle)) * SPEED;
	}
	printf("Pos (%f, %f) --> %f - %f \n", player->x, player->y, (player->angle / (180 * PI)), player->angle);
	player->img->instances[0].x = player->x;
	player->img->instances[0].y = player->y;
}


void init_player(t_player *player, t_game *data)
{
	player->mlx = data->display.mlx;
	player->angle = INIT_ANGLE;
	player->rotation = 0.5;
	player->x = data->scene.player_x;
	player->y = data->scene.player_y;
	player->img = data->display.grafics.player;
}

int	put_player(t_player *player)
{
	if (mlx_image_to_window(player->mlx, player->img, player->x * P_SIZE, player->y * P_SIZE) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int start_grafics(t_game *data)
{
	t_player	player;

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->display.mlx = mlx_init(data->scene.map_width * P_SIZE, data->scene.map_height * P_SIZE, "cube3d", true);
	if (!data->display.mlx)
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
	if (init_images(data))
		return (EXIT_FAILURE);
	if (put_map(data->file.map, &data->display, data->display.grafics.wall))
		return (EXIT_FAILURE);
	
	init_player(&player, data);
	
	if (put_player(&player))
		return (EXIT_FAILURE);
	
	mlx_loop_hook(data->display.mlx, wasd_key_functions, &player); // <--- Es mejor usar este
	// mlx_loop_hook(data->display.mlx, get_distance, data);
	
	mlx_loop(data->display.mlx);
	mlx_terminate(data->display.mlx);
	free_scene_info(&data->file);
	return (EXIT_SUCCESS);
}
