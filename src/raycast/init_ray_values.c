/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:07:51 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/15 20:08:07 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

void	init_ray_values(t_game *data)
{
	//Vector de dirección inicial
	if (data->player.angle == 90) //North
	{
		data->player.dir_vector.y = -1;
		data->player.camera_plane.x = -FOV;
	}
	else if (data->player.angle == 270) // South
	{
		data->player.dir_vector.y = 1;
		data->player.camera_plane.x = FOV;
	}
	else if (data->player.angle == 0) //East
	{
		data->player.dir_vector.x = 1;
		data->player.camera_plane.y = -FOV;
	}
	if (data->player.angle == 180) // West
	{
		data->player.dir_vector.x = -1;
		data->player.camera_plane.y = FOV;
	}
}
