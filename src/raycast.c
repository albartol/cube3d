/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:28:31 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/10 17:43:39 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>
#include <check_scene.h>


/* 
Setea las cordenadas iniciales del player
y determina el vector de dirección segun sea N, S, W o E
 */
void	set_cords(t_raycast *r_data , t_game *data)
{
	r_data->origin.x = (data->scene.player_x) + 0.5;
	r_data->origin.y = (data->scene.player_y) + 0.5;

	r_data->v_dir.x = -1;
	r_data->v_dir.y = 0;

	r_data->v_dir.x = 0;
	r_data->v_dir.y = 0;
	if (data->scene.angle == 90) //North
		r_data->v_dir.y = -1;
	if (data->scene.angle == 270) // South
		r_data->v_dir.y = 1;
	if (data->scene.angle == 0) //East
		r_data->v_dir.x = 1;
	if (data->scene.angle == 180) // West
		r_data->v_dir.x = -1;
	printf("\nDIRECTION VECTOR -> (%f, %f)\n", r_data->v_dir.x, r_data->v_dir.y);
}

uint32_t ft_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t t)
{
	return (r << 24 | g << 16 | b << 8 | t);
}

int	fill_screen(mlx_image_t *img, double line_height, int side)
{
	static	uint32_t	j;
	uint32_t			color;
	int					start;
	int					end;

	start = (-line_height / 2) + (WIN_HEIGHT / 2);
	end = (line_height / 2) + (WIN_HEIGHT / 2);

	// fprintf("draw Startt ===> %d", start);
	// fprintf("draw endddd ===> %d", end);

	//Segfault controled
	if (start < 0)
		start = 0;
	if (end > WIN_HEIGHT)
		end = WIN_HEIGHT;

	//Color
	// color = ft_pixel(243, 133, 229, 255);
	color = ft_pixel(244, 120, 120, 255);
	if (side == 0)
		color = color / 2;

	//End
	if (j > img->width)
		return (EXIT_FAILURE);
	
	//Fill
	while (start < end)
	{
		mlx_put_pixel(img, j, start, color);
		start++;
	}
	j++;
	return (EXIT_SUCCESS);
}

int	raycast(t_game *data)
{
	t_raycast	ray_data;
	t_dda		dda_data;
	double		line_height;
	int			x;

	//Raycasting:
	set_cords(&ray_data, data);
	printf("origin (%f, %f)\n", ray_data.origin.x, ray_data.origin.y);
	printf("Direction vector (%f, %f)\n", ray_data.v_dir.x, ray_data.v_dir.y);

	ray_data.camera_plane.x = 0;
	ray_data.camera_plane.y = 0.66;

	data->display.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cube 3D", false);
	data->display.frames[0] = mlx_new_image(data->display.mlx, WIN_WIDTH, WIN_HEIGHT);
	x = 0;
	while (x < WIN_WIDTH)
	{
		dda_data.map_pos_x = (int)ray_data.origin.x;
		dda_data.map_pos_y = (int)ray_data.origin.y;
		ray_data.camera_x = 2 * x / (double)WIN_WIDTH - 1;
		ray_data.ray_dir.x = ray_data.v_dir.x + (ray_data.camera_plane.x * ray_data.camera_x); //Dirección del rayo
		ray_data.ray_dir.y = ray_data.v_dir.y + (ray_data.camera_plane.y * ray_data.camera_x);

		// DDA
		printf("\n_________Ray #%d_(%f)_________\n", x + 1, ray_data.camera_x);
		line_height = dda(&ray_data, &dda_data, data->file.map);
		if (fill_screen(data->display.frames[0], line_height, dda_data.side))
			break;
		printf("Linea a dibujar --> [%f] hitted by (%d)\n", line_height, dda_data.side);
		printf("\n__________________________\n");
		x++;
	}
	mlx_image_to_window(data->display.mlx, data->display.frames[0], 0, 0);
	mlx_loop_hook(data->display.mlx, key_events, &data->display);
	mlx_loop(data->display.mlx);
	return (EXIT_SUCCESS);
}
