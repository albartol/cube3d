/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:05:27 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/25 16:06:53 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check_scene.h>
#include <raycast.h>

// Función que determina si hay una pared en las coordenadas (x, y)
int	detect_collision(int x, int y, char **map)
{
	if ((x <= 0 || y <= 0) || (y >= array_len(map)
			|| x >= (int)ft_strlen(map[y])) || map[y][x] == WALL)
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
		dda->side_dist.x = (dda->map_pos.x + 1 - dda->origin.x)
			* dda->delta_dist.x;
	}
	else
	{
		dda->step.x = -1;
		dda->side_dist.x = (dda->origin.x - dda->map_pos.x) * dda->delta_dist.x;
	}
	if (dda->ray_dir.y > 0)
	{
		dda->step.y = 1;
		dda->side_dist.y = (dda->map_pos.y + 1 - dda->origin.y)
			* dda->delta_dist.y;
	}
	else
	{
		dda->step.y = -1;
		dda->side_dist.y = (dda->origin.y - dda->map_pos.y) * dda->delta_dist.y;
	}
}

/*
En física se usa el nombre de "deltas" para indicar
el incremento de una variable (en este caso de la hipotenusa/pendiente de x e y)
por ello fue que 
en la primera versión que hice del raycast llamé a la estructura de coordenadas
"increment | increment->x, increment->y"
creo que queda mejor con el nombre de "deltas" <(>w <)>
 */
static void	get_deltas(t_dda *dda_info)
{
	// Calcular la razon
	if (!dda_info->ray_dir.x)
		dda_info->delta_dist.x = __DBL_MAX__;
	else
		dda_info->delta_dist.x = fabs(1 / dda_info->ray_dir.x);
	if (!dda_info->ray_dir.y)
		dda_info->delta_dist.y = __DBL_MAX__;
	else
		dda_info->delta_dist.y = fabs(1 / dda_info->ray_dir.y);
}

static double	get_distance(t_dda *dda)
{
	double	per_wall_distance;

	// Distancia perpendicular de la pared con la camara
	// Calcular por la distancia perpendicular segun el rayo de impacto x o y
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
	// Tamaño de la linea a dibujar en la ventana ahre:
	return (WIN_HEIGHT / per_wall_distance); // probar
}

double	dda(t_dda *dda_info, char **map)
{
	// DDA (Calculus)
	get_deltas(dda_info);
	get_steps_dist(dda_info);
	// DDA (Algoritmo)
	while (!detect_collision(dda_info->map_pos.x, dda_info->map_pos.y, map))
	{
		if (dda_info->side_dist.x < dda_info->side_dist.y)
		{
			dda_info->side_dist.x += dda_info->delta_dist.x;
			dda_info->map_pos.x += dda_info->step.x;
			dda_info->side = 0;
		}
		else
		{
			dda_info->side_dist.y += dda_info->delta_dist.y;
			dda_info->map_pos.y += dda_info->step.y;
			dda_info->side = 1;
		}
	}
	return (get_distance(dda_info));
}
