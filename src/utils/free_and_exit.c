/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:32:05 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/25 14:49:58 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	free_scene(t_scene *scena)
{
	if (scena->north_texture)
		mlx_delete_texture(scena->north_texture);
	if (scena->south_texture)
		mlx_delete_texture(scena->south_texture);
	if (scena->east_texture)
		mlx_delete_texture(scena->east_texture);
	if (scena->west_texture)
		mlx_delete_texture(scena->west_texture);
}

int	free_and_exit(t_game *data, int exit)
{
	free_scene_info(&data->file);
	free_scene(&data->scene);
	if (data->display.frame)
		mlx_delete_image(data->display.mlx, data->display.frame);
	if (data->display.map)
		mlx_delete_image(data->display.mlx, data->display.map);
	return (exit);
}
