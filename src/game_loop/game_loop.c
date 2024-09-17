/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:11:53 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/17 19:39:23 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

void	game_loop(void *param)
{
	t_game  *data;

	data = (t_game *)param;
	keys_check(data);
	mouse_pov(data);
	if (data->draw)
		draw_all(data);
}
