/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preload_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:33:53 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/26 12:35:10 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>
#include <check_scene.h>

// static void	fill_image(mlx_texture_t *texture, mlx_image_t *dest)
// {
// 	uint32_t	x;
// 	uint32_t	y;
// 	void		*c;

// 	x = 0;
// 	while (x < texture->width)
// 	{
// 		y = 0;
// 		while (y < texture->height )
// 		{
// 			c = &texture->pixels[((y * texture->width) + x) * texture->bytes_per_pixel];
// 			mlx_put_pixel(dest, x, y, *(uint32_t *)c);
// 			y++;
// 		}
// 		x++;
// 	}
// }

int preload_textures(t_game *data)
{
	data->scene.north_texture = mlx_load_png(data->file.north_texture);
	data->scene.south_texture = mlx_load_png(data->file.south_texture);
	data->scene.east_texture = mlx_load_png(data->file.east_texture);
	data->scene.west_texture = mlx_load_png(data->file.west_texture);

	if (!data->scene.north_texture || !data->scene.south_texture ||
		!data->scene.east_texture || !data->scene.west_texture)
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
	return (EXIT_SUCCESS);
}
