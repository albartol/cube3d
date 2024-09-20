/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:40:41 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/20 14:57:35 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <cube3d.h>
#include <raycast.h>

static void	put_cell(mlx_image_t *img, uint32_t color, t_cords_i coords)
{
	t_cords_i	pixel;
	t_cords_i	cells;
	int			map_size;
	int			cell_size;

	map_size = WIN_HEIGHT / MAP_SIDE;
	cell_size = map_size / CELLS_NUM;
	pixel.x = coords.x * cell_size;
	pixel.y = coords.y * cell_size;
	cells.y = 0;
	while (cells.y < cell_size)
	{
		cells.x = 0;
		while (cells.x < cell_size)
		{
			if (pixel.x < map_size && pixel.y < map_size)
				mlx_put_pixel(img, pixel.x++, pixel.y, color);
			cells.x++;
		}
		pixel.y++;
		pixel.x -= cell_size;
		cells.y++;
	}
}

static uint32_t	get_cell_color(t_cords_i map_pos, char **map, t_cords_i origin)
{
	map_pos.x += origin.x - (CELLS_NUM / 2);
	map_pos.y += origin.y - (CELLS_NUM / 2);
	if (map_pos.x < 0 || map_pos.y < 0)
		return (OUTSIDE_COLOR);
	else if (map_pos.y >= array_len(map)
		|| map_pos.x >= (int)ft_strlen(map[map_pos.y]))
		return (OUTSIDE_COLOR);
	else if (map[map_pos.y][map_pos.x] == SPACE)
		return (OUTSIDE_COLOR);
	else if (map[map_pos.y][map_pos.x] == WALL)
		return (WALL_COLOR);
	return (FLOOR_COLOR);
}

void	draw_map(t_game *game)
{
	t_cords_i	origin;
	t_cords_i	map_pos;
	uint32_t	color;

	origin.x = game->player.pos.x;
	origin.y = game->player.pos.y;
	map_pos.y = CELLS_NUM;
	while (map_pos.y >= 0)
	{
		map_pos.x = CELLS_NUM;
		while (map_pos.x >= 0)
		{
			color = get_cell_color(map_pos, game->file.map, origin);
			put_cell(game->display.map, color, map_pos);
			map_pos.x--;
		}
		map_pos.y--;
	}
	origin.x = CELLS_NUM / 2;
	origin.y = CELLS_NUM / 2;
	put_cell(game->display.map, PLAYER_COLOR, origin);
}
