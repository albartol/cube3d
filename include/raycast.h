/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:10:13 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/29 15:26:17 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cube3d.h"

// PI DEFINITIONS
# define PI 3.14159265358979323846    /* pi */
# define PI_2 1.57079632679489661923  /* pi/2 */
# define PI_4 0.78539816339744830962  /* pi/4 */
# define _1_PI 0.31830988618379067154 /* 1/pi */

# define MOVE_SPEED 0.1
# define ROTATION_SPEED 3.0
# define MOVE_SPEED_R (MOVE_SPEED * PI / 180)
# define ROTATION_SPEED_R (ROTATION_SPEED * PI / 180) // Radians

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define FOV 0.66
# define LIMIT_UP_DOWN (WIN_HEIGHT / 2)

# define RAY_WIDTH 4

# define NUM_RAY (WIN_WIDTH / RAY_WIDTH)

typedef struct s_dda	t_dda;

// Raycast
double  dda(t_dda *dda_data, char **map);
void    movement(mlx_key_data_t keydata, void *param);
int	    init_ray_values(t_game *data);
void    hooks(void *param);
int	    draw_img(t_game *data, mlx_image_t *img);
void    draw_all(t_game *data);

// Hooks
void    hooks(void *param);
int		wasd_movement(mlx_t *mlx, t_player *player, char **map);
int		keys_hook(t_game *data);
void	rotate_LR(t_player *player, double rotation_val, double lr, int *draw);
void	rotate_UD(t_player *player, double rotation_val, int *draw);
int		mouse_hook(t_game *data);

#endif