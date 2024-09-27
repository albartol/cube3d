/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preload_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:33:53 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/27 14:57:48 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check_scene.h>
#include <raycast.h>

int	preload_textures(t_game *data)
{
	data->scene.north_texture = mlx_load_png(data->file.north_texture);
	if (!data->scene.north_texture)
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
	data->scene.south_texture = mlx_load_png(data->file.south_texture);
	if (!data->scene.south_texture)
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
	data->scene.east_texture = mlx_load_png(data->file.east_texture);
	if (!data->scene.east_texture)
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
	data->scene.west_texture = mlx_load_png(data->file.west_texture);
	if (!data->scene.west_texture)
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
	return (EXIT_SUCCESS);
}
