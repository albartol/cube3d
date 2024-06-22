/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:10:54 by albartol          #+#    #+#             */
/*   Updated: 2024/06/22 18:18:24 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_SCENE_H
# define CHECK_SCENE_H

# include <cube3d.h>

enum e_map_tiles
{
	PLAYER_NORTH = 'N',
	PLAYER_SOUTH = 'S',
	PLAYER_EAST = 'E',
	PLAYER_WEST = 'W',
	WALL = '1',
	EMPTY = '0'
};

int	check_elements(t_scene_file *info, t_scene *scene);
int	check_colors(char *floor_color, char *celling_color, t_scene *scene);
int	check_map(t_scene_file *info);

#endif