/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_grafics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:44:53 by flopez-r          #+#    #+#             */
/*   Updated: 2024/07/22 15:53:36 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>
void	print_pos(t_game *data)
{
	printf("=============================\n");
	printf("Player pos (window)--> (%d, %d)\n", data->display.grafics.player->instances[0].x, data->display.grafics.player->instances[0].y);
	printf("Player pos (  map )--> (%d, %d)\n", data->display.grafics.player->instances[0].x  / P_SIZE, data->display.grafics.player->instances[0].y  / P_SIZE);
	printf("=============================\n");
}

void	wasd_key_functions(void *param)
{
	t_game	*data;

	data = (t_game *)param;
	if (mlx_is_key_down(data->display.mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->display.mlx);
	if (mlx_is_key_down(data->display.mlx, MLX_KEY_W))
	{
		data->display.grafics.player->instances[0].y -= SPEED;
		print_pos(data);
	}
	if (mlx_is_key_down(data->display.mlx, MLX_KEY_S))
	{
		data->display.grafics.player->instances[0].y += SPEED;
		print_pos(data);
	}
	if (mlx_is_key_down(data->display.mlx, MLX_KEY_A))
	{
		data->display.grafics.player->instances[0].x -= SPEED;
		print_pos(data);
	}
	if (mlx_is_key_down(data->display.mlx, MLX_KEY_D))
	{
		data->display.grafics.player->instances[0].x += SPEED;
		print_pos(data);
	}

}

int	put_player(t_game *data)
{
	if (mlx_image_to_window(data->display.mlx, data->display.grafics.player, data->scene.player_x * P_SIZE, data->scene.player_y * P_SIZE) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
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

void get_distance(void *param)
{
	t_game		*data;
	mlx_image_t	* player;
	size_t		distance;
	int32_t		x;
	int32_t		y;

	data = (t_game *)param;
	player = data->display.grafics.player;
	x = player->instances[0].x;
	y = player->instances[0].y;
	while (1)
	{
		if ()
	}
}

int start_grafics(t_game *data)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->display.mlx = mlx_init(data->scene.map_width * P_SIZE, data->scene.map_height * P_SIZE, "cube3d", true);
	if (!data->display.mlx)
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
	if (init_images(data))
		return (EXIT_FAILURE);
	if (put_map(data->file.map, &data->display, data->display.grafics.wall))
		return (EXIT_FAILURE);
	if (put_player(data))
		return (EXIT_FAILURE);

	mlx_loop_hook(data->display.mlx, wasd_key_functions, data); // <--- Es mejor usar este
	mlx_loop_hook(data->display.mlx, get_distance, data);

	mlx_loop(data->display.mlx);
	mlx_terminate(data->display.mlx);
	free_scene_info(&data->file);
	return (EXIT_SUCCESS);
}
