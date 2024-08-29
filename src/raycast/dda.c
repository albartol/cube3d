/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:05:27 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/29 16:22:28 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>
#include <check_scene.h>

// Función que determina si hay una pared en las coordenadas (x, y)
int detect_colition(int x, int y, char **map)
{
	
	int	width;
	int height;

	width = ft_strlen(map[y]);
	height = array_len((const char **)map);

	if ((x < 0 || y < 0) || (x >= width || y >= height) || (map[y][x] == WALL))
		return (1);
	return (0);
}


/*Funcion que:
- Calcula que dirección tomarán los pasos
- Calcula la longitud de la hipotenusa en x e y inicial
 */
static void	get_steps_dist(t_dda *dda)
{
	if (dda->ray_dir.x > 0)
	{
		dda->step.x = 1;
		dda->side_dist.x = (dda->map_pos_x + 1 - dda->origin.x) * dda->delta_dist.x;
	}
	else
	{
		dda->step.x = -1;
		dda->side_dist.x = (dda->origin.x - dda->map_pos_x) *  dda->delta_dist.x;
	}
	if (dda->ray_dir.y > 0)
	{
		dda->step.y = 1;
		dda->side_dist.y = (dda->map_pos_y + 1 - dda->origin.y) * dda->delta_dist.y;
	}
	else
	{
		dda->step.y = -1;
		dda->side_dist.y = (dda->origin.y - dda->map_pos_y) *  dda->delta_dist.y;
	}
}

/* 
En física se usa el nombre de "deltas" para indicar
el incremento de una variable (en este caso de la hipotenusa/pendiente de x e y)
por ello fue que en la primera versión que hice del raycast llamé a la estructura de coordenadas
"increment | increment->x, increment->y"
creo que queda mejor con el nombre de "deltas" <(>w <)>
 */
static void	get_deltas(t_dda *dda_info)
{
	//Calcular la razon
	if (!dda_info->ray_dir.x)
		dda_info->delta_dist.x = __DBL_MAX__;
	else
		dda_info->delta_dist.x = fabs(1 / dda_info->ray_dir.x);
	
	if (!dda_info->ray_dir.y)
		dda_info->delta_dist.y = __DBL_MAX__;
	else
		dda_info->delta_dist.y = fabs(1 / dda_info->ray_dir.y);
}

static void	get_distance(double *line, t_dda *dda)
{
	//Distancia perpendicular de la pared con la camara
	double	per_wall_distance;

	//Calcular por la distancia perpendicular segun el rayo de impacto x o y
	if (dda->side == 0)
	{
		per_wall_distance = (dda->side_dist.x - dda->delta_dist.x);
		dda->x_hit = per_wall_distance * dda->ray_dir.y + dda->origin.y;
	}
	else
	{
		per_wall_distance = (dda->side_dist.y - dda->delta_dist.y);
		dda->x_hit = per_wall_distance * dda->ray_dir.x + dda->origin.x;
	}
	dda->x_hit -= floor(dda->x_hit);
	//Tamaño de la linea a dibujar en la ventana ahre:
	*line = WIN_HEIGHT / per_wall_distance;
}

double	dda(t_dda *dda_info, char **map)
{
	double	line_height;

	//DDA (Calculus)
	get_deltas(dda_info);
	get_steps_dist(dda_info);

	//DDA (Algoritmo)
	while (!detect_colition(dda_info->map_pos_x, dda_info->map_pos_y, map))
	{
		if (dda_info->side_dist.x < dda_info->side_dist.y)
		{
			dda_info->side_dist.x += dda_info->delta_dist.x;
			dda_info->map_pos_x += dda_info->step.x;
			dda_info->side = 0;
		}
		else
		{
			dda_info->side_dist.y += dda_info->delta_dist.y;
			dda_info->map_pos_y += dda_info->step.y;
			dda_info->side = 1;
		}
	}
	get_distance(&line_height, dda_info);
	return (line_height);
}
