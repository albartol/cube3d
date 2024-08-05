/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:28:31 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/05 14:32:59 by flopez-r         ###   ########.fr       */
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

double	get_h(double ca, double co)
{
	return (sqrt(pow(ca, 2) + pow(co / ca, 2)));
}

void	set_offset(t_cords *offset, t_cords origin)
{
	offset->x = 2 - origin.x;
	offset->y = 2 - origin.y;
}

void	move_cords(double *cord, int angle)
{
	if ((angle >= 0 && angle <= 90) || (angle >= 270 && angle <= 360))
		(*cord) += 1;
	else if ((angle > 90 && angle <= 180) || (angle >= 180 && angle < 270))
		(*cord) -= 1;
}

double	dda(t_cords origin, t_cords dest, int angle)
{
	t_cords	ray;
	t_cords	offset;
	t_cords	movement;

	// offset.x = 0.5;
	offset.y = 0.5;
	movement.x = 0;
	movement.y = 0;
	// while (42)
	// {
	// set_offset(&offset, origin);
	printf("Angulo --> %d\n", angle);
	(void)origin;
	(void)dest;
	ray.x = get_h(origin.x, 1);
	ray.y = get_h(offset.y, 1);
	printf("dx--> %f\ndy--> %f\n", ray.x, ray.y);
	if (ray.x < ray.y)
		move_cords(&movement.x, angle);
	else
		move_cords(&movement.y, angle);
	
	printf("movimiento ---> (%f, %f)\n", movement.x, movement.y);
	return (1);
}

int	raycast(t_game *data)
{
	t_cords origin;
	t_cords dest;

	set_cords(&origin, &dest, data);
	printf("origin (%f, %f)\n", origin.x, origin.y);
	printf("dest (%f, %f)\n", dest.x, dest.y);

	dda(origin, dest, data->scene.angle);
	return (EXIT_SUCCESS);
}
