/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:30:07 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/25 14:57:03 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

// static void	image_to_image(mlx_image_t *src, mlx_image_t *dest)
// {
// 	// uint32_t	x;
// 	uint32_t	y;

// 	y = 0;
// 	while (y < src->height && y < dest->height)
// 	{
// 		ft_memcpy(&dest->pixels[y * dest->width], &src->pixels[y * src->width],
			// src->width);
// 		// x = 0;
// 		// while (x < src->width && x < dest->width)
// 		// {
// 		// 	dest->pixels[y * dest->width + x] = src->pixels[y * src->width + x];
// 		// 	x++;
// 		// }
// 		y++;
// 	}
// }

void	render(t_game *data)
{
	draw_img(data, data->display.frame); // This part need protection
	draw_map(data);
}
