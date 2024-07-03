/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:30:03 by flopez-r          #+#    #+#             */
/*   Updated: 2024/07/03 15:30:20 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	free_scene_info(t_scene_file *info)
{
	ft_lstclear(&info->file_content, free);
	array_free(info->map);
	free(info->north_texture);
	free(info->south_texture);
	free(info->east_texture);
	free(info->west_texture);
	free(info->floor_color);
	free(info->celling_color);
}
