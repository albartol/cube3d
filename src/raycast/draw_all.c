/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:30:07 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/05 11:30:31 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

int	draw_all(t_game *data)
{
	// static int	frame;

	draw_img(data, data->display.frames[0]);//This part need protection
	draw_map(data);
	// frame = !frame;
	return (EXIT_SUCCESS);
}
