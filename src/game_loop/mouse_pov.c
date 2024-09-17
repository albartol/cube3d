/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_pov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:42:12 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/17 19:38:49 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

static void	new_mouse_pos(int32_t *x, int32_t *y)
{
	if (*x < WIN_WIDTH / 2)
		*x += 10;
	else if (*x > WIN_WIDTH / 2)
		*x -= 10;
	if (in_range(*x, WIN_WIDTH / 2 - 11, WIN_WIDTH / 2 + 11))
		*x = WIN_WIDTH / 2;
	if (*y < WIN_HEIGHT / 2)
		*y += 10;
	else if (*y > WIN_HEIGHT / 2)
		*y -= 10;
	if (in_range(*y, WIN_HEIGHT / 2 - 11, WIN_HEIGHT / 2 + 11))
		*y = WIN_HEIGHT / 2;
}

void	mouse_pov(t_game *data)
{
	int32_t	x;
	int32_t	y;

	mlx_get_mouse_pos(data->display.mlx, &x, &y);
	if (x < WIN_WIDTH / 2)
		rotate_LR(&data->player, ROTATION_SPEED_R - 0.01, -1.0, &data->draw);
	else if (x > WIN_WIDTH / 2)
		rotate_LR(&data->player, ROTATION_SPEED_R - 0.01, 1.0, &data->draw);
	if (y < WIN_HEIGHT / 2)
		rotate_UD(&data->player, (ROTATION_SPEED + 1), &data->draw);
	else if (y > WIN_HEIGHT / 2)
		rotate_UD(&data->player, -(ROTATION_SPEED + 1), &data->draw);
	new_mouse_pos(&x, &y);
	mlx_set_mouse_pos(data->display.mlx, x, y);
	// mlx_set_mouse_pos(data->display.mlx, WIN_WIDTH / 2, WIN_HEIGHT / 2);
}
