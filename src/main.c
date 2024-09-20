/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 22:27:18 by albartol          #+#    #+#             */
/*   Updated: 2024/09/20 12:40:17 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	print_info(t_game *data)
{
	ft_printf("───────────────────SCENE-FILE───────────────────\n");
	ft_printf("%s\n", data->file.north_texture);
	ft_printf("%s\n", data->file.south_texture);
	ft_printf("%s\n", data->file.east_texture);
	ft_printf("%s\n", data->file.west_texture);
	ft_printf("%s\n", data->file.floor_color);
	ft_printf("%s\n", data->file.celling_color);
	ft_printf("───────────────────SCENE────────────────────────\n");
	ft_printf("Map width ----->   %lu\n", data->scene.map_width);
	ft_printf("Map height ---->   %lu\n", data->scene.map_height);
	ft_printf("Player x ------>   %lu\n", data->scene.player_x);
	ft_printf("Player y ------>   %lu\n", data->scene.player_y);
	ft_printf("Player angle -->   %d\n", data->scene.angle);
	ft_printf("──────────────────────────────────────────────────────\n");
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
	if (extract_scene_info(&data.file))
		return (free_and_exit(&data, EXIT_FAILURE));
	if (check_scene_info(&data))
		return (free_and_exit(&data, EXIT_FAILURE));
	print_info(&data);
	print_map(data.file.map);
	printf("floor_color: %X\n", data.scene.floor_color);
	printf("celling_color: %X\n", data.scene.celling_color);
	if (preload_textures(&data))
		return (free_and_exit(&data, EXIT_FAILURE));
	raycast(&data);
	free_and_exit(&data, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
