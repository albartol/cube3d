/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:28:31 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/09 21:48:48 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

static void	set_ray_val(t_raycast *info, t_game *data)
{
	info->ray_dir.x = data->player.dir.x + data->player.plane.x * info->camera_pos;
	info->ray_dir.y = data->player.dir.y + data->player.plane.y * info->camera_pos;
	info->map_pos.x = (int)data->player.pos.x;
	info->map_pos.y = (int)data->player.pos.y;
	if (info->ray_dir.x == 0)
		info->delta_dist.x = DBL_MAX;
	else
		info->delta_dist.x = fabs(1 / info->ray_dir.x);
	if (info->ray_dir.y == 0)
		info->delta_dist.y = DBL_MAX;
	else
		info->delta_dist.y = fabs(1 / info->ray_dir.y);
	info->hit = 0;
}

static void	set_side_dist(t_raycast *info, t_game *data)
{
	if (info->ray_dir.x < 0)
	{
		info->step_dir.x = -1;
		info->side_dist.x = (data->player.pos.x - info->map_pos.x) * info->delta_dist.x;
	}
	else
	{
		info->step_dir.x = 1;
		info->side_dist.x = (info->map_pos.x + 1.0 - data->player.pos.x) * info->delta_dist.x;
	}
	if (info->ray_dir.y < 0)
	{
		info->step_dir.y = -1;
		info->side_dist.y = (data->player.pos.y - info->map_pos.y) * info->delta_dist.y;
	}
	else
	{
		info->step_dir.y = 1;
		info->side_dist.y = (info->map_pos.y + 1.0 - data->player.pos.y) * info->delta_dist.y;
	}
}

int	raycast(t_game *data)
{
	t_raycast		info;
	unsigned int	ray_num;
	unsigned int	total_ray;
	data->player.pos.x = data->scene.player_x;
	data->player.pos.y = data->scene.player_y;
	data->player.dir.x = -1;
	data->player.dir.y = 0;
	data->player.plane.x = 0;
	data->player.plane.y = 0.66;

	printf("player pos (%f, %f)\n", data->player.pos.x,data->player.pos.y);
	
	ray_num = 0;
	total_ray = RAY_NUM;

	while (ray_num <= total_ray)
	{
		info.camera_pos = 2 * ray_num / (double)total_ray - 1;
		set_ray_val(&info, data);
		set_side_dist(&info, data);

		printf("-------------------------------------------------------------\n");
		printf("camara pos %f \n", info.camera_pos);
		printf("ray dir x %f \n", info.ray_dir.x);
		printf("ray dir y %f \n", info.ray_dir.y);
		printf("side dist x %f \n", info.side_dist.x);
		printf("side dist y %f \n", info.side_dist.y);
		printf("desta dist x %f \n", info.delta_dist.x);
		printf("desta dist y %f \n", info.delta_dist.y);
		printf("step x %i \n", info.step_dir.x);
		printf("step y %i \n", info.step_dir.y);
		printf("-------------------------------------------------------------\n");

		dda(&info, data->file.map);

		if(info.side_hit == 0)
			info.dist_to_wall = (info.side_dist.x - info.delta_dist.x);
		else
			info.dist_to_wall = (info.side_dist.y - info.delta_dist.y);

		printf("Distancia --> %f\n", info.dist_to_wall);
		printf("-------------------------------------------------------------\n");
		ray_num++;
	}
	return (EXIT_SUCCESS);
}
