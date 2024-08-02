/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 22:27:18 by albartol          #+#    #+#             */
/*   Updated: 2024/08/02 14:55:31 by flopez-r         ###   ########.fr       */
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

void print_info(t_game *data)
{
	ft_putstr_fd("───────────────────SCENE-FILE───────────────────\n", 1);
	printf("%s\n", data->file.north_texture);
	printf("%s\n", data->file.south_texture);
	printf("%s\n", data->file.east_texture);
	printf("%s\n", data->file.west_texture);
	printf("%s\n", data->file.floor_color);
	printf("%s\n", data->file.celling_color);
	ft_putstr_fd("───────────────────SCENE────────────────────────\n", 1);

	printf("Map width ----->   %lu\n", data->scene.map_width);
	printf("Map height ---->   %lu\n", data->scene.map_height);
	printf("Player x ------>   %lu\n", data->scene.player_x);
	printf("Player y ------>   %lu\n", data->scene.player_y);
	printf("Player angle -->   %d\n", data->scene.angle);
	ft_putstr_fd("──────────────────────────────────────────────────────\n", 1);
}

void	game_data_init(t_game *data)
{
	data = ft_memset(data, 0, sizeof(t_game));
}

int	main(int argc, char **argv)
{
	t_game	data;

	if (argc != 2)
		return (exit_msg("Wrong number of arguments\n", EXIT_FAILURE));
	game_data_init(&data);
	if (read_scene_file(&data.file, argv[1]))
		return (EXIT_FAILURE);
	// ft_lstiter(data.file.file_content, print);
	if (extract_scene_info(&data.file))
		return (free_and_exit(&data, EXIT_FAILURE));
	if (check_scene_info(&data.file, &data.scene))
		return (free_and_exit(&data, EXIT_FAILURE));
	print_info(&data);
	print_map(data.file.map);
	free_scene_info(&data.file);
	printf("floor_color: %0X\n", data.scene.floor_color);
	printf("celling_color: %0X\n", data.scene.celling_color);
	return (EXIT_SUCCESS);
}
