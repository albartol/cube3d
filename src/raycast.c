/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:28:31 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/07 17:37:52 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

void	set_cords(t_cords *origin, t_cords *dest, t_game *data)
{
	int	width_size;
	int	height_size;

	origin->x = (data->scene.player_x) + 0.5;
	origin->y = (data->scene.player_y) + 0.5;
	width_size = ft_strlen(data->file.map[data->scene.player_y]);
	height_size = array_len((const char **)data->file.map);

	dest->x = 0.1;
	dest->y = 0.1;
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


	//Test
	double distance;

	// while (init_angle < data->scene.angle)
	// {
		distance = dda(origin, dest, data->file.map);
		printf("Distacia --> %f\n", distance);
	// 	init_angle++;
	// }
	return (EXIT_SUCCESS);
}
