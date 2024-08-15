/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:23:29 by flopez-r          #+#    #+#             */
/*   Updated: 2024/07/13 19:21:19 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

int	put_map(char **map, t_display *display, mlx_image_t	*wall)
{
	int			x;
	int			y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
			{
				if (mlx_image_to_window(display->mlx, wall, x * P_SIZE, y * P_SIZE) == -1)
					return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
			}
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}
