/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preload_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:33:53 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/20 12:56:24 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check_scene.h>
#include <raycast.h>

int	preload_textures(t_game *data)
{
	data->scene.north_texture = mlx_load_png(data->file.north_texture);
	data->scene.south_texture = mlx_load_png(data->file.south_texture);
	data->scene.east_texture = mlx_load_png(data->file.east_texture);
	data->scene.west_texture = mlx_load_png(data->file.west_texture);
	if (!data->scene.north_texture || !data->scene.south_texture
		|| !data->scene.east_texture || !data->scene.west_texture)
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
	return (EXIT_SUCCESS);
}
