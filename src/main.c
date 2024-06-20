/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 22:27:18 by albartol          #+#    #+#             */
/*   Updated: 2024/06/20 22:28:14 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void print(void *str)
{
	ft_putstr_fd((char *)str, 1);
	ft_putchar_fd('\n', 1);
}

void print_map(char **map)
{
	int	i;

	i = 0;
	ft_putstr_fd("------------------------------------------------------\n", 1);
	while (map[i])
	{
		ft_putstr_fd(map[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putstr_fd("------------------------------------------------------\n", 1);
}

void print_info(t_scene_file *info)
{
	ft_putstr_fd("------------------------------------------------------\n", 1);
	ft_putstr_fd(info->north_texture, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(info->south_texture, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(info->east_texture, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(info->west_texture, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(info->floor_color, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(info->celling_color, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("------------------------------------------------------\n", 1);
}

void	game_data_init(t_game *data)
{
	data->display.mlx_ptr = NULL;
	data->display.win_ptr = NULL;
	data->file.file_content = NULL;
	data->file.north_texture = NULL;
	data->file.south_texture = NULL;
	data->file.east_texture = NULL;
	data->file.west_texture = NULL;
	data->file.floor_color = NULL;
	data->file.celling_color = NULL;
	data->file.map = NULL;
	data->scene.textures.north_texture.img = NULL;
	data->scene.textures.south_texture.img = NULL;
	data->scene.textures.east_texture.img = NULL;
	data->scene.textures.west_texture.img = NULL;
	data->scene.textures.north_texture.addr = NULL;
	data->scene.textures.south_texture.addr = NULL;
	data->scene.textures.east_texture.addr = NULL;
	data->scene.textures.west_texture.addr = NULL;
}

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

int	main(int argc, char **argv)
{
	t_game	data;

	if (argc != 2)
	{
		print_error("Wrong number of arguments\n");
		return (EXIT_FAILURE);
	}
	game_data_init(&data);
	if (read_scene_file(&data.file, argv[1]))
		return (EXIT_FAILURE);
	ft_lstiter(data.file.file_content, print);
	if (extract_scene_info(&data.file))
		return (EXIT_FAILURE);
	print_info(&data.file);
	print_map(data.file.map);
	free_scene_info(&data.file);
	return (EXIT_SUCCESS);
}
