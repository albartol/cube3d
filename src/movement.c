/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:14:48 by flopez-r          #+#    #+#             */
/*   Updated: 2024/07/29 17:17:17 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

float	transform_angle(float angle)
{
	if (angle > 360)
		return (angle - 360);
	if (angle < 0)
		return (angle + 360);
	return (angle);
}

float	convert_to_radian(float number)
{
	return (number * (PI / 180));
}

void	movement(void *param)
{
	t_player *player;

	player = (t_player *)param;
	if (mlx_is_key_down(player->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(player->mlx);
	//LEFT AND RIGHT
	if (mlx_is_key_down(player->mlx, MLX_KEY_RIGHT))
		player->angle = transform_angle(player->angle - ROTATION_SPEED);
	if (mlx_is_key_down(player->mlx, MLX_KEY_LEFT))
		player->angle = transform_angle(player->angle + ROTATION_SPEED);
	//WASD
	if (mlx_is_key_down(player->mlx, MLX_KEY_W))
	{
		player->x += cos(convert_to_radian(player->angle)) * SPEED;
		player->y -= sin(convert_to_radian(player->angle)) * SPEED;
	}
	if (mlx_is_key_down(player->mlx, MLX_KEY_S))
	{
		player->x -= cos(convert_to_radian(player->angle)) * SPEED;
		player->y += sin(convert_to_radian(player->angle)) * SPEED;
	}
	if (mlx_is_key_down(player->mlx, MLX_KEY_A))
	{
		player->x -= sin(convert_to_radian(player->angle)) * SPEED;
		player->y -= cos(convert_to_radian(player->angle)) * SPEED;
	}
	if (mlx_is_key_down(player->mlx, MLX_KEY_D))
	{
		player->x += sin(convert_to_radian(player->angle)) * SPEED;
		player->y += cos(convert_to_radian(player->angle)) * SPEED;
	}
	player->img->instances[0].x = player->x;
	player->img->instances[0].y = player->y;
}

// printf("Pos (%f, %f) --> %f - %f \n", player->x, player->y, (player->angle /
//  (180 * PI)), player->angle);