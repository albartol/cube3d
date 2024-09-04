/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:40:42 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/04 13:35:50 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <raycast.h>

/* 
Returns true if its no colitions
and false si hay colisiones
 */
static int	checker(float x, float y, t_player *player, char **map)
{
	int new_x;
	int new_y;

	new_x = (int)x;
	new_y = (int)y;

	// if (check_inside_walls(map, new_x, new_y))
	// 	return (0);
	if (new_x <= 0 || new_y <= 0)	
		return (0);
	if (new_y >= array_len(map) || new_x >= (int)ft_strlen(map[new_y]))	
		return (0);
	if (map[new_y][new_x] == '1')
		return (0);
	player->pos.x = x;
	player->pos.y = y;
	return (1);
}

int	wasd_movement(mlx_t *mlx, t_player *player, char **map)
{
	t_cords_d new;
	t_cords_d	const_sin;
	int		draw;

	const_sin.x = cos(player->angle) * MOVE_SPEED;
	const_sin.y = sin(player->angle) * MOVE_SPEED;
	new.x = player->pos.x;
	new.y = player->pos.y;

	draw = 0;
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		draw = checker(new.x + const_sin.x, new.y - const_sin.y, player, map);
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		draw = checker(new.x - const_sin.x, new.y + const_sin.y, player, map);
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		draw = checker(new.x + const_sin.y, new.y + const_sin.x, player, map);
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		draw = checker(new.x - const_sin.y, new.y - const_sin.x, player, map);
	return (draw);
}
