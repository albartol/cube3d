/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:07:51 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/25 15:15:42 by albartol         ###   ########.fr       */
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
	else if (data->player.angle == 0) // East
	{
		data->player.dir_vector.x = 1;
		data->player.camera_plane.y = -FOV;
	}
	else if (data->player.angle == 180) // West
	{
		data->player.dir_vector.x = -1;
		data->player.camera_plane.y = FOV;
	}
	data->player.angle *= (PI / 180);
}

int	init_ray_values(t_game *data)
{
	mlx_t	*mlx;
	uint32_t	map_size;

	map_size = WIN_HEIGHT / MAP_SIDE;
	mlx = data->display.mlx;
	data->display.frame = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->display.frame)
		return (EXIT_FAILURE);
	data->display.map = mlx_new_image(mlx, map_size, map_size);
	if (!data->display.map)
		return (EXIT_FAILURE);
	init_dir_vector(data);
	return (EXIT_SUCCESS);
}
