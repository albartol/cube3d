/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:31:15 by albartol          #+#    #+#             */
/*   Updated: 2024/07/02 13:05:41 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>
#include <check_scene.h>

int exit_msg(char *message, int exit_code)
{
	print_error(message);
	return (exit_code);
}


int check_inside_walls(char **map, size_t x, size_t y)
{
	if (y == 0 || map[y - 1][x] == SPACE) //UP
		return (EXIT_FAILURE);
	if (!map[y + 1] || map[y + 1][x] == SPACE) // DOWN
		return (EXIT_FAILURE);
	if (x == 0 || map[y][x - 1] == SPACE) // LEFT
		return (EXIT_FAILURE);
	if (!map[y][x + 1] || map[y][x + 1] == SPACE) // DOWN
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


int check_value(char **map, size_t x, size_t y)
{
	static	int	cant_player;

	if (!ft_strchr("NSEW10 ", map[y][x]))
		return (exit_msg("Not valid character\n", EXIT_FAILURE));
	else if (ft_strchr("NSEW", map[y][x]))
	{
		if (cant_player == 0)
			cant_player++;
		else
			return (exit_msg("There should only be one player\n", EXIT_FAILURE));
	}
	if (map[y][x] == EMPTY)
	{
		if (check_inside_walls(map, x, y))
			return (exit_msg("The map must be inside walls\n", EXIT_FAILURE));
	}
	if (!map[y][x + 1] && !map[y + 1] && !cant_player)
		return (exit_msg("There should be a player inside the map\n", EXIT_FAILURE));
	return (EXIT_SUCCESS);
}

int	check_map(char **map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (check_value(map, x, y))
				return (EXIT_FAILURE);
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}
