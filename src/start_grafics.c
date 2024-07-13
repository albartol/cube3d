/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_grafics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:44:53 by flopez-r          #+#    #+#             */
/*   Updated: 2024/07/13 19:29:10 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	key_functions(mlx_key_data_t keydata, void *param)
{
	t_game	*data;

	data = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(data->display.mlx);
}

int	put_player(t_game *data, mlx_image_t *player)
{
	if (mlx_image_to_window(data->display.mlx, player, data->scene.player_x * P_SIZE, data->scene.player_y * P_SIZE) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	init_images(mlx_image_t **player, mlx_image_t **wall, t_display *display)
{
	*wall = mlx_new_image(display->mlx, P_SIZE, P_SIZE);
	*player = mlx_new_image(display->mlx, 20, 20);
	
	if (!*wall || !*player)
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
	fill_color(*wall, 255, 255, 255, 255);
	fill_color(*player, 30, 202, 75, 255);
	return (EXIT_SUCCESS);
}

int start_grafics(t_game *data)
{
	mlx_image_t	*wall;
	mlx_image_t	*player;

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->display.mlx = mlx_init(data->scene.map_width * P_SIZE, data->scene.map_height * P_SIZE, "cube3d", true);
	if (!data->display.mlx)
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
	if (init_images(&player, &wall, &data->display))
		return (EXIT_FAILURE);
	if (put_map(data->file.map, &data->display, wall))
		return (EXIT_FAILURE);
	if (put_player(data, player))
		return (EXIT_FAILURE);

	mlx_key_hook(data->display.mlx, key_functions, data);
	mlx_loop(data->display.mlx);
	mlx_terminate(data->display.mlx);
	free_scene_info(&data->file);
	return (EXIT_SUCCESS);
}

	// mlx_get_monitor_size(0, &data->display.width, &data->display.height);
	// mlx_set_setting(MLX_FULLSCREEN, true);
	// data->display.mlx = mlx_init(data->display.width, data->display.height,
	// 	"cube3d", false);