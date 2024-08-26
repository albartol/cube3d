/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:28:31 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/26 12:43:15 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>
#include <check_scene.h>

void	draw_all(t_game *data)
{
	static int	frame;

	draw_img(data, data->display.frames[0]);
	frame = !frame;
}

void	fill_image_prueba(mlx_texture_t *texture, mlx_image_t *img)
{
	uint32_t	x;
	uint32_t	y;
	void		*c;

	x = 0;
	(void)img;
	while (x < texture->width)
	{
		y = 0;
		while (y < texture->height )
		{
			c = &texture->pixels[((y * texture->width) + x) * texture->bytes_per_pixel];
			mlx_put_pixel(img, x, y, *(uint32_t *)c);
			// printf("Color --> %X\n", *(uint32_t *)c);
			/*c = 0;
			c |= texture->pixels[((y * texture->width) + x)];
			c <<= texture->bytes_per_pixel;
			c |= texture->pixels[((y * texture->width) + x + 1)];
			c <<= texture->bytes_per_pixel;
			c |= texture->pixels[((y * texture->width) + x+2)];
			c <<= texture->bytes_per_pixel;
			c |= texture->pixels[((y * texture->width) + x+3)];
			mlx_put_pixel(img, x, y, c);*/

			//mlx_put_pixel(img, x, y, 0xFFFF00FF);
			// mlx_put_pixel(img, x, y, 0xFF0000AA);
			y++;
		}
		x++;
	}
}

int	raycast(t_game *data)
{
	//Raycasting:
	data->display.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cube 3D", false);
	if (!data->display.mlx)
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));

	if (init_ray_values(data))
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));

	//Draw initial image
	if (draw_img(data, data->display.frames[0]))
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));

	// mlx_loop_hook(data->display.mlx, movement, data);
	mlx_key_hook(data->display.mlx, movement, data);
	mlx_loop(data->display.mlx);
	return (EXIT_SUCCESS);
}
