/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_grafics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:44:53 by flopez-r          #+#    #+#             */
/*   Updated: 2024/07/13 20:01:25 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	key_functions(void *param)
{
	t_game	*data;

	data = (t_game *)param;
	if (mlx_is_key_down(data->display.mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->display.mlx);
	if (mlx_is_key_down(data->display.mlx, MLX_KEY_W))
		data->display.grafics.player->instances[0].y -= SPEED;
	if (mlx_is_key_down(data->display.mlx, MLX_KEY_S))
		data->display.grafics.player->instances[0].y += SPEED;
	if (mlx_is_key_down(data->display.mlx, MLX_KEY_A))
		data->display.grafics.player->instances[0].x -= SPEED;
	if (mlx_is_key_down(data->display.mlx, MLX_KEY_D))
		data->display.grafics.player->instances[0].x += SPEED;
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

	// mlx_key_hook(data->display.mlx, key_functions, data);
	mlx_loop_hook(data->display.mlx, key_functions, data); // <--- Es mejor usar este
	mlx_loop(data->display.mlx);
	mlx_terminate(data->display.mlx);
	free_scene_info(&data->file);
	return (EXIT_SUCCESS);
}

	// mlx_get_monitor_size(0, &data->display.width, &data->display.height);
	// mlx_set_setting(MLX_FULLSCREEN, true);
	// data->display.mlx = mlx_init(data->display.width, data->display.height,
	// 	"cube3d", false);