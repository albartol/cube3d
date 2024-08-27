/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:40:42 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/27 16:57:00 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <raycast.h>

/* 
Returns true if its no colitions
and false si hay colisiones
 */
static void	checker(float x, float y, t_player *player, char **map)
{
	int new_x;
	int new_y;

	new_x = (int)x;
	new_y = (int)y;
	if (new_x < 0 || new_y < 0)	
		return ;
	if (map[new_y][new_x] == '1')
		return ;
	player->x = x;
	player->y = y;
}

void	wasd_movement(mlx_t *mlx, t_player *player, char **map)
{
	t_cords new;
	t_cords	const_sin;

	const_sin.x = cos(player->angle) * MOVE_SPEED;
	const_sin.y = sin(player->angle) * MOVE_SPEED;
	new.x = player->x;
	new.y = player->y;

	if (mlx_is_key_down(mlx, MLX_KEY_W))
		checker(new.x + const_sin.x, new.y - const_sin.y, player, map);
	else if (mlx_is_key_down(mlx, MLX_KEY_S))
		checker(new.x - const_sin.x, new.y + const_sin.y, player, map);
	else if (mlx_is_key_down(mlx, MLX_KEY_A))
		checker(new.x + const_sin.y, new.y + const_sin.x, player, map);
	else if (mlx_is_key_down(mlx, MLX_KEY_D))
		checker(new.x - const_sin.y, new.y - const_sin.x, player, map);
}
