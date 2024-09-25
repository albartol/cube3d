/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_lr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:42:06 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/25 14:29:44 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

static float	transform_angle(float angle)
{
	float	two_pi;

	two_pi = 2.0f * PI;
	if (angle > two_pi)
		return (angle - two_pi);
	else if (angle < 0)
		return (angle + two_pi);
	return (angle);
}

void	rotate_lr(t_player *player, double rotation_val, double lr)
{
	t_cords_d	cos_sin;
	t_cords_d	save_pos;
	t_cords_d	save_plane;

	save_plane.x = player->camera_plane.x;
	save_plane.y = player->camera_plane.y;
	save_pos.x = player->dir_vector.x;
	save_pos.y = player->dir_vector.y;
	rotation_val = (rotation_val * PI) / 180;
	cos_sin.x = cos(rotation_val * lr);
	cos_sin.y = sin(rotation_val * lr);
	// Rotate the direction vector
	player->dir_vector.x = (save_pos.x * cos_sin.x) - (save_pos.y * cos_sin.y);
	player->dir_vector.y = (save_pos.x * cos_sin.y) + (save_pos.y * cos_sin.x);
	// Rotate the camera plane
	player->camera_plane.x = (save_plane.x * cos_sin.x) - (save_plane.y
			* cos_sin.y);
	player->camera_plane.y = (save_plane.x * cos_sin.y) + (save_plane.y
			* cos_sin.x);
	if (lr < 0)
		player->angle += transform_angle(rotation_val);
	else
		player->angle -= transform_angle(rotation_val);
}
