/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:05:27 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/26 11:43:00 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>
#include <check_scene.h>

// Función que determina si hay una pared en las coordenadas (x, y)
int detect_colition(int x, int y, char **map)
{
	
	int	width;
	int height;

	width = ft_strlen(map[y])/*  - 1 */;
	height = array_len((const char **)map)/*  - 1 */;

	if ((x < 0 || y < 0) || (x >= width || y >= height) || (map[y][x] == WALL))
		return (1);
	return (0);
}


/*Funcion que:
- Calcula que dirección tomarán los pasos
- Calcula la longitud de la hipotenusa en x e y inicial
 */
static void	get_steps_dist(t_raycast *ray_data, t_dda *dda)
{
	if (ray_data->ray_dir.x > 0)
	{
		dda->step.x = 1;
		dda->side_dist.x = (dda->map_pos_x + 1 - ray_data->origin.x) * dda->delta_dist.x;
	}
	else
	{
		dda->step.x = -1;
		dda->side_dist.x = (ray_data->origin.x - dda->map_pos_x) *  dda->delta_dist.x;
	}
	if (ray_data->ray_dir.y > 0)
	{
		dda->step.y = 1;
		dda->side_dist.y = (dda->map_pos_y + 1 - ray_data->origin.y) * dda->delta_dist.y;
	}
	else
	{
		dda->step.y = -1;
		dda->side_dist.y = (ray_data->origin.y - dda->map_pos_y) *  dda->delta_dist.y;
	}
}

/* 
En física se usa el nombre de "deltas" para indicar
el incremento de una variable (en este caso de la hipotenusa/pendiente de x e y)
por ello fue que en la primera versión que hice del raycast llamé a la estructura de coordenadas
"increment | increment->x, increment->y"
creo que queda mejor con el nombre de "deltas" <(>w <)>
 */
static void	get_deltas(t_raycast *r_data, t_dda *dda_data)
{
	//Calcular la razon
	if (!r_data->ray_dir.x)
		dda_data->delta_dist.x = __DBL_MAX__;
	else
		dda_data->delta_dist.x = fabs(1 / r_data->ray_dir.x);
	
	if (!r_data->ray_dir.y)
		dda_data->delta_dist.y = __DBL_MAX__;
	else
		dda_data->delta_dist.y = fabs(1 / r_data->ray_dir.y);
}

void	get_distance(double *line, t_dda *dda_data, t_raycast *ray_data)
{
	double	per_wall_distance; //Distancia perpendicular de la pared con la camara

	//Calcular por la distancia perpendicular segun el rayo de impacto x o y
	if (dda_data->side == 0)
	{
		per_wall_distance = (dda_data->side_dist.x - dda_data->delta_dist.x);
		dda_data->x_hit = per_wall_distance * ray_data->v_dir.y + ray_data->origin.y;
	}
	else
	{
		per_wall_distance = (dda_data->side_dist.y - dda_data->delta_dist.y);
		dda_data->x_hit = per_wall_distance * ray_data->v_dir.x + ray_data->origin.x;
	}
	dda_data->x_hit = (float)(dda_data->x_hit - (int)dda_data->x_hit);
	//Tamaño de la linea a dibujar en la ventana ahre:
	*line = WIN_HEIGHT / per_wall_distance;
}

double	dda(t_raycast *ray_data, t_dda *dda_data, char **map)
{
	double	line_height;

	//DDA (Calculus)
	get_deltas(ray_data, dda_data);
	get_steps_dist(ray_data, dda_data);

	//DDA (Algoritmo)
	while (!detect_colition(dda_data->map_pos_x, dda_data->map_pos_y, map))
	{
		if (dda_data->side_dist.x < dda_data->side_dist.y)
		{
			dda_data->side_dist.x += dda_data->delta_dist.x;
			dda_data->map_pos_x += dda_data->step.x;
			dda_data->side = 0;
			// printf("Me moví en x %f pasos, pos actual (%d, %d)\n", dda_data->step.x, dda_data->map_pos_x, dda_data->map_pos_y);
		}
		else
		{
			dda_data->side_dist.y += dda_data->delta_dist.y;
			dda_data->map_pos_y += dda_data->step.y;
			dda_data->side = 1;
			// printf("Me moví en y %f pasos, pos actual (%d, %d)\n", dda_data->step.y, dda_data->map_pos_x, dda_data->map_pos_y);
		}
	}

	get_distance(&line_height, dda_data, ray_data);
	return (line_height);
}
