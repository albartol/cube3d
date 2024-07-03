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

int	key_events(int keycode, t_game *data)
{
	if (keycode == WSL_END)
		exit_window(data);
	printf ("Keycode: %d\n", keycode);
	return (0);
}

int start_grafics(t_game *data)
{
	data->display.mlx_ptr = mlx_init();
	data->display.win_ptr = mlx_new_window(data->display.mlx_ptr, 800, 400, "C3D");

	void *img;
	int img_width;
	int img_height;

	img = mlx_xpm_file_to_image(data->display.mlx_ptr, "./textures/east_wall.xpm", &img_height, &img_width);
	if (!img)
	{
		printf("Error al abrir la imagen\n");
		exit_window(data);
	}

	mlx_put_image_to_window(data->display.mlx_ptr, data->display.win_ptr, img, 200, 200);

	mlx_hook(data->display.win_ptr, 17, 0, exit_window, data);
	mlx_hook(data->display.win_ptr, 2, (1L << 0), key_events, data);
	mlx_loop(data->display.mlx_ptr);
	return (EXIT_SUCCESS);
}
