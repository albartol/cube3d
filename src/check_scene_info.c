/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:31:15 by albartol          #+#    #+#             */
/*   Updated: 2024/06/22 18:24:16 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>
#include <check_scene.h>

int	check_scene_info(t_scene_file *scene_info, t_scene *scene)
{
	if (check_elements(scene_info, scene))
		return (EXIT_FAILURE);
	if (check_map(scene_info))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
