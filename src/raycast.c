/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:28:31 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/13 17:31:55 by flopez-r         ###   ########.fr       */
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

	// if (data->player.angle == 90) //North
	// 	r_data->v_dir.y = -1;
	// if (data->player.angle == 270) // South
	// 	r_data->v_dir.y = 1;
	// if (data->player.angle == 0) //East
	// 	r_data->v_dir.x = 1;
	// if (data->player.angle == 180) // West
	// 	r_data->v_dir.x = -1;
	printf(GREEN"\nDIRECTION VECTOR -> (%f, %f)\n"RESET, r_data->v_dir.x, r_data->v_dir.y);
}

int	fill_screen(mlx_image_t *img, double line_height, int side)
{
	static	uint32_t	j;
	uint32_t			color;
	uint32_t			color_background;
	int					start;
	int					end;

	start = (-line_height / 2) + (WIN_HEIGHT / 2);
	end = (line_height / 2) + (WIN_HEIGHT / 2);

	//Segfault controled
	if (start < 0)
		start = 0;
	if (end > WIN_HEIGHT)
		end = WIN_HEIGHT;

	//End
	if (j > img->width)
	{
		j = 0;
		return (EXIT_FAILURE);
	}

	//Color
	color_background = create_color(0, 0, 0, 255);
	color = create_color(243, 133, 229, 255);
	// color = create_color(244, 120, 120, 255);
	if (side == 0)
		color = create_color(167, 67, 154, 255);

	//Fill
	int	i = 0;
	while (i < (int)img->height)
	{
		if (i >= start && i <= end)
			mlx_put_pixel(img, j, i, color);
		else
			mlx_put_pixel(img, j, i, color_background);
		i++;
	}
	j++;
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
	printf(YELLOW"origin (%f, %f)\n", ray_data.origin.x, ray_data.origin.y);
	printf("Direction vector (%f, %f)\n"RESET, ray_data.v_dir.x, ray_data.v_dir.y);
	while (x < WIN_WIDTH)
	{
		dda_data.map_pos_x = (int)ray_data.origin.x;
		dda_data.map_pos_y = (int)ray_data.origin.y;
		ray_data.camera_x = 2 * x / (double)WIN_WIDTH - 1;
		ray_data.ray_dir.x = ray_data.v_dir.x + (ray_data.camera_plane.x * ray_data.camera_x); //Dirección del rayo
		ray_data.ray_dir.y = ray_data.v_dir.y + (ray_data.camera_plane.y * ray_data.camera_x);

		// DDA
		// printf("\n_________Ray #%d_(%f)_________\n", x + 1, ray_data.camera_x);
		line_height = dda(&ray_data, &dda_data, data->file.map);
		if (fill_screen(img, line_height, dda_data.side))
			return (EXIT_SUCCESS);
		// printf("Linea a dibujar --> [%f] hitted by (%d)\n", line_height, dda_data.side);
		// printf("\n__________________________\n");
		x++;
	}
	return (EXIT_FAILURE);
}

void	draw_all(t_game *data)
{
	static int	frame;

	frame = 0;
	draw_img(data, data->display.frames[frame]);
	mlx_image_to_window(data->display.mlx, data->display.frames[frame], 0, 0);
	if (!frame)
		frame = 1;
	else
		frame = 0;
}

int	raycast(t_game *data)
{
	//Raycasting:
	data->display.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cube 3D", false);
	data->display.frames[0] = mlx_new_image(data->display.mlx, WIN_WIDTH, WIN_HEIGHT);
	data->display.frames[1] = mlx_new_image(data->display.mlx, WIN_WIDTH, WIN_HEIGHT);

	//Plano de camara inicial (FOV)
	data->player.camera_plane.x = 0;
	data->player.camera_plane.y = 0.66;
	//Vector de dirección inicial
	data->player.dir_vector.x = -1;
	data->player.dir_vector.y = 0;

	//Draw initial image
	draw_img(data, data->display.frames[0]);

	mlx_image_to_window(data->display.mlx, data->display.frames[0], 0, 0);
	mlx_key_hook(data->display.mlx, key_events, data);
	mlx_loop(data->display.mlx);
	return (EXIT_SUCCESS);
}
