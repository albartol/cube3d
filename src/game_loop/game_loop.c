/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:11:53 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/20 12:40:56 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

void	game_loop(void *param)
{
	t_game	*data;

	data = (t_game *)param;
	keys_check(data);
	mouse_pov(data);
	if (data->draw)
		draw_all(data);
}
