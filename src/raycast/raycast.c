/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:28:31 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/15 20:25:18 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>
#include <check_scene.h>

void	draw_all(t_game *data)
{
	static int	frame;

	draw_img(data, data->display.frames[0]);
	mlx_image_to_window(data->display.mlx, data->display.frames[0], 0, 0);
	frame = !frame;
}

int	raycast(t_game *data)
{
	//Raycasting:
	data->display.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cube 3D", false);
	data->display.frames[0] = mlx_new_image(data->display.mlx, WIN_WIDTH, WIN_HEIGHT);
	data->display.frames[1] = mlx_new_image(data->display.mlx, WIN_WIDTH, WIN_HEIGHT);

	init_ray_values(data);

	//Draw initial image
	draw_img(data, data->display.frames[0]);
	mlx_image_to_window(data->display.mlx, data->display.frames[0], 0, 0);

	mlx_key_hook(data->display.mlx, key_events, data);
	mlx_loop(data->display.mlx);
	return (EXIT_SUCCESS);
}
