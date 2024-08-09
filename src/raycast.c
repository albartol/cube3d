/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:28:31 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/09 18:29:23 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>
#include <check_scene.h>

void	set_cords(t_cords *origin, t_cords *v_dir, t_game *data)
{
	origin->x = (data->scene.player_x) + 0.5;
	origin->y = (data->scene.player_y) + 0.5;

	(void)v_dir;
	// v_dir->x = 0;
	// v_dir->y = 0;
	// if (data->scene.angle == 90) //North
	// 	v_dir->y = -1;
	// if (data->scene.angle == 270) // South
	// 	v_dir->y = 1;
	// if (data->scene.angle == 0) //East
	// 	v_dir->x = 1;
	// if (data->scene.angle == 180) // West
	// 	v_dir->x = -1;
}

// Función que determina si hay una pared en las coordenadas (x, y)
int detect_colition(int x, int y, char **map) {
	
	int	width;
	int height;

	width = ft_strlen(map[y])/*  - 1 */;
	height = array_len((const char **)map)/*  - 1 */;

	if ((x < 0 || y < 0) || (x >= width || y >= height) || (map[y][x] == WALL))
		return (1);
	return (0);
}

int	raycast(t_game *data)
{
	t_cords origin; 		// Initial position
	t_cords	v_dir;			// Initial direction vector
	t_cords	camera_plane;	// Plano de camara del jugador --> the FOV is 2 * atan(0.66/1.0)=66°
	t_cords ray_dir;		// La dirección del rayo
	double	camera_x;		// Posicion x del plano de camara
	int		x;

	set_cords(&origin, &v_dir, data);
	printf("origin (%f, %f)\n", origin.x, origin.y);
	// //Rayasting:
	v_dir.x = -1;
	v_dir.y = 0;
	printf("Direction vector (%f, %f)\n", v_dir.x, v_dir.y);

	camera_plane.x = 0;
	camera_plane.y = 0.66;

	//DDA:
	t_cords	delta_dist;		//Razon para calcular la hipotenusa
	t_cords	side_dist;		//Distancia inicial de la hipotenusa de x e y
	t_cords	step;			//Pasos a tomar en x e y
	double	line_height;
	int		side;			//0 for X and 1 for Y
	int		map_pos_x;
	int		map_pos_y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		map_pos_x = (int)origin.x;
		map_pos_y = (int)origin.y;
		camera_x = 2 * x / (double)WIN_WIDTH - 1;
		ray_dir.x = v_dir.x + (camera_plane.x * camera_x); //Dirección del rayo
		ray_dir.y = v_dir.y + (camera_plane.y * camera_x);

		// printf("Camera x --> %f\n", camera_x);
		// printf("Rayo de dirección --> (%f, %f)\n", ray_dir.x, ray_dir.y);

		//DDA (Calculus)
		//Calcular la razon
		if (!ray_dir.x)
			delta_dist.x = __DBL_MAX__;
		else
			delta_dist.x = fabs(1 / ray_dir.x);
		
		if (!ray_dir.y)
			delta_dist.y = __DBL_MAX__;
		else
			delta_dist.y = fabs(1 / ray_dir.y);

		//Calcular que dirección tomarán los pasos
		//Calcular la longitud de la hipotenusa en x e y inicial
		if (ray_dir.x > 0)
		{
			step.x = 1;
			side_dist.x = (map_pos_x + 1 - origin.x) * delta_dist.x;
		}
		else
		{
			step.x = -1;
			side_dist.x = (origin.x - map_pos_x) *  delta_dist.x;
		}
		if (ray_dir.y > 0)
		{
			step.y = 1;
			side_dist.y = (map_pos_y + 1 - origin.y) * delta_dist.y;
		}
		else
		{
			step.y = -1;
			side_dist.y = (origin.y - map_pos_y) *  delta_dist.y;
		}
		//DDA (Algoritmo)
		printf("\n_________Ray #%d_(%f)_________\n", x + 1, camera_x);
		while (!detect_colition(map_pos_x, map_pos_y, data->file.map))
		{
			if (side_dist.x < side_dist.y)
			{
				side_dist.x += delta_dist.x;
				map_pos_x += step.x;
				side = 0;
				printf("Me moví en x %f pasos, pos actual (%d, %d)\n", step.x, map_pos_x, map_pos_y);
			}
			else
			{
				side_dist.y += delta_dist.y;
				map_pos_y += step.y;
				side = 1;
				printf("Me moví en y %f pasos, pos actual (%d, %d)\n", step.y, map_pos_x, map_pos_y);
			}
		}
		
		//Calcular por la distancia perpendicular segun el rayo de impacto x o y
		double	per_wall_distance;
		if (side == 0)
			per_wall_distance = (side_dist.x - delta_dist.x);
		else 
			per_wall_distance = (side_dist.y - delta_dist.y);
		
		//Linea a dibujar en ventana:
		line_height = WIN_HEIGHT / per_wall_distance;
		printf("Linea a dibujar --> [%f]\n", line_height);
		printf("\n__________________________\n");
		x++;
	}

	//Test
	// double distance;

	// while (init_angle < data->scene.angle)
	// {
		// distance = dda(origin, dest, data->file.map);
		// printf("Distacia --> %f\n", distance);
	// 	init_angle++;
	// }
	return (EXIT_SUCCESS);
}
