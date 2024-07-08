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
	mlx_loop_end(data->display.mlx_ptr);
	return (0);
}


void	put_img(t_display display, int x, int y, void *image)
{
	mlx_put_image_to_window(display.mlx_ptr, display.win_ptr, image, x * P_SIZE, y * P_SIZE);
}
void	put_img_map(t_game *data, int x, int y)
{
	if (data->file.map[y][x] == '1')
		put_img(data->display, x, y, data->display.frames[0]);
	else if (data->file.map[y][x] == '0')
		put_img(data->display, x, y, data->display.frames[1]);
}

void	put_map(t_game *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->file.map[y])
	{
		x = 0;
		while (data->file.map[y][x])
		{
			put_img_map(data, x, y);
			x++;
		}
		y++;
	}
}
void	put_player(t_game *data)
{
	mlx_clear_window(data->display.mlx_ptr, data->display.win_ptr);
	put_map(data);
	put_img(data->display, data->display.width >> 1, data->display.height >> 1, data->display.frames[2]);
}

int	key_events(int keycode, t_game *data)
{
	printf("Keycode :%d\n", keycode);
	if (keycode == WSL_END)
		exit_window(data);
	// if (keycode == W_UP)
	// 	data->display.y -= SPEED;
	// else if (keycode == S_DOWN)
	// 	data->display.y += SPEED;
	// else if (keycode == A_LEFT)
	// 	data->display.x -= SPEED;
	// else if (keycode == D_RIGHT)
	// 	data->display.x += SPEED;
	put_player(data);
	return (0);
}


int start_grafics(t_game *data)
{
	data->display.mlx_ptr = mlx_init();
	mlx_get_screen_size(data->display.mlx_ptr, &data->display.width, &data->display.height);
	data->display.win_ptr = mlx_new_window(data->display.mlx_ptr, data->display.width - 100, data->display.height - 100, "cube3d");

	int img_width;
	int img_height;

	data->display.frames[0] = mlx_xpm_file_to_image(data->display.mlx_ptr, data->file.north_texture, &img_height, &img_width);
	data->display.frames[1] = mlx_xpm_file_to_image(data->display.mlx_ptr, data->file.south_texture, &img_height, &img_width);
	data->display.frames[2] = mlx_xpm_file_to_image(data->display.mlx_ptr, data->file.west_texture, &img_height, &img_width);
	if (!data->display.frames[0] || !data->display.frames[0] || !data->display.frames[2])
	{
		print_error("Error al abrir la imagen\n");
		return (EXIT_FAILURE);
	}

	put_map(data);
	put_player(data);

	mlx_hook(data->display.win_ptr, ON_DESTROY, 0, exit_window, data);
	mlx_hook(data->display.win_ptr, ON_KEYDOWN, (1L << 0), key_events, data);
	// mlx_loop_hook(data->display.mlx_ptr, game_loop, data);
	mlx_loop(data->display.mlx_ptr);
	free_scene_info(&data->file);
	mlx_destroy_window(data->display.mlx_ptr, data->display.win_ptr);
	mlx_destroy_image(data->display.mlx_ptr, data->display.frames[0]);
	// destroy_textures(data->display.mlx_ptr, &data->scene.textures);
	mlx_destroy_display(data->display.mlx_ptr);
	return (EXIT_SUCCESS);
}
