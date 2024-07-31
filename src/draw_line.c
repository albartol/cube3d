/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:34:41 by flopez-r          #+#    #+#             */
/*   Updated: 2024/07/31 17:41:03 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

/* 
I need to implement the DDA or Bresenham Algorithm 
DDA:
	https://www.youtube.com/watch?v=W5P8GlaEOSI
	https://www.youtube.com/watch?v=Q3qNXaIMIlY
BRESENHAM:
	https://www.youtube.com/watch?v=RGB-wlatStc
 */
int draw_line(t_game *data, size_t x1, size_t y1, size_t x2, size_t y2)
{
	size_t	i;

	(void)x2;
	(void)y2;
	i = 0;

	data->display.grafics.player->instances[0].x += SPEED;
	while (i < 200)
	{
		if (mlx_image_to_window(data->display.mlx, 
			data->display.grafics.line_ray, x1 * P_SIZE, (y1 * P_SIZE) + i) == -1)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
