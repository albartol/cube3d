/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_LR.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:42:06 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/04 12:13:15 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

static float transform_angle(float angle)
{
	float two_pi = 2.0f * PI;
	
	if (angle > two_pi)
		return (angle - two_pi);
	else if (angle < 0)
		return (angle + two_pi);
	return (angle);
}

void	rotate_LR(t_player *player, double lr, int *draw)
{
	t_cords cos_sin;
	t_cords save_pos;
	t_cords save_plane;

	save_plane.x = player->camera_plane.x;
	save_plane.y = player->camera_plane.y;
	save_pos.x = player->dir_vector.x;
	save_pos.y = player->dir_vector.y;
	cos_sin.x = cos(ROTATION_SPEED_R * lr);
	cos_sin.y = sin(ROTATION_SPEED_R * lr);

	//Rotate the direction vector
	player->dir_vector.x = (save_pos.x * cos_sin.x ) - (save_pos.y * cos_sin.y);
	player->dir_vector.y = (save_pos.x * cos_sin.y ) + (save_pos.y * cos_sin.x);

	//Rotate the camera plane
	player->camera_plane.x = (save_plane.x * cos_sin.x) - (save_plane.y * cos_sin.y);
	player->camera_plane.y = (save_plane.x * cos_sin.y) + (save_plane.y * cos_sin.x);

	if (lr < 0)
		player->angle += transform_angle(ROTATION_SPEED_R);
	else
		player->angle -= transform_angle(ROTATION_SPEED_R);
	*draw = 1;
}
