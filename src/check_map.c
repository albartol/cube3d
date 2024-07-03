/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:31:15 by albartol          #+#    #+#             */
/*   Updated: 2024/07/03 18:19:53 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check_scene.h>
#include <cube3d.h>



size_t len_to_char(char *str, char *chars)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && !ft_strchr(chars, str[i]))
		i++;
	return (i);
}

int check_up_down(char **map, size_t x, size_t y)
{
	size_t	up_len;
	size_t	actual_len;
	size_t	down_len;

	actual_len = len_to_char(map[y], "NSWE");
	if (y > 0)
	{
		up_len = ft_strlen(map[y - 1]);
		if (up_len < actual_len)
			return (EXIT_FAILURE);
	}
	if (map[y + 1])
	{
		down_len = ft_strlen(map[y + 1]);
		if (actual_len > down_len)
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	check_inside_walls(char **map, size_t x, size_t y)
{

	if (ft_strchr("NSWE", map[y][x]))
	{
		if (check_up_down(map, x, y)) // If you answer: Why did my parner do this??? try discoment the below function (before parser)  and run test.cub
			return (EXIT_FAILURE);
	}
	if (y == 0 || map[y - 1][x] == SPACE) // UP
			return (EXIT_FAILURE);
	if (!map[y + 1] || map[y + 1][x] == SPACE) // DOWN
		return (EXIT_FAILURE);
	if (x == 0 || map[y][x - 1] == SPACE) // LEFT
		return (EXIT_FAILURE);
	if (!map[y][x + 1] || map[y][x + 1] == SPACE) // RIGHT
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

// static int	check_inside_walls(char **map, size_t x, size_t y)
// {
// 	if (y == 0 || map[y - 1][x] == SPACE) // UP
// 		return (EXIT_FAILURE);
// 	if (!map[y + 1] || map[y + 1][x] == SPACE) // DOWN
// 		return (EXIT_FAILURE);
// 	if (x == 0 || map[y][x - 1] == SPACE) // LEFT
// 		return (EXIT_FAILURE);
// 	if (!map[y][x + 1] || map[y][x + 1] == SPACE) // DOWN
// 		return (EXIT_FAILURE);
// 	return (EXIT_SUCCESS);
// }

static int	check_value(char **map, size_t x, size_t y)
{
	static int	cant_player;

	if (!ft_strchr("NSEW10 ", map[y][x]))
		return (exit_msg("Invalid character in map\n", EXIT_FAILURE));
	else if (ft_strchr("NSEW", map[y][x]))
	{
		if (cant_player > 0)
			return (exit_msg("Too many players\n", EXIT_FAILURE));
		cant_player++;
		if (check_inside_walls(map, x, y))
			return (exit_msg("Player position not valid\n", EXIT_FAILURE));
	}
	else if (map[y][x] == EMPTY)
	{
		if (check_inside_walls(map, x, y))
			return (exit_msg("The map must be inside walls\n", EXIT_FAILURE));
	}
	if (!map[y][x + 1] && !map[y + 1] && !cant_player)
		return (exit_msg("Missing player\n", EXIT_FAILURE));
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
		if (!map[y][x])
			return (exit_msg("Invalid map\n", EXIT_FAILURE));
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
