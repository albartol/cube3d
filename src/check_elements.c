/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:31:15 by albartol          #+#    #+#             */
/*   Updated: 2024/06/23 00:41:33 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>
#include <check_scene.h>

static int	check_texture_path(const char *texture_path)
{
	int	fd;

	if (check_file_type(texture_path, ".xpm"))
	{
		print_error(texture_path);
		ft_putstr_fd(": The texture must be a *.xpm file\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	fd = open(texture_path, O_RDONLY);
	if (fd == -1)
	{
		print_error(NULL);
		perror(texture_path);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	check_elements(t_scene_file *info, t_scene *scene)
{
	if (check_colors(info->floor_color, info->celling_color, scene))
	{
		if (errno != ENOMEM)
			print_error("Invalid format for the color elements\n");
		else
			perror(NULL);
		return (EXIT_FAILURE);
	}
	if (check_texture_path(info->north_texture)
		|| check_texture_path(info->south_texture)
		|| check_texture_path(info->east_texture)
		|| check_texture_path(info->west_texture))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
