/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_grafics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:44:53 by flopez-r          #+#    #+#             */
/*   Updated: 2024/07/03 17:29:43 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

int exit_window(t_game	*data)
{
	(void)data;
	printf("%s%s"RESET, YELLOW, "Bye bye!");
	free_scene_info(&data->file);
	exit(0);
	return (0);
}

void	put_player(t_game *data)
{
	mlx_clear_window(data->display.mlx_ptr, data->display.win_ptr);
	mlx_put_image_to_window(data->display.mlx_ptr, data->display.win_ptr, data->display.player_map, data->display.x, data->display.y);
}

int	key_events(int keycode, t_game *data)
{
	printf("Keycode :%d\n", keycode);
	if (keycode == WSL_END)
		exit_window(data);
	if (keycode == W_UP)
		data->display.y -= SPEED;
	else if (keycode == S_DOWN)
		data->display.y += SPEED;
	else if (keycode == A_LEFT)
		data->display.x -= SPEED;
	else if (keycode == D_RIGHT)
		data->display.x += SPEED;
	put_player(data);
	return (0);
}


int start_grafics(t_game *data)
{
	data->display.x = 800;
	data->display.y = 600;
	data->display.mlx_ptr = mlx_init();
	data->display.win_ptr = mlx_new_window(data->display.mlx_ptr, 1600, 1200, "C3D");

	int img_width;
	int img_height;

	data->display.player_map = mlx_xpm_file_to_image(data->display.mlx_ptr, "./textures/east_wall.xpm", &img_height, &img_width);
	if (!data->display.player_map)
	{
		printf("Error al abrir la imagen\n");
		exit_window(data);
	}

	put_player(data);

	mlx_hook(data->display.win_ptr, 17, 0, exit_window, data);
	mlx_hook(data->display.win_ptr, 2, (1L << 0), key_events, data);
	mlx_loop(data->display.mlx_ptr);
	return (EXIT_SUCCESS);
}
