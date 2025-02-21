/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:28:31 by flopez-r          #+#    #+#             */
/*   Updated: 2024/09/26 17:41:33 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check_scene.h>
#include <raycast.h>

static void	keys_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*data;

	data = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		mlx_close_window(data->display.mlx);
		ft_putstr_fd("Thanks for playing\n", STDOUT_FILENO);
	}
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_RELEASE)
		data->display.map->enabled = !data->display.map->enabled;
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_RELEASE)
	{
		data->mouse = !data->mouse;
		if (data->mouse)
			mlx_set_cursor_mode(data->display.mlx, MLX_MOUSE_NORMAL);
		else
			mlx_set_cursor_mode(data->display.mlx, MLX_MOUSE_HIDDEN);
	}
}

static void	close_hook(void *param)
{
	t_game	*data;

	data = (t_game *)param;
	(void)data;
	ft_putstr_fd("Thanks for playing\n", STDOUT_FILENO);
}

int	raycast(t_game *data)
{
	data->display.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cube 3D", false);
	if (!data->display.mlx)
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
	if (init_ray_values(data))
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
	if (mlx_image_to_window(data->display.mlx, data->display.frame, 0, 0) == -1)
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
	if (mlx_image_to_window(data->display.mlx, data->display.map, 0, 0) == -1)
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
	if (!mlx_loop_hook(data->display.mlx, game_loop, data))
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
	mlx_key_hook(data->display.mlx, keys_hook, data);
	mlx_close_hook(data->display.mlx, close_hook, data);
	data->mouse = !data->mouse;
	mlx_loop(data->display.mlx);
	return (EXIT_SUCCESS);
}
