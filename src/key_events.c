/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:13:52 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/13 16:21:34 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

void	draw_all(t_game *data);
/* 
Nota: las adiciones y restas tanto a x e y son segun el vector de direccion que funciona ahora
W --> mira al Oeste
 */
void	key_events(void *param)
{
	t_game		*data;

	data = (t_game *)param;
	if (mlx_is_key_down(data->display.mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(data->display.mlx);
		printf("Adiooooossss");
	}
	else if (mlx_is_key_down(data->display.mlx, MLX_KEY_W))
	{
		data->player.x -= 0.1;
		printf(YELLOW"Mi posición es :(%d, %d)\n" RESET, (int)data->player.x, (int)data->player.y);
		draw_all(data);
	}
	else if (mlx_is_key_down(data->display.mlx, MLX_KEY_S))
	{
		data->player.x += 0.1;
		printf(YELLOW"Mi posición es :(%d, %d)\n" RESET, (int)data->player.x, (int)data->player.y);
		draw_all(data);
	}
	else if (mlx_is_key_down(data->display.mlx, MLX_KEY_A))
	{
		data->player.y -= 0.1;
		printf(YELLOW"Mi posición es :(%d, %d)\n" RESET, (int)data->player.x, (int)data->player.y);
		draw_all(data);
	}
	else if (mlx_is_key_down(data->display.mlx, MLX_KEY_D))
	{
		data->player.y += 0.1;
		printf(YELLOW"Mi posición es :(%d, %d)\n" RESET, (int)data->player.x, (int)data->player.y);
		draw_all(data);
	}
	//Starting rotations
	// else if (mlx_is_key_down(data->display.mlx, MLX_KEY_LEFT))
	// {
		
	// }
}


// void	key_events(void *param)
// {
// 	t_game		*data;

// 	data = (t_game *)param;
// 	if (mlx_is_key_down(data->display.mlx, MLX_KEY_ESCAPE))
// 	{
// 		mlx_close_window(data->display.mlx);
// 		printf("Adiooooossss");
// 	}
// 	if (mlx_is_key_down(data->display.mlx, MLX_KEY_W))
// 	{
// 		data->player.x += 0.5;
// 		printf(YELLOW"Mi posición es :(%d, %d)\n" RESET, (int)data->player.x, (int)data->player.y);
// 	}
// }
