/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:28:31 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/05 12:17:07 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

double	dda(t_cords origin, t_cords dest)
{
	(void)origin;
	(void)dest;
	return (1);
}

void	set_cords(t_cords *origin, t_cords *dest, t_game *data)
{
	int	width_size;
	int	height_size;

	origin->x = (data->scene.player_x) + 0.5;
	origin->y = (data->scene.player_y) + 0.5;
	width_size = ft_strlen(data->file.map[data->scene.player_y]);
	height_size = array_len((const char **)data->file.map);

	dest->x = 0;
	dest->y = 0;
	if (data->scene.angle == 0)
	{
		dest->y = origin->y;
		dest->x = width_size - data->scene.player_x;
	}
	if (data->scene.angle == 90)
		dest->x = origin->x;
	if (data->scene.angle == 180)
		dest->y = origin->y;
	else if (data->scene.angle == 270)
	{
		dest->x = origin->x;
		dest->y = height_size - 1;
	}
}


int	raycast(t_game *data)
{
	t_cords origin;
	t_cords dest;

	set_cords(&origin, &dest, data);
	printf("origin (%f, %f)\n", origin.x, origin.y);
	printf("dest (%f, %f)\n", dest.x, dest.y);

	dda(origin, dest);
	return (EXIT_SUCCESS);
}
