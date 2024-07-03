/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 22:27:18 by albartol          #+#    #+#             */
/*   Updated: 2024/07/03 18:28:55 by flopez-r         ###   ########.fr       */
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
	int	j;

	i = 0;
	ft_putstr_fd("────────────────────────MAP──────────────────────\n", 1);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSWE", map[i][j]))
				printf(PLAYER_COL);
			else if (map[i][j] == '1')
				printf(WALL_COL);
			printf("%c", map[i][j]);
			printf(RESET);
			j++;
		}
		printf("\n");
		i++;
	}
	ft_putstr_fd("──────────────────────────────────────────────────────\n", 1);
}

void print_info(t_scene_file *info)
{
	ft_putstr_fd("──────────────────────────────────────────────────────\n", 1);
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
	ft_putstr_fd("──────────────────────────────────────────────────────\n", 1);
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
	data->scene.floor_color = 0;
	data->scene.celling_color = 0;
	data->scene.textures.north_texture.img = NULL;
	data->scene.textures.south_texture.img = NULL;
	data->scene.textures.east_texture.img = NULL;
	data->scene.textures.west_texture.img = NULL;
	data->scene.textures.north_texture.addr = NULL;
	data->scene.textures.south_texture.addr = NULL;
	data->scene.textures.east_texture.addr = NULL;
	data->scene.textures.west_texture.addr = NULL;
}

int	main(int argc, char **argv)
{
	t_game	data;

	if (argc != 2)
		return (exit_msg("Wrong number of arguments\n", EXIT_FAILURE));
	game_data_init(&data);
	if (read_scene_file(&data.file, argv[1]))
		return (EXIT_FAILURE);
	ft_lstiter(data.file.file_content, print);
	if (extract_scene_info(&data.file))
	{
		free_scene_info(&data.file);
		return (EXIT_FAILURE);
	}
	print_info(&data.file);
	print_map(data.file.map);
	if (check_scene_info(&data.file, &data.scene))
	{
		free_scene_info(&data.file);
		return (EXIT_FAILURE);
	}
	// free_scene_info(&data.file);
	printf("floor_color: %0X\n", data.scene.floor_color);
	printf("celling_color: %0X\n", data.scene.celling_color);
	// if (init_images(&data))
	// {
	// 	free_scene_info(&data.file);
	// 	return (EXIT_FAILURE);
	// }
	if (start_grafics(&data))
	{
		free_scene_info(&data.file);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
