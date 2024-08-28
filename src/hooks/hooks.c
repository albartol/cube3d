/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:11:53 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/28 18:46:35 by flopez-r         ###   ########.fr       */
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
		rotate_LR(&data->player, ROTATION_SPEED_R, 1.0, &draw)
	mlx_set_mouse_pos(data->display.mlx, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	printf("Posicion del mouse en (%d, %d)\n", x, y);
	return (0);
}

void	hooks(void *param)
{
	t_game  *data;

	data = (t_game *)param;
	if (keys_hook(data))
		draw_all(data);
	if (mouse_hook(data))
		draw_all(data);
}
