/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:07:51 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/20 12:57:08 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

/*
Iniciar el vector de dirección inicial
al igual que la camara
 */
static void	init_dir_vector(t_game *data)
{
	if (data->player.angle == 90) // North
	{
		data->player.dir_vector.y = -1;
		data->player.camera_plane.x = -FOV;
	}
	else if (data->player.angle == 270) // South
	{
		data->player.dir_vector.y = 1;
		data->player.camera_plane.x = FOV;
	}
	if (data->player.angle == 0) // East
	{
		data->player.dir_vector.x = 1;
		data->player.camera_plane.y = -FOV;
	}
	if (data->player.angle == 180) // West
	{
		data->player.dir_vector.x = -1;
		data->player.camera_plane.y = FOV;
	}
	data->player.angle *= (PI / 180);
}

int	init_ray_values(t_game *data)
{
	mlx_t	*mlx;

	mlx = data->display.mlx;
	data->display.frames[0] = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	data->display.frames[1] = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	data->display.map = mlx_new_image(mlx, MAP_SIDE, MAP_SIDE);
	if (!data->display.frames[0] || !data->display.frames[0]
		|| !data->display.map)
		return (EXIT_FAILURE);
	init_dir_vector(data);
	return (EXIT_SUCCESS);
}
