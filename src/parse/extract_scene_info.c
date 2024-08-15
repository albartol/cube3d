/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_scene_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:09:48 by albartol          #+#    #+#             */
/*   Updated: 2024/06/20 21:34:12 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>
#include <extract_scene.h>

int	extract_scene_info(t_scene_file *scene_info)
{
	size_t	list_pos;

	list_pos = extract_elements(scene_info);
	if (list_pos < 5 || !scene_info->north_texture
		|| !scene_info->south_texture || !scene_info->east_texture
		|| !scene_info->west_texture || !scene_info->floor_color
		|| !scene_info->celling_color)
	{
		if (errno != ENOMEM)
			print_error("Invalid or missing elements in scene file\n");
		return (EXIT_FAILURE);
	}
	if (extract_map(scene_info, list_pos))
	{
		perror(NULL);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
