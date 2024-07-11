/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_grafics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:44:53 by flopez-r          #+#    #+#             */
/*   Updated: 2024/07/10 22:05:14 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

int start_grafics(t_game *data)
{
	// mlx_get_monitor_size(0, &data->display.width, &data->display.height);
	// mlx_set_setting(MLX_FULLSCREEN, true);
	// data->display.mlx = mlx_init(data->display.width, data->display.height,
	// 	"cube3d", false);
	data->display.mlx = mlx_init(800, 600, "cube3d", false);
	if (!data->display.mlx)
		return (exit_msg(mlx_strerror(mlx_errno), EXIT_FAILURE));
	mlx_loop(data->display.mlx);
	mlx_terminate(data->display.mlx);
	return (EXIT_SUCCESS);
}
