/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:05:27 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/06 18:30:38 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>
#include <check_scene.h>


// Función que determina si hay una pared en las coordenadas (x, y)
int detect_colition(t_cords cords, char **map) {
	
	int	width;
	int height;

	width = ft_strlen(map[(int)cords.y]) - 1;
	height = array_len(map) - 1;
	
	if ((cords.x < 0 || cords.y < 0) || (cords.x >= width || cords.y >= height) ||
		(map[(int)cords.y][(int)cords.x] == WALL))
		return (1);
	return (0);
}

/* Obtener y calcular los pasos y la distancia inicial de las
posiciones x e y */
void	get_steps_dist(t_cords *origin, t_cords *dest, t_cords *steps, t_cords *increment, t_cords *side_dist)
{
	if (dest->x <= 0)	// Left
	{
		steps->x = -1;
		side_dist->x = (origin->x - (int)origin->x) * increment->x;
	}
	else				// Right
	{
		steps->x = 1; 
		side_dist->x = (((int)origin->x + 1) - origin->x) * increment->x;
	}
	if (dest->y <= 0)	// Down
	{
		steps->y = -1;
		side_dist->y = (origin->y - (int)origin->y) * increment->y;
	}
	else				// Up
	{
		steps->y = 1;
		side_dist->y = (((int)origin->y + 1) - (int)origin->y) * increment->y;
	}
}


double	dda(t_cords origin, t_cords dest, char **map)
{
	t_cords	increment;
	t_cords	steps;
	t_cords	side_dist;

	//Incremento en x e y (deltas)
	increment.x = fabs(1 / dest.x);
	increment.y = fabs(1 / dest.y);
	
	//Calcular los pasos
	get_steps_dist(&origin, &dest, &steps, &increment, &side_dist);

	//DDA Loop
	char choque = 'n';
	while (42)
	{
		if (side_dist.x < side_dist.y)
		{
			side_dist.x += increment.x;
			origin.x += steps.x;
			choque = 'x';
		}
		else
		{
			side_dist.y += increment.y;
			origin.y += steps.y;
			choque = 'y';
		}
		if (detect_colition(origin, map))
			break;
	}
	printf("Colition found in (%f, %f) hitted by %c\n", origin.x, origin.y, choque);
	return (42);
}
