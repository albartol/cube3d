/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:09:46 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/26 16:59:53 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

uint32_t	get_textured_color(int y_col, double line_h, float x_hit, mlx_texture_t *texture)
{
	int			colum;
	int			row;
	void		*result;

	colum = texture->width * x_hit;
	row = (texture->height / line_h) * y_col;

	if (colum < 0)
		colum *= -1;
	// printf(PURPLE"Texturass %d - %d\n"RESET, texture->width, texture->height);
	//  printf("Colum ==> %d\n", colum);
	//  printf("row ==> %d\n", row);
	result = &texture->pixels[((row * texture->width) + colum ) * texture->bytes_per_pixel];
	return (*(uint32_t *)result);
}

static int	fill_frame(mlx_image_t *img, double line_h, t_dda dda_data, t_game *data)
{
	static	uint32_t	x;
	int					y;
	uint32_t			color;
	int					start;
	int					end;

	if (x > img->width)
	{
		x = 0;
		return (EXIT_FAILURE);
	}
	start = (-line_h / 2) + (WIN_HEIGHT / 2) + data->player.move_y;
	end = (line_h / 2) + (WIN_HEIGHT / 2) + data->player.move_y;
	y = 0;
	while (y < (int)img->height)
	{
		if (y < start)//Sky
			color = data->scene.celling_color;
		else if (y >= start && y < end)//walls
		{
			// if (dda_data.side == 0)
			// 	dda_data.x_hit = 
			color = get_textured_color (y - start, line_h, dda_data.x_hit, data->scene.north_texture);
			if (!dda_data.side)
				color /= 2;
			// color = create_color(255, 13, 123, 145);
		}
		else if (y >= end)//chao
			color = data->scene.floor_color;
		mlx_put_pixel(img, x, y, color);
		y++;
	}
	x++;
	return (EXIT_SUCCESS);
}

/* 
Setea las cordenadas iniciales del player
y determina el vector de dirección segun sea N, S, W o E
el angulo se seteó anteriormente en la función get_view()
del archivo check_map.c
 */
void	set_cords(t_raycast *r_data , t_game *data)
{
	//Cambiar la posición de origen según lo que tenga data
	r_data->origin.x = data->player.x + 0.5;
	r_data->origin.y = data->player.y + 0.5;

	//Cambiar el plano de camara según lo que tenga data
	r_data->camera_plane.x = data->player.camera_plane.x;
	r_data->camera_plane.y = data->player.camera_plane.y;

	//Cambiar el vector de dirección según lo que tenga data
	r_data->v_dir.x = data->player.dir_vector.x;
	r_data->v_dir.y = data->player.dir_vector.y;

	printf(GREEN"\nDIRECTION VECTOR -> (%f, %f)\n"RESET, r_data->v_dir.x, r_data->v_dir.y);
}

int	draw_img(t_game *data, mlx_image_t *img)
{
	int			x;
	t_raycast	ray_data;
	double		line_height;
	t_dda		dda_data;
	
	set_cords(&ray_data, data);
	printf(RED"Player angle --> %f\n"RESET, data->player.angle);
	// printf(YELLOW"origin (%f, %f)\n", ray_data.origin.x, ray_data.origin.y);
	// printf("Direction vector (%f, %f)\n"RESET, ray_data.v_dir.x, ray_data.v_dir.y);
	// printf(GREEN"Camera plane: (%f, %f)\n"RESET, ray_data.camera_plane.x, ray_data.camera_plane.y);
	x = 0;
	while (x < WIN_WIDTH)
	{
		dda_data.map_pos_x = (int)ray_data.origin.x;
		dda_data.map_pos_y = (int)ray_data.origin.y;
		ray_data.camera_x = 2 * x / (double)WIN_WIDTH - 1;
		ray_data.ray_dir.x = ray_data.v_dir.x + (ray_data.camera_plane.x * ray_data.camera_x); //Dirección del rayo
		ray_data.ray_dir.y = ray_data.v_dir.y + (ray_data.camera_plane.y * ray_data.camera_x);

		// DDA
		line_height = dda(&ray_data, &dda_data, data->file.map);
		if (fill_frame(img, line_height, dda_data, data))
			break;
		x++;
	}
	if (mlx_image_to_window(data->display.mlx, data->display.frames[0], 0, 0) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
