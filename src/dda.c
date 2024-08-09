/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:05:27 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/09 19:38:39 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>
#include <check_scene.h>

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

void	get_distance(double *line, t_dda *dda_data)
{
	double	per_wall_distance; //Distancia perpendicular de la pared con la camara

	//Calcular por la distancia perpendicular segun el rayo de impacto x o y
	if (dda_data->side == 0)
		per_wall_distance = (dda_data->side_dist.x - dda_data->delta_dist.x);
	else 
		per_wall_distance = (dda_data->side_dist.y - dda_data->delta_dist.y);
	
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
			printf("Me moví en x %f pasos, pos actual (%d, %d)\n", dda_data->step.x, dda_data->map_pos_x, dda_data->map_pos_y);
		}
		else
		{
			dda_data->side_dist.y += dda_data->delta_dist.y;
			dda_data->map_pos_y += dda_data->step.y;
			dda_data->side = 1;
			printf("Me moví en y %f pasos, pos actual (%d, %d)\n", dda_data->step.y, dda_data->map_pos_x, dda_data->map_pos_y);
		}
	}

	get_distance(&line_height, dda_data);
	return (line_height);
}
// double	dda(t_cords origin, t_cords dest, char **map)
// {
// 	t_cords	increment;
// 	t_cords	steps;
// 	t_cords	side_dist;
// 	t_cords movements;


// 	movements.x = origin.x;
// 	movements.y = origin.y;
// 	//Incremento en x e y (deltas)
// 	if (!dest.x)
// 		increment.x = __DBL_MAX__;
// 	else
// 		increment.x = fabs(1 / dest.x);
// 	if (!dest.y)
// 		increment.y = __DBL_MAX__;
// 	else
// 		increment.y = fabs(1 / dest.y);

// 	printf("Incremento en x --> %f\n", increment.x);
// 	printf("Incremento en y --> %f\n", increment.y);

// 	//Calcular los pasos
// 	get_steps_dist(&origin, &dest, &steps, &increment, &side_dist);

// 	//DDA Loop
// 	char choque = 'n';

// 	printf("size en x --> %f\n", side_dist.x);
// 	printf("size en y --> %f\n", side_dist.y);
	
// 	printf("\n\n---------INICIO DDA----------\n\n");
// 	printf("Origin --> (%f, %f)\n", origin.x, origin.y);
// 	while (!detect_colition(movements, map))
// 	{
// 		if (side_dist.x < side_dist.y)
// 		{
// 			side_dist.x += increment.x;
// 			movements.x += steps.x;
// 			choque = 'x';
// 			printf("Me he movido en x %f pasos\n", steps.x);
// 		}
// 		else
// 		{
// 			side_dist.y += increment.y;
// 			movements.y += steps.y;
// 			choque = 'y';
// 			printf("Me he movido en y %f pasos\n", steps.y);
// 		}
// 	}
// 	print_map(map);
// 	printf("Colition found in (%f, %f) hitted by %c\n", movements.x, movements.y, choque);
// 	return (get_distance(origin, movements));
// }


// // Función que determina si hay una pared en las coordenadas (x, y)
// static int detect_colition(t_cords cords, char **map) {
	
// 	int	width;
// 	int height;

// 	width = ft_strlen(map[(int)cords.y])/*  - 1 */;
// 	height = array_len((const char **)map)/*  - 1 */;

// 	if ((cords.x < 0 || cords.y < 0) || (cords.x >= width || cords.y >= height) ||
// 		(map[(int)cords.y][(int)cords.x] == WALL))
// 		return (1);
// 	return (0);
// }

// void	arreglo(t_cords *origin, t_cords * dest, t_cords *steps, t_cords *side_dist)
// {
// 	if (dest->x == origin->x /* || dest->x == 0 */)
// 	{
// 		steps->x = 0;
// 		side_dist->x = __DBL_MAX__;
// 	}
// 	if (dest->y == origin->y /* || dest->y == 0 */)
// 	{
// 		steps->y = 0;
// 		side_dist->y = __DBL_MAX__;
// 	}
// }

// /* Obtener y calcular los pasos y la distancia inicial de las
// posiciones x e y */
// void	get_steps_dist(t_cords *origin, t_cords *dest, t_cords *steps, t_cords *increment, t_cords *side_dist)
// {
// 	if (dest->x < origin->x /* < 0 */)	// Left
// 	{
// 		steps->x = -1;
// 		side_dist->x = (origin->x - (int)origin->x) * increment->x;
// 	}
// 	else				// Right
// 	{
// 		steps->x = 1; 
// 		side_dist->x = ((int)origin->x + 1 - origin->x) * increment->x;
// 	}
// 	if (dest->y < origin->y /* < 0 */)	// Down
// 	{
// 		steps->y = -1;
// 		side_dist->y = (origin->y - (int)origin->y) * increment->y;
// 	}
// 	else				// Up
// 	{
// 		steps->y = 1;
// 		side_dist->y = ((int)origin->y + 1 - (int)origin->y) * increment->y;
// 	}
// 	// printf("\n\nprueba size_dist --> %f\n\n", side_dist->y);
// 	arreglo(origin, dest, steps, side_dist);
// }

// /*	La fórmula más común para calcular la distancia 
// 	entre dos puntos es la fórmula de distancia euclidiana.
// 	y es válida para puntos en un plano euclidiano
// 	d = √((x2 - x1)² + (y2 - y1)²)
// */
// double	get_distance(t_cords P1, t_cords P2)
// {
// 	double	distance;

// 	distance = sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2));
// 	return (distance);
// }
