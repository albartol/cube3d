/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:31:15 by albartol          #+#    #+#             */
/*   Updated: 2024/08/26 10:30:18 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>
#include <check_scene.h>

static int	check_texture_path(const char *texture_path)
{
	int	fd;

	if (/* check_file_type(texture_path, ".xpm") &&  */check_file_type(texture_path, ".png"))
	{
		print_error(texture_path);
		ft_putstr_fd(": The texture must be an *.png file\n", STDERR_FILENO);
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
