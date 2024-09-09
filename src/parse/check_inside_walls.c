/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inside_walls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:25:42 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/09 13:20:18 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check_scene.h>

/* 
Returns True if it founds a collision
and false if they dont
 */
int	check_inside_walls(char **map, size_t x, size_t y)
{
	if (y == 0 || ft_strlen(map[y - 1]) <= x || map[y - 1][x] == SPACE) // UP
		return (EXIT_FAILURE);
	if (!map[y + 1] || ft_strlen(map[y + 1]) <= x || map[y + 1][x] == SPACE) // DOWN
		return (EXIT_FAILURE);
	if (x == 0 || map[y][x - 1] == SPACE) // LEFT
		return (EXIT_FAILURE);
	if (!map[y][x + 1] || map[y][x + 1] == SPACE) // DOWN
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
