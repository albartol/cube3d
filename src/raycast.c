/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:28:31 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/15 19:11:21 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>
#include <check_scene.h>

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

int	fill_frame(mlx_image_t *img, double line_height, int side)
{
	static	uint32_t	x;
	int					y;
	uint32_t			color;
	int					start;
	int					end;

	//End
	if (x > img->width)
	{
		x = 0;
		return (EXIT_FAILURE);
	}

	start = (-line_height / 2) + (WIN_HEIGHT / 2);
	end = (line_height / 2) + (WIN_HEIGHT / 2);

	//Fill
	y = 0;
	while (y < (int)img->height)
	{
		if (y < start)//Sky
			color = create_color(255, 145, 13, 85);
		else if (y >= start && y <= end)//walls
		{
			color = create_color(255, 13, 123, 145);
			if (!side)
				color /= 2;
		}
		else if (y >= end)//chao
			color = create_color(255, 51, 222, 131);
		mlx_put_pixel(img, x, y, color);
		y++;
	}
	x++;
	return (EXIT_SUCCESS);
}

int	draw_img(t_game *data, mlx_image_t *img)
{
	int			x;
	t_raycast	ray_data;
	double		line_height;
	t_dda		dda_data;
	
	x = 0;
	set_cords(&ray_data, data);
	printf(RED"Player angle --> %d\n"RESET, data->player.angle);
	printf(YELLOW"origin (%f, %f)\n", ray_data.origin.x, ray_data.origin.y);
	printf("Direction vector (%f, %f)\n"RESET, ray_data.v_dir.x, ray_data.v_dir.y);
	printf(GREEN"Camera plane: (%f, %f)\n"RESET, ray_data.camera_plane.x, ray_data.camera_plane.y);
	while (x < WIN_WIDTH)
	{
		dda_data.map_pos_x = (int)ray_data.origin.x;
		dda_data.map_pos_y = (int)ray_data.origin.y;
		ray_data.camera_x = 2 * x / (double)WIN_WIDTH - 1;
		ray_data.ray_dir.x = ray_data.v_dir.x + (ray_data.camera_plane.x * ray_data.camera_x); //Dirección del rayo
		ray_data.ray_dir.y = ray_data.v_dir.y + (ray_data.camera_plane.y * ray_data.camera_x);

		// DDA
		line_height = dda(&ray_data, &dda_data, data->file.map);
		if (fill_frame(img, line_height, dda_data.side))
			return (EXIT_SUCCESS);
		x++;
	}
	return (EXIT_FAILURE);
}

void	draw_all(t_game *data)
{
	static int	frame;

	draw_img(data, data->display.frames[0]);
	mlx_image_to_window(data->display.mlx, data->display.frames[0], 0, 0);
	frame = !frame;
}

void	init_ray_values(t_game *data)
{
	//Vector de dirección inicial
	if (data->player.angle == 90) //North
	{
		data->player.dir_vector.y = -1;
		data->player.camera_plane.x = -FOV;
	}
	else if (data->player.angle == 270) // South
	{
		data->player.dir_vector.y = 1;
		data->player.camera_plane.x = FOV;
	}
	else if (data->player.angle == 0) //East
	{
		data->player.dir_vector.x = 1;
		data->player.camera_plane.y = -FOV;
	}
	if (data->player.angle == 180) // West
	{
		data->player.dir_vector.x = -1;
		data->player.camera_plane.y = FOV;
	}
}

int	raycast(t_game *data)
{
	//Raycasting:
	data->display.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cube 3D", false);
	data->display.frames[0] = mlx_new_image(data->display.mlx, WIN_WIDTH, WIN_HEIGHT);
	data->display.frames[1] = mlx_new_image(data->display.mlx, WIN_WIDTH, WIN_HEIGHT);

	init_ray_values(data);

	//Draw initial image
	draw_img(data, data->display.frames[0]);

	mlx_image_to_window(data->display.mlx, data->display.frames[0], 0, 0);
	mlx_key_hook(data->display.mlx, key_events, data);
	mlx_loop(data->display.mlx);
	return (EXIT_SUCCESS);
}
