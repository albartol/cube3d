/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:40:41 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/06 12:39:43 by flopez-r         ###   ########.fr       */
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

static uint32_t	get_cell_color(t_cords_i map_pos, char **map, t_cords_i	origin)
{
	// (void)origin;
	map_pos.x += origin.x - 3;
	map_pos.y += origin.y - 3;
	if (map_pos.x < 0 || map_pos.y < 0)
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
	uint32_t		color;

	origin.x = game->player.pos.x;
	origin.y = game->player.pos.y;

	//Map movement
	map_pos.y = CELLS_NUM;
	printf(";PLayer position --> (%d, %d)", origin.x, origin.y);
	printf("===================\n");
	while (map_pos.y >= 0)
	{
		map_pos.x = CELLS_NUM;
		printf(";Row #%d\n", map_pos.y);
		while (map_pos.x >= 0)
		{
			color = get_cell_color(map_pos, game->file.map, origin);
			printf("Celd in (%d, %d) is %x\n", map_pos.x, map_pos.y, color);
			put_cell(game->display.map, color, map_pos);
			map_pos.x--;
		}
		map_pos.y--;
	}
	printf("===================\n");
	// origin.x ;
	// origin.y ;
	// put_cell(game->display.map, PLAYER_COLOR, origin);
}

// void	draw_map(t_game *game)
// {
// 	t_cords_i		origin;
// 	t_cords_i		map_pos;
// 	uint32_t		color;

// 	origin.x = game->player.pos.x;
// 	origin.y = game->player.pos.y;

// 	//Map movement
// 	map_pos.y = 0;
// 	printf(";PLayer position --> (%d, %d)", origin.x, origin.y);
// 	printf("===================\n");
// 	while (map_pos.y < CELLS_NUM)
// 	{
// 		map_pos.x = 0;
// 		printf(";Row #%d\n", map_pos.y);
// 		while (map_pos.x < CELLS_NUM)
// 		{
// 			color = get_cell_color(map_pos, game->file.map, origin);
// 			printf("Celd in (%d, %d) is %x\n", map_pos.x, map_pos.y, color);
// 			put_cell(game->display.map, color, map_pos);
// 			map_pos.x++;
// 		}
// 		map_pos.y++;
// 	}
// 	printf("===================\n");
// 	// origin.x = CELLS_NUM / 2;
// 	// origin.y = CELLS_NUM / 2;
// 	put_cell(game->display.map, PLAYER_COLOR, origin);
// }
