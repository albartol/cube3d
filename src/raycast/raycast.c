/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:28:31 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/03 14:39:38 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>
#include <check_scene.h>

int	draw_all(t_game *data)
{
	static int	frame;

	draw_map(data, data->display.map[0]);
	draw_img(data, data->display.frames[0]);//This part need protection
	draw_map(data, data->display.map[0]);
	frame = !frame;
	return (EXIT_SUCCESS);
}

int	raycast(t_game *data)
{
	//Raycasting:
	data->display.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cube 3D", false);
	if (!data->display.mlx)
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));

	if (init_ray_values(data))
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));

	//Draw initial image
	if (draw_all(data))
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));

	mlx_set_cursor_mode(data->display.mlx, MLX_MOUSE_HIDDEN);
	mlx_loop_hook(data->display.mlx, hooks, data);
	mlx_loop(data->display.mlx);
	return (EXIT_SUCCESS);
}
