/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:28:31 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/25 16:02:41 by albartol         ###   ########.fr       */
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
	if (mlx_image_to_window(data->display.mlx, data->display.frame, 0, 0) == -1)
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
	if (mlx_image_to_window(data->display.mlx, data->display.map, 0, 0) == -1)
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
	if (!mlx_loop_hook(data->display.mlx, game_loop, data))
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
	mlx_set_cursor_mode(data->display.mlx, MLX_MOUSE_HIDDEN);
	mlx_loop(data->display.mlx);
	return (EXIT_SUCCESS);
}

// mlx_win_cursor_t *cursor;
// cursor = mlx_create_std_cursor(MLX_CURSOR_CROSSHAIR);
// if (!cursor)
// 	return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
// mlx_set_cursor(data->display.mlx, cursor);
