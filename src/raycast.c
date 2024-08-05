/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:28:31 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/05 16:59:20 by flopez-r         ###   ########.fr       */
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

void	set_offset(t_cords *offset, t_cords origin, t_cords dest)
{
	(void)dest;
	offset->x = origin.x - 1;
	offset->y = origin.y - 1;
}

void	move_cords(double *cord, int angle)
{
	if ((angle >= 0 && angle < 90) || (angle >= 270 && angle <= 360))
		(*cord) += 1;
	else if ((angle >= 90 && angle <= 180) || (angle >= 180 && angle < 270))
		(*cord) -= 1;
}

double	dda(t_cords origin, t_cords dest, int angle, char **map)
{
	double	distance;
	t_cords	offset;
	t_cords	movement;

	(void)angle;
	(void)map;
	distance = 0;
	set_offset(&offset, origin, dest);
	printf("offset x--> %f -- offset y --> %f\n", offset.x , offset.y);
	
	movement.x = get_h(offset.x, offset.y);
	movement.y = get_h(offset.y, offset.x);
	while (1)
	{
		printf("dx--> %f\ndy--> %f\n", offset.x, offset.y);
		if (movement.x < movement.y)
		{
			printf("Movimiento en x\n");
			movement.x += 1;
			movement.y = get_h(offset.y, offset.x);
		}
		else
		{
			printf("Movimiento en y\n");
			movement.y += 1;
			movement.x = get_h(offset.x, offset.y);
		}
	}
	// ray.x = get_h(offset.x, offset.y);
	// ray.y = get_h(offset.y, offset.x);
	// // printf("dx--> %f\ndy--> %f\n", ray.x, ray.y);
	// if (ray.x < ray.y)
	// 	move_cords(&movement.x, angle);
	// else
	// 	move_cords(&movement.y, angle);
	// printf("movimiento ---> (%f, %f)\n", movement.x, movement.y);
	return (distance);
}

int	raycast(t_game *data)
{
	t_cords origin;
	t_cords dest;

	set_cords(&origin, &dest, data);
	printf("origin (%f, %f)\n", origin.x, origin.y);
	printf("dest (%f, %f)\n", dest.x, dest.y);


	//Test
	int init_angle = 0;
	double distance;

	// while (init_angle < data->scene.angle)
	// {
		distance = dda(origin, dest, init_angle, data->file.map);
		printf("Distacia --> %f\n", distance);
	// 	init_angle++;
	// }
	return (EXIT_SUCCESS);
}
