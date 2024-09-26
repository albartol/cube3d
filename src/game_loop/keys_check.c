/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:56:01 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/26 14:35:45 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

/*
Returns true if its no collisions
and false si hay colisiones
 */
static void	collision_check(double x, double y, t_player *player, char **map)
{
	t_cords_i	new;
	t_cords_i	old;

	old.x = (int)player->pos.x;
	old.y = (int)player->pos.y;
	new.x = (int)x;
	new.y = (int)y;
	if (new.x <= 0 || new.y <= 0 || new.y >= array_len(map)
		|| new.x >= (int)ft_strlen(map[new.y]) || map[new.y][new.x] == WALL)
		return ;
	if (old.x < new.x && map[old.y][old.x + 1] == WALL && old.y < new.y
		&& map[old.y + 1][old.x] == WALL)
		return ;
	if (old.x < new.x && map[old.y][old.x + 1] == WALL && old.y > new.y
		&& map[old.y - 1][old.x] == WALL)
		return ;
	if (old.x > new.x && map[old.y][old.x - 1] == WALL && old.y < new.y
		&& map[old.y + 1][old.x] == WALL)
		return ;
	if (old.x > new.x && map[old.y][old.x - 1] == WALL && old.y > new.y
		&& map[old.y - 1][old.x] == WALL)
		return ;
	player->pos.x = x;
	player->pos.y = y;
}

static void	wasd_movement(mlx_t *mlx, t_player *player, char **map)
{
	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		collision_check(player->pos.x + cos(player->angle) * MOVE_SPEED,
			player->pos.y - sin(player->angle) * MOVE_SPEED, player, map);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		collision_check(player->pos.x - cos(player->angle) * MOVE_SPEED,
			player->pos.y + sin(player->angle) * MOVE_SPEED, player, map);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		collision_check(player->pos.x - sin(player->angle) * MOVE_SPEED,
			player->pos.y - cos(player->angle) * MOVE_SPEED, player, map);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		collision_check(player->pos.x + sin(player->angle) * MOVE_SPEED,
			player->pos.y + cos(player->angle) * MOVE_SPEED, player, map);
	}
}

static void	arrows_pov(mlx_t *mlx, t_player *player)
{
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_Q))
		rotate_lr(player, ROTATION_SPEED, -1.0);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx, MLX_KEY_E))
		rotate_lr(player, ROTATION_SPEED, 1.0);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		rotate_ud(player, (ROTATION_SPEED + 1));
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		rotate_ud(player, -(ROTATION_SPEED + 1));
}

void	keys_check(t_game *data)
{
	wasd_movement(data->display.mlx, &data->player, data->file.map);
	arrows_pov(data->display.mlx, &data->player);
}
