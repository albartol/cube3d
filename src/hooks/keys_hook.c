/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:56:01 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/04 11:38:12 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

int	keys_hook(t_game *data)
{
	mlx_t	*mlx;
	int		draw;

	mlx = data->display.mlx;

	draw = 0;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(data->display.mlx);
		printf("Thanks for playing");
	}
	if (mlx_is_key_down(mlx, MLX_KEY_W) ||
		mlx_is_key_down(mlx, MLX_KEY_A) ||
		mlx_is_key_down(mlx, MLX_KEY_S) ||
		mlx_is_key_down(mlx, MLX_KEY_D))
		draw = wasd_movement(mlx, &data->player, data->file.map);

	//Left && Right
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_Q))
		rotate_LR(&data->player, 1.0, &draw);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT)|| mlx_is_key_down(mlx, MLX_KEY_E))
		rotate_LR(&data->player, -1.0, &draw);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))

	//Up && Down
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		rotate_UD(&data->player, ROTATION_SPEED, &draw);
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		rotate_UD(&data->player, -ROTATION_SPEED, &draw);
	return (draw);
}
