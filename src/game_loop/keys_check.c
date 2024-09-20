/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:56:01 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/20 12:48:30 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

/*
Returns true if its no collisions
and false si hay colisiones
 */
static int	checker(float x, float y, t_player *player, char **map)
{
	int	new_x;
	int	new_y;

	new_x = (int)x;
	new_y = (int)y;
	if (new_x <= 0 || new_y <= 0)
		return (0);
	if (new_y >= array_len(map) || new_x >= (int)ft_strlen(map[new_y]))
		return (0);
	if (map[new_y][new_x] == WALL)
		return (0);
	player->pos.x = x;
	player->pos.y = y;
	return (1);
}

static int	wasd_movement(mlx_t *mlx, t_player *player, char **map)
{
	t_cords_d	new;
	t_cords_d	const_sin;
	int			draw;

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
		draw = checker(new.x - const_sin.y, new.y - const_sin.x, player, map);
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		draw = checker(new.x + const_sin.y, new.y + const_sin.x, player, map);
	return (draw);
}

static void	arrows_pov(mlx_t *mlx, t_player *player, int *draw)
{
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_Q))
		rotate_lr(player, ROTATION_SPEED_R, -1.0, draw);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx, MLX_KEY_E))
		rotate_lr(player, ROTATION_SPEED_R, 1.0, draw);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		rotate_ud(player, (ROTATION_SPEED + 1), draw);
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		rotate_ud(player, -(ROTATION_SPEED + 1), draw);
}

void	keys_check(t_game *data)
{
	mlx_t	*mlx;

	mlx = data->display.mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(data->display.mlx);
		ft_putstr_fd("Thanks for playing\n", STDOUT_FILENO);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_M))
	{
		data->display.map->enabled = !data->display.map->enabled;
		data->draw = 1;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_C))
	{
		data->mouse = !data->mouse;
		if (data->mouse)
			mlx_set_cursor_mode(data->display.mlx, MLX_MOUSE_NORMAL);
		else
			mlx_set_cursor_mode(data->display.mlx, MLX_MOUSE_HIDDEN);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_W) || mlx_is_key_down(mlx, MLX_KEY_A)
		|| mlx_is_key_down(mlx, MLX_KEY_S) || mlx_is_key_down(mlx, MLX_KEY_D))
		data->draw += wasd_movement(mlx, &data->player, data->file.map);
	arrows_pov(mlx, &data->player, &data->draw);
}
