/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:10:13 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/06 18:32:15 by flopez-r         ###   ########.fr       */
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

# define ROTATION_SPEED 10

# define WIN_WIDTH	800
# define WIN_HEIGHT	600

# define RAY_WIDTH 4

# define NUM_RAY (WIN_WIDTH / RAY_WIDTH)
// # define INIT_ANGLE 90

typedef struct s_cords t_cords;

struct s_cords
{
	double	x;
	double	y;
};

double	dda(t_cords origin, t_cords dest, char **map);

#endif