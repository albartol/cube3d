/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:28:31 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/09 19:34:43 by flopez-r         ###   ########.fr       */
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

	// r_data->v_dir.x = 0;
	// r_data->v_dir.y = 0;
	// if (data->scene.angle == 90) //North
	// 	r_data->v_dir.y = -1;
	// if (data->scene.angle == 270) // South
	// 	r_data->v_dir.y = 1;
	// if (data->scene.angle == 0) //East
	// 	r_data->v_dir.x = 1;
	// if (data->scene.angle == 180) // West
	// 	r_data->v_dir.x = -1;
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
		printf("Linea a dibujar --> [%f]\n", line_height);
		printf("\n__________________________\n");
		x++;
	}
	return (EXIT_SUCCESS);
}
