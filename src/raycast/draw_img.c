/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:09:46 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/03 17:05:58 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

uint32_t	get_textured_color(int y_col, double line_h, t_dda *dda)
{
	int			i;
	int			colum;
	int			row;
	uint32_t	result;

	colum = dda->texture->width * dda->x_hit;
	row = (dda->texture->height / line_h) * y_col;

	if (colum < 0)
		colum *= -1;
	if (row < 0)
		row *= -1;
	result = 0;
	i = 0;
	while (i < 4)
	{
		result <<= 8;
		result |= dda->texture->pixels[((row * dda->texture->width) + colum ) * dda->texture->bytes_per_pixel + i++];
	}
	return (result);
}

static int	fill_frame(mlx_image_t *img, double line_h, t_dda *dda, t_game *game)
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
	start = (-line_h / 2) + (WIN_HEIGHT / 2) + game->player.move_y;
	end = (line_h / 2) + (WIN_HEIGHT / 2) + game->player.move_y;
	y = 0;
	while (y < (int)img->height)
	{
		if (y < start)//Sky
			color = game->scene.celling_color;
		else if (y >= start && y < end)//walls
			color = get_textured_color(y - start, line_h, dda);
		else if (y >= end)//chao
			color = game->scene.floor_color;
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
static void	set_cords(t_dda *dda , t_player *player)
{
	//Cambiar la posición de origen según lo que tenga data
	dda->origin.x = player->x + 0.5;
	dda->origin.y = player->y + 0.5;

	//Cambiar el plano de camara según lo que tenga data
	dda->camera_plane.x = player->camera_plane.x;
	dda->camera_plane.y = player->camera_plane.y;

	//Cambiar el vector de dirección según lo que tenga data
	dda->v_dir.x = player->dir_vector.x;
	dda->v_dir.y = player->dir_vector.y;

	// printf(GREEN"\nDIRECTION VECTOR -> (%f, %f)\n"RESET, r_data->v_dir.x, r_data->v_dir.y);
}

void	set_texture(t_dda *dda, t_game *game)
{
	if (!dda->side)
	{
		if (dda->ray_dir.x < 0)
			dda->texture = game->scene.west_texture;
		else
			dda->texture = game->scene.east_texture;
	}
	else
	{
		if (dda->ray_dir.y <= 0)
			dda->texture = game->scene.north_texture;
		else
			dda->texture = game->scene.south_texture;
	}
}

int	draw_img(t_game *game, mlx_image_t *img)
{
	int			x;
	double		line_height;
	t_dda		dda_info;
	
	set_cords(&dda_info, &game->player);
	printf(CYAN"Player angle --------_> %f\n" RESET, game->player.angle);
	// printf(GREEN"Player eje y--------_> %f\n" RESET, game->player.move_y);
	printf(GREEN"Player eje x y--------_> (%f, %f)\n" RESET, game->player.x, game->player.y);
	printf(YELLOW"Vector de dirección--------_> (%f, %f)\n" RESET, game->player.dir_vector.x, game->player.dir_vector.y);
	// printf(YELLOW"origin (%f, %f)\n", ray_data.origin.x, ray_data.origin.y);
	// printf("Direction vector (%f, %f)\n"RESET, ray_data.v_dir.x, ray_data.v_dir.y);
	// printf(GREEN"Camera plane: (%f, %f)\n"RESET, ray_data.camera_plane.x, ray_data.camera_plane.y);
	x = 0;
	while (x < WIN_WIDTH)
	{
		dda_info.map_pos_x = (int)dda_info.origin.x;
		dda_info.map_pos_y = (int)dda_info.origin.y;
		dda_info.camera_x = 2 * x / (double)WIN_WIDTH - 1;
		dda_info.ray_dir.x = dda_info.v_dir.x + (dda_info.camera_plane.x * dda_info.camera_x); //Dirección del rayo
		dda_info.ray_dir.y = dda_info.v_dir.y + (dda_info.camera_plane.y * dda_info.camera_x);

		// DDA_info
		line_height = dda(&dda_info, game->file.map);
		set_texture(&dda_info, game);
		if (fill_frame(img, line_height, &dda_info, game))
			break;
		if (x == 0 || x == WIN_WIDTH -1 )
			printf("Direccion del rayo en la linea %d --> (%f, %f)\n", x, dda_info.ray_dir.x, dda_info.ray_dir.y);
		x++;
	}
	if (mlx_image_to_window(game->display.mlx, img, 0, 0) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
