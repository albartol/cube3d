/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:10:13 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/20 14:59:13 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "cube3d.h"
# include <check_scene.h>

// PI DEFINITIONS
# define PI 3.14159265358979323846    /* pi */
# define PI_2 1.57079632679489661923  /* pi/2 */
# define PI_4 0.78539816339744830962  /* pi/4 */
# define _1_PI 0.31830988618379067154 /* 1/pi */

// Speed and sensibility
# define MOVE_SPEED 0.1
# define ROTATION_SPEED 1.5

// Screen Size
# define WIN_WIDTH 1200
# define WIN_HEIGHT 900

// Map Size
# define CELLS_NUM 21
# define MAP_SIDE 5

// Map colors
# define WALL_COLOR 0xa8dadcef
# define PLAYER_COLOR 0xe63946ff
# define FLOOR_COLOR 0xf1faeeef
# define OUTSIDE_COLOR 0x1d3557af

# define FOV 0.66

# define RAY_WIDTH 4

typedef struct s_dda	t_dda;

// Raycast
double	dda(t_dda *dda_data, char **map);
int		init_ray_values(t_game *data);
int		draw_img(t_game *data, mlx_image_t *img);
int		draw_all(t_game *data);

// Hooks
void	game_loop(void *param);
void	keys_check(t_game *data);
void	mouse_pov(t_game *data);
void	rotate_lr(t_player *player, double rotation_val, double lr, int *draw);
void	rotate_ud(t_player *player, double rotation_val, int *draw);

// Map
void	draw_map(t_game *game);

#endif