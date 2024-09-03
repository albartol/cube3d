/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:40:41 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/03 17:21:53 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <cube3d.h>
#include <raycast.h>

uint32_t give_color(t_game *game, int x, int y)
{
	char		**map;
	uint32_t	player_x;
	uint32_t	player_y;

	player_x = game->player.x;
	player_y = game->player.y;
	map = game->file.map;

	printf("WASAAAAA ---> (%d, %d)\n", x, y);
	if (x <= 0 || y <= 0 || x >= (int)ft_strlen(map[y]) - 1)
		return (OUTSIDE_COLOR);
	else if (map[y][x] == '1')
		return (WALL_COLOR);
	else if (map[y][x] == '0')
		return (FLOOR_COLOR);
	else if (in_range(x, player_x - 5, player_x + 5))
		return (PLAYER_COLOR);
	return (OUTSIDE_COLOR);
}

int draw_map(t_game *game, mlx_image_t *img)
{
	uint32_t x;
	uint32_t y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			mlx_put_pixel(img, x, y, give_color(game, (x / P_SIZE) - 1, (y / P_SIZE) - 1));
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->display.mlx, img, 0, 0);
	return (EXIT_SUCCESS);
}
