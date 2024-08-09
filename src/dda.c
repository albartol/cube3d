/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:05:27 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/09 19:02:00 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>
#include <check_scene.h>

void	dda(t_raycast *info, char **map)
{
	while (info->hit == 0)
	{
		printf("map pos (%i, %i)\n", info->map_pos.x,info->map_pos.y);
		if (info->side_dist.x < info->side_dist.y)
		{
			info->side_dist.x += info->delta_dist.x;
			info->map_pos.x += info->step_dir.x;
			info->side_hit = 0;
			printf("Me he movido en x %i pasos\n", info->step_dir.x);
			printf("side dist x %f \n", info->side_dist.x);
		}
		else
		{
			info->side_dist.y += info->delta_dist.y;
			info->map_pos.y += info->step_dir.y;
			info->side_hit = 1;
			printf("Me he movido en y %i pasos\n", info->step_dir.y);
			printf("side dist y %f \n", info->side_dist.y);
		}
		int	width;
		int height;

		if (info->map_pos.x < 0 || info->map_pos.y < 0)
			continue ;
		width = ft_strlen(map[info->map_pos.y]);
		height = array_len(map);

		if ((info->map_pos.x >= width || info->map_pos.y >= height) ||
			(map[info->map_pos.y][info->map_pos.x] == WALL))
			info->hit = 1;
	}
}
