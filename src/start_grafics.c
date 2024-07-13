/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_grafics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:44:53 by flopez-r          #+#    #+#             */
/*   Updated: 2024/07/13 16:10:06 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

// void	key_functions(void *param)
// {
// 	t_game	*data;

// 	data = (t_game *)param;
// 	if (mlx_is_key_down(data->display.mlx, MLX_KEY_ESCAPE))
// 	{
// 		printf("Bye bye!\n");
// 		free_scene_info(&data->file);
// 		mlx_close_window(data->display.mlx);
// 	}
// 	if (mlx_is_key_down(data->display.mlx, MLX_KEY_A))
// }

uint32_t ft_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t t)
{
	return (r << 24 | g << 16 | b << 8 | t);
}

void	key_functions(mlx_key_data_t keydata, void *param)
{
	t_game	*data;

	data = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(data->display.mlx);
}

void	fill_color(mlx_image_t *img, uint32_t r, uint32_t g, uint32_t b, uint32_t t)
{
	uint32_t	i;
	uint32_t	j;
	uint32_t	color;

	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			color = ft_pixel(r, g, b, t);
			mlx_put_pixel(img, j, i, color);
			j++;
		}
		i++;
	}
}

int	put_map(char **map, t_display *display)
{
	int			x;
	int			y;
	mlx_image_t	*wall;

	wall = mlx_new_image(display->mlx, P_SIZE, P_SIZE);
	if (!wall)
		return (exit_msg("Fail to create an image\n", EXIT_FAILURE));
	fill_color(wall, 255, 255, 255, 255);
	y = 0;
	printf("Imprimiendo mapa\n");
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_image_to_window(display->mlx, wall, x * P_SIZE, y * P_SIZE);
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

int start_grafics(t_game *data)
{
	// mlx_get_monitor_size(0, &data->display.width, &data->display.height);
	// mlx_set_setting(MLX_FULLSCREEN, true);
	// data->display.mlx = mlx_init(data->display.width, data->display.height,
	// 	"cube3d", false);

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->display.mlx = mlx_init(data->scene.map_width * P_SIZE, data->scene.map_height * P_SIZE, "cube3d", true);
	if (!data->display.mlx)
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));

	if (put_map(data->file.map, &data->display))
		return (EXIT_FAILURE);
	mlx_key_hook(data->display.mlx, key_functions, data);
	// mlx_loop_hook(data->display.mlx, key_functions, data);
	mlx_loop(data->display.mlx);
	mlx_terminate(data->display.mlx);
	free_scene_info(&data->file);
	return (EXIT_SUCCESS);
}
