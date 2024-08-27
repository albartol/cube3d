/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:56:01 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/27 16:57:53 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

static float transform_angle(float angle)
{
	float two_pi = 2.0f * PI;
	
	if (angle > two_pi)
		return (angle - two_pi);
	if (angle < 0)
		return (angle + two_pi);
	return (angle);
}

void	rotate_LR(t_player *player, double rotation_val)
{
	t_cords cos_sin;
	t_cords save_pos;
	t_cords save_plane;

	save_plane.x = player->camera_plane.x;
	save_plane.y = player->camera_plane.y;
	save_pos.x = player->dir_vector.x;
	save_pos.y = player->dir_vector.y;
	cos_sin.x = cos(rotation_val);
	cos_sin.y = sin(rotation_val);

	//Rotate the direction vector
	player->dir_vector.x = (save_pos.x * cos_sin.x ) - (save_pos.y * cos_sin.y);
	player->dir_vector.y = (save_pos.x * cos_sin.y ) + (save_pos.y * cos_sin.x);

	//Rotate the camera plane
	player->camera_plane.x = (save_plane.x * cos_sin.x) - (save_plane.y * cos_sin.y);
	player->camera_plane.y = (save_plane.x * cos_sin.y) + (save_plane.y * cos_sin.x);

	player->angle += transform_angle(rotation_val);
}

void	rotate_UD(t_player *player, double rotation_val)
{
	player->move_y += rotation_val * PI;
	if (player->move_y > LIMIT_UP_DOWN)
		player->move_y = LIMIT_UP_DOWN;
	else if (player->move_y < -LIMIT_UP_DOWN)
		player->move_y = -LIMIT_UP_DOWN;
	printf(YELLOW"Rotando arriba / abajo %f grados \n"RESET, player->move_y);
}

void	keys_hook(t_game *data)
{
	mlx_t	*mlx;

	mlx = data->display.mlx;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(data->display.mlx);
		printf("Thanks for playing");
	}
	if (mlx_is_key_down(mlx, MLX_KEY_W) ||
		mlx_is_key_down(mlx, MLX_KEY_A) ||
		mlx_is_key_down(mlx, MLX_KEY_S) ||
		mlx_is_key_down(mlx, MLX_KEY_D))
		wasd_movement(mlx, &data->player, data->file.map);

	//Left && Right
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx, MLX_KEY_Q))
		rotate_LR(&data->player, ROTATION_SPEED_R);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT)|| mlx_is_key_down(mlx, MLX_KEY_E))
		rotate_LR(&data->player, -ROTATION_SPEED_R);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))

	//Up && Down
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		rotate_UD(&data->player, ROTATION_SPEED);
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		rotate_UD(&data->player, -ROTATION_SPEED);
}
