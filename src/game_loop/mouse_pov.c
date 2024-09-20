/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_pov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:42:12 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/20 14:48:33 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

// static void	new_mouse_pos(int32_t *x, int32_t *y)
// {
// 	int32_t vel_x;
// 	int32_t vel_y;

// 	vel_x = abs(abs(*x) - WIN_WIDTH / 2) / 10;
// 	vel_y = abs(abs(*y) - WIN_HEIGHT / 2) / 10;
// 	if (*x < WIN_WIDTH / 2)
// 		*x += vel_x;
// 	else if (*x > WIN_WIDTH / 2)
// 		*x -= vel_x;
// 	if (in_range(*x, WIN_WIDTH / 2 - 11, WIN_WIDTH / 2 + 11))
// 		*x = WIN_WIDTH / 2;
// 	if (*y < WIN_HEIGHT / 2)
// 		*y += vel_y;
// 	else if (*y > WIN_HEIGHT / 2)
// 		*y -= vel_y;
// 	if (in_range(*y, WIN_HEIGHT / 2 - 11, WIN_HEIGHT / 2 + 11))
// 		*y = WIN_HEIGHT / 2;
// }

void	mouse_pov(t_game *data)
{
	int32_t	x;
	int32_t	y;
	double	vel_x;
	double	vel_y;

	if (data->mouse)
		return ;
	mlx_get_mouse_pos(data->display.mlx, &x, &y);
	vel_x = (abs(abs(x) - WIN_WIDTH / 2) / (WIN_WIDTH / 8)) * PI / 180;
	vel_y = abs(abs(y) - WIN_HEIGHT / 2) / (WIN_HEIGHT / 12);
	if (x < WIN_WIDTH / 2)
		rotate_lr(&data->player, ROTATION_SPEED + vel_x, -1.0, &data->draw);
	else if (x > WIN_WIDTH / 2)
		rotate_lr(&data->player, ROTATION_SPEED + vel_x, 1.0, &data->draw);
	if (y < WIN_HEIGHT / 2)
		rotate_ud(&data->player, ROTATION_SPEED + vel_y, &data->draw);
	else if (y > WIN_HEIGHT / 2)
		rotate_ud(&data->player, -(ROTATION_SPEED + vel_y), &data->draw);
	mlx_set_mouse_pos(data->display.mlx, WIN_WIDTH / 2, WIN_HEIGHT / 2);
}
