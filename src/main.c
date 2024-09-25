/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 22:27:18 by albartol          #+#    #+#             */
/*   Updated: 2024/09/25 16:00:25 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	print_info(t_game *data)
{
	ft_printf("───────────────────SCENE-FILE───────────────────\n");
	ft_printf("north_texture: %s\n", data->file.north_texture);
	ft_printf("south_texture: %s\n", data->file.south_texture);
	ft_printf("east_texture:  %s\n", data->file.east_texture);
	ft_printf("west_texture:  %s\n", data->file.west_texture);
	ft_printf("floor_color:   %s\n", data->file.floor_color);
	ft_printf("celling_color: %s\n", data->file.celling_color);
	ft_printf("floor_color:   %X\n", data->scene.floor_color);
	ft_printf("celling_color: %X\n", data->scene.celling_color);
	print_map(data->file.map);
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
	if (preload_textures(&data))
		return (free_and_exit(&data, EXIT_FAILURE));
	if (raycast(&data))
		free_and_exit(&data, EXIT_FAILURE);
	free_and_exit(&data, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
