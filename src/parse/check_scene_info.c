/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:31:15 by albartol          #+#    #+#             */
/*   Updated: 2024/08/13 14:02:36 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>
#include <check_scene.h>

int	check_scene_info(t_game	*data)
{
	if (check_elements(&data->file, &data->scene))
		return (EXIT_FAILURE);
	if (check_map(data->file.map, data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
