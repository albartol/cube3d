/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:10:13 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/09 12:27:30 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RAYCAST_H
# define RAYCAST_H

# include <cube3d.h>

//PI DEFINITIONS
# define PI		3.14159265358979323846	/* pi */
# define PI_2	1.57079632679489661923	/* pi/2 */
# define PI_4	0.78539816339744830962	/* pi/4 */
# define _1_PI	0.31830988618379067154	/* 1/pi */

# define ROTATION_SPEED 10

# define WIN_WIDTH	800
# define WIN_HEIGHT	600

# define RAY_WIDTH 4

# define RAY_NUM (WIN_WIDTH / RAY_WIDTH)

typedef struct s_raycast t_raycast;

struct s_raycast
{
	double		camera_pos;
	double		dist_to_wall;
	t_coord_d	ray_dir;
	t_coord_d	side_dist;
	t_coord_d	delta_dist;
	t_coord_i	map_pos;
	t_coord_i	step_dir;
	int			side_hit;
	int			hit;
	int			line_height;
	int			start_pixel;
	int			end_pixel;
};

void	dda(t_raycast *info, char **map);

#endif