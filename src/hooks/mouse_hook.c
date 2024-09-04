/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:42:12 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/04 13:32:32 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

int	mouse_hook(t_game *data)
{
	int32_t	x;
	int32_t	y;
	int		draw;

	mlx_get_mouse_pos(data->display.mlx, &x, &y);
	if (x < WIN_WIDTH / 2)
		rotate_LR(&data->player, 1.0, &draw);
	if (x > WIN_WIDTH / 2)
		rotate_LR(&data->player, -1.0, &draw);
	if (y < WIN_HEIGHT / 2)
		rotate_UD(&data->player, ROTATION_SPEED, &draw);
	if (y > WIN_HEIGHT / 2)
		rotate_UD(&data->player, -ROTATION_SPEED, &draw);
	mlx_set_mouse_pos(data->display.mlx, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (draw);
}
