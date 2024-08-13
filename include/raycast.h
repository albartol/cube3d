/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:10:13 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/13 14:01:16 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RAYCAST_H
# define RAYCAST_H

# include "cube3d.h"

//PI DEFINITIONS
# define PI		3.14159265358979323846	/* pi */
# define PI_2	1.57079632679489661923	/* pi/2 */
# define PI_4	0.78539816339744830962	/* pi/4 */
# define _1_PI	0.31830988618379067154	/* 1/pi */

# define MOVE_SPEED 0.3
# define ROTATION_SPEED 0.3

# define WIN_WIDTH	800
# define WIN_HEIGHT	600

# define RAY_WIDTH 4

# define NUM_RAY (WIN_WIDTH / RAY_WIDTH)
// # define INIT_ANGLE 90

// typedef struct s_cords t_cords;
// typedef struct s_raycast t_raycast;
typedef struct s_dda t_dda;

// struct s_cords
// {
// 	double	x;
// 	double	y;
// };

// struct s_raycast
// {
// 	t_cords origin; 		// Initial position
// 	t_cords	v_dir;			// Initial direction vector
// 	t_cords	camera_plane;	// Plano de camara del jugador --> the FOV is 2 * atan(0.66/1.0)=66°
// 	t_cords ray_dir;		// La dirección del rayo
// 	double	camera_x;
// };

struct s_dda
{
	t_cords	delta_dist;		//Razon para calcular la hipotenusa
	t_cords	side_dist;		//Distancia inicial de la hipotenusa de x e y
	t_cords	step;			//Pasos a tomar en x e y
	int		side;			//0 for X and 1 for Y
	int		map_pos_x;
	int		map_pos_y;
};

// double	dda(t_cords origin, t_cords dest, char **map);
double	dda(t_raycast *ray_data, t_dda *dda_data, char **map);

#endif