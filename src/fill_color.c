/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:28:49 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/13 13:38:45 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	fill_color(mlx_image_t *img, uint32_t r, uint32_t g, uint32_t b, uint32_t t)
{
	uint32_t	i;
	uint32_t	j;
	uint32_t	color;

	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			color = create_color(r, g, b, t);
			mlx_put_pixel(img, j, i, color);
			j++;
		}
		i++;
	}
}
