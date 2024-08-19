/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:28:31 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/19 14:46:45 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>
#include <check_scene.h>

void	draw_all(t_game *data)
{
	static int	frame;

	draw_img(data, data->display.frames[0]);
	frame = !frame;
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
	if (draw_img(data, data->display.frames[0]))
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));

	data->player.angle *= (PI / 180);
	
	mlx_loop_hook(data->display.mlx, movement, data);
	// mlx_key_hook(data->display.mlx, movement, data);
	mlx_loop(data->display.mlx);
	return (EXIT_SUCCESS);
}
