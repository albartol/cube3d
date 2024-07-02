/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:31:15 by albartol          #+#    #+#             */
/*   Updated: 2024/07/02 12:32:54 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>
#include <check_scene.h>

int	check_scene_info(t_scene_file *scene_info, t_scene *scene)
{
	if (check_elements(scene_info, scene))
		return (EXIT_FAILURE);
	if (check_map(scene_info->map))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
