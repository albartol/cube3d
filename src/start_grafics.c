/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_grafics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:44:53 by flopez-r          #+#    #+#             */
/*   Updated: 2024/07/22 17:17:05 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PI 3.1415926
#define M_PI_2		1.57079632679489661923	
#include <cube3d.h>

// void	key_functions(mlx_key_data_t keydata, void *param)
// {
// 	t_game	*data;

// 	data = (t_game *)param;
// 	if (keydata.key == MLX_KEY_ESCAPE)
// 		mlx_close_window(data->display.mlx);
// 	if (keydata.key == MLX_KEY_W)
// 		data->display.grafics.player->instances[0].y -= SPEED;
// 	if (keydata.key == MLX_KEY_S)
// 		data->display.grafics.player->instances[0].y += SPEED;
// 	if (keydata.key == MLX_KEY_A)
// 		data->display.grafics.player->instances[0].x -= SPEED;
// 	if (keydata.key == MLX_KEY_D)
// 		data->display.grafics.player->instances[0].x += SPEED;
// }

// void	rotate_key_functions(void *param)
// {
// 	t_game	*data;

// 	data = (t_game *)param;
// 	if (mlx_is_key_down(data->display.mlx, MLX_KEY_LEFT))
// 		printf("izquierdaaa\n");
	
// }

// void	wasd_key_functions(void *param)
// {
// 	t_game	*data;

// 	data = (t_game *)param;
// 	if (mlx_is_key_down(data->display.mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(data->display.mlx);
// 	if (mlx_is_key_down(data->display.mlx, MLX_KEY_W))
// 	{
// 		data->display.grafics.player->instances[0].y -= SPEED;
// 		data->display.grafics.line_ray->instances[0].y -= SPEED;
// 	}
// 	if (mlx_is_key_down(data->display.mlx, MLX_KEY_S))
// 	{
// 		data->display.grafics.player->instances[0].y += SPEED;
// 		data->display.grafics.line_ray->instances[0].y += SPEED;
// 	}
// 	if (mlx_is_key_down(data->display.mlx, MLX_KEY_A))
// 	{
// 		data->display.grafics.player->instances[0].x -= SPEED;
// 		data->display.grafics.line_ray->instances[0].x -= SPEED;
// 	}
// 	if (mlx_is_key_down(data->display.mlx, MLX_KEY_D))
// 	{
// 		data->display.grafics.player->instances[0].x += SPEED;
// 		data->display.grafics.line_ray->instances[0].x += SPEED;
// 	}
// }

double c_radians(double angle)
{
	return ((angle * PI) / 180);
}
void	wasd_key_functions(void *param)
{
	t_player	*player;

	player = (t_player *)param;
	if (mlx_is_key_down(player->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(player->mlx);

	if (mlx_is_key_down(player->mlx, MLX_KEY_LEFT))
	{
		player->angle += R_SPEED;
		printf("Angulo --> %f\n", player->angle / (PI * 180));
	}
	if (mlx_is_key_down(player->mlx, MLX_KEY_RIGHT))
	{
		player->angle -= R_SPEED;
		printf("Angulo --> %f\n", player->angle / (PI * 180));
	}
	

	if (mlx_is_key_down(player->mlx, MLX_KEY_W)/*  || mlx_is_key_down(player->mlx, MLX_KEY_S) */)
	{
		player->x += cos(c_radians(player->angle)) * SPEED;
		player->y += sin(c_radians(player->angle)) * SPEED;
		// player->player->instances[0].x = ;
		// player->player->instances[0].y = ;
	}
	if (mlx_is_key_down(player->mlx, MLX_KEY_S))
	{
		player->x -= cos(c_radians(player->angle)) * SPEED;
		player->y -= sin(c_radians(player->angle)) * SPEED;
	}
	if (mlx_is_key_down(player->mlx, MLX_KEY_A))
	{
		player->x += cos(c_radians(player->angle) - M_PI_2) * SPEED;
		player->y += sin(c_radians(player->angle) - M_PI_2) * SPEED;
	}
	if (mlx_is_key_down(player->mlx, MLX_KEY_D))
	{
		player->x += cos(c_radians(player->angle) + M_PI_2) * SPEED;
		player->y += sin(c_radians(player->angle) + M_PI_2) * SPEED;
	}
	player->player->instances[0].x = player->x;
	player->player->instances[0].y = player->y;
}

int	put_player(t_game *data)
{
	// char	orientation;

	// orientation = data->file.map[data->scene.player_y, data->scene.player_y];
	// if (orientation == 'N')

	// if (mlx_image_to_window(data->display.mlx, data->display.grafics.line_ray, data->scene.player_x * P_SIZE, data->scene.player_y * P_SIZE) == -1)
	// 	return (EXIT_FAILURE);
	if (mlx_image_to_window(data->display.mlx, data->display.grafics.player, data->scene.player_x * P_SIZE, data->scene.player_y * P_SIZE) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	init_images(t_game *data)
{
	data->display.grafics.wall = mlx_new_image(data->display.mlx, P_SIZE, P_SIZE);
	data->display.grafics.player = mlx_new_image(data->display.mlx, 20, 20);
	// data->display.grafics.line_ray = mlx_new_image(data->display.mlx, 3, VISIBILITY);

	if (!data->display.grafics.wall || !data->display.grafics.player /* || 
		!data->display.grafics.line_ray  */)
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
	fill_color(data->display.grafics.wall, 255, 255, 255, 255);
	fill_color(data->display.grafics.player, 30, 202, 75, 255);
	// fill_color(data->display.grafics.line_ray, 82, 255, 51, 255);
	return (EXIT_SUCCESS);
}


// void	draw_lines(void *param)
// {
// 	size_t	i;
// 	t_game *data;

// 	i = 0;
// 	data = (t_game *)param;
// 	while (i < VISIBILITY)
// 	{
// 		if (mlx_image_to_window(data->display.mlx, data->display.grafics.line_ray, data->display.grafics.player->instances[0].x, data->display.grafics.player->instances[0].y) == -1)
// 			mlx_close_window(data->display.mlx);
// 		i++;
// 	}	
// }

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

	player.mlx = data->display.mlx;
	player.angle = 90;
	player.x = data->scene.player_x;
	player.y = data->scene.player_y;
	player.player = data->display.grafics.player;
	
	if (put_player(data))
		return (EXIT_FAILURE);
	// if (draw_lines(data, data->scene.player_x, data->scene.player_y, 1, 1))
	// 	return (EXIT_FAILURE);
		

		
	// mlx_key_hook(data->display.mlx, wasd_key_functions, data);
	mlx_loop_hook(data->display.mlx, wasd_key_functions, &player); // <--- Es mejor usar este
	// mlx_loop_hook(data->display.mlx, rotate_key_functions, data);
	
	mlx_loop(data->display.mlx);
	mlx_terminate(data->display.mlx);
	free_scene_info(&data->file);
	return (EXIT_SUCCESS);
}

	// mlx_get_monitor_size(0, &data->display.width, &data->display.height);
	// mlx_set_setting(MLX_FULLSCREEN, true);
	// data->display.mlx = mlx_init(data->display.width, data->display.height,
	// 	"cube3d", false);