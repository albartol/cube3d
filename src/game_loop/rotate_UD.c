/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_UD.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:44:19 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/20 12:47:29 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

void	rotate_ud(t_player *player, double rotation_val, int *draw)
{
	player->move_y += rotation_val * PI;
	if (player->move_y > LIMIT_UP_DOWN)
		player->move_y = LIMIT_UP_DOWN;
	else if (player->move_y < -LIMIT_UP_DOWN)
		player->move_y = -LIMIT_UP_DOWN;
	*draw = 1;
}
