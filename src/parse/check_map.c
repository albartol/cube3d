/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:31:15 by albartol          #+#    #+#             */
/*   Updated: 2024/09/20 12:53:37 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check_scene.h>

void	get_view(t_game *data, char character)
{
	if (character == PLAYER_EAST)
		data->player.angle = 0;
	else if (character == PLAYER_NORTH)
		data->player.angle = 90;
	else if (character == PLAYER_WEST)
		data->player.angle = 180;
	else if (character == PLAYER_SOUTH)
		data->player.angle = 270;
}

static int	check_value(char **map, size_t x, size_t y, t_game *data)
{
	static int	cant_player;

	if (!ft_strchr("NSEW10 ", map[y][x]))
		return (exit_msg("Invalid character in map\n", EXIT_FAILURE));
	else if (ft_strchr("NSEW", map[y][x]))
	{
		if (cant_player > 0)
			return (exit_msg("Too many players\n", EXIT_FAILURE));
		data->player.pos.x = x + 0.5;
		data->player.pos.y = y + 0.5;
		get_view(data, map[y][x]);
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

int	check_map(char **map, t_game *data)
{
	size_t	y;
	size_t	x;
	size_t	max_x;

	y = 0;
	max_x = 0;
	while (map[y])
	{
		x = 0;
		if (!map[y][x])
			return (exit_msg("Invalid map\n", EXIT_FAILURE));
		while (map[y][x])
		{
			if (x > max_x)
				max_x = x;
			if (check_value(map, x, y, data))
				return (EXIT_FAILURE);
			x++;
		}
		y++;
	}
	data->scene.map_height = y;
	data->scene.map_width = max_x + 1;
	return (EXIT_SUCCESS);
}
