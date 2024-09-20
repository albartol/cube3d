/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:28:31 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/20 12:58:29 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check_scene.h>
#include <raycast.h>

// Raycasting:
int	raycast(t_game *data)
{
	data->display.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cube 3D", false);
	if (!data->display.mlx)
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
	if (init_ray_values(data))
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
	if (draw_all(data))
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
	mlx_set_cursor_mode(data->display.mlx, MLX_MOUSE_HIDDEN);
	mlx_image_to_window(data->display.mlx, data->display.frames[0], 0, 0);
	mlx_image_to_window(data->display.mlx, data->display.map, 0, 0);
	mlx_loop_hook(data->display.mlx, game_loop, data);
	mlx_loop(data->display.mlx);
	return (EXIT_SUCCESS);
}

// mlx_win_cursor_t *cursor;
// cursor = mlx_create_std_cursor(MLX_CURSOR_CROSSHAIR);
// if (!cursor)
// 	return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
// mlx_set_cursor(data->display.mlx, cursor);
