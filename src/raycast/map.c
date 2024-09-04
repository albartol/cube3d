/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:40:41 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/04 18:33:31 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <cube3d.h>
#include <raycast.h>

static void	put_cell(mlx_image_t *img, uint32_t color, t_cords_i coords)
{
	t_cords_i			pixel;
	t_cords_i			cell_size;

	pixel.x = coords.x * CELL_SIZE;
	pixel.y = coords.y * CELL_SIZE;
	cell_size.y = 0;
	while (cell_size.y < CELL_SIZE)
	{
		cell_size.x = 0;
		while (cell_size.x < CELL_SIZE)
		{
			if (pixel.x < MAP_SIDE && pixel.y < MAP_SIDE)
				mlx_put_pixel(img, pixel.x++, pixel.y, color);
			cell_size.x++;
		}
		pixel.y++;
		pixel.x -= CELL_SIZE;
		cell_size.y++;
	}
}

static uint32_t	get_cell_color(t_cords_i map_pos, char **map)
{
	if (map_pos.x <= 0 || map_pos.y <= 0)
		return (OUTSIDE_COLOR);
	else if (map_pos.y >= array_len(map)
		|| map_pos.x >= (int)ft_strlen(map[map_pos.y]))
		return (OUTSIDE_COLOR);
	else if (map[map_pos.y][map_pos.x] == SPACE)
		return (OUTSIDE_COLOR);
	else if (map[map_pos.y][map_pos.x] == WALL)
		return (WALL_COLOR);
	// else if (map[map_pos.y][map_pos.x] == EMPTY)
	return (FLOOR_COLOR);
}


void	draw_map(t_game *game)
{
	t_cords_i		origin;
	t_cords_i		map_pos;
	t_cords_i		coords;
	uint32_t		color;

	origin.x = game->player.pos.x;
	origin.y = game->player.pos.y;

	map_pos.x = origin.x - 4;
	map_pos.y = origin.y - 4;
	

	//Map movement
	coords.y = 0;
	while (coords.y < CELLS_NUM)
	{
		coords.x = 0;
		while (coords.x < CELLS_NUM)
		{
			color = get_cell_color(map_pos, game->file.map);
			put_cell(game->display.map, color, coords);
			coords.x++;
			map_pos.x++;
		}
		coords.y++;
		map_pos.y++;
	}
	put_cell(game->display.map, PLAYER_COLOR, origin);
}
