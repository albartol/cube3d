/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ud.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:44:19 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/25 14:29:39 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

void	rotate_ud(t_player *player, double rotation_val)
{
	double	limit_up_down;

	limit_up_down = WIN_HEIGHT / 2;
	player->move_y += rotation_val * PI;
	if (player->move_y > limit_up_down)
		player->move_y = limit_up_down;
	else if (player->move_y < -limit_up_down)
		player->move_y = -limit_up_down;
}
