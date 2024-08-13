/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:13:52 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/13 16:52:37 by flopez-r         ###   ########.fr       */
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
	t_cords		save;

	data = (t_game *)param;

	//For the rotation
	save.x = data->player.dir_vector.x;
	save.y = data->player.dir_vector.y;

	if (mlx_is_key_down(data->display.mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(data->display.mlx);
		printf("Adiooooossss");
	}
	else if (mlx_is_key_down(data->display.mlx, MLX_KEY_W))
	{
		data->player.x -= MOVE_SPEED;
		printf(YELLOW"Mi posición es :(%d, %d)\n" RESET, (int)data->player.x, (int)data->player.y);
		draw_all(data);
	}
	else if (mlx_is_key_down(data->display.mlx, MLX_KEY_S))
	{
		data->player.x += MOVE_SPEED;
		printf(YELLOW"Mi posición es :(%d, %d)\n" RESET, (int)data->player.x, (int)data->player.y);
		draw_all(data);
	}
	else if (mlx_is_key_down(data->display.mlx, MLX_KEY_A))
	{
		data->player.y -= MOVE_SPEED;
		printf(YELLOW"Mi posición es :(%d, %d)\n" RESET, (int)data->player.x, (int)data->player.y);
		draw_all(data);
	}
	else if (mlx_is_key_down(data->display.mlx, MLX_KEY_D))
	{
		data->player.y += MOVE_SPEED;
		printf(YELLOW"Mi posición es :(%d, %d)\n" RESET, (int)data->player.x, (int)data->player.y);
		draw_all(data);
	}
	//Rotation
	/* 
	Dada la matriz de rotacion:
	[cos( θ )	- 	sin( θ )]
	[sin( θ )	+ 	cos( θ )]

	podemos hacer una ecuación matricial donde: x0, y0 son las coordenadas originales del player
	y θ el angulo de movimiento (rotation speed)
	
	[cos( θ )	- 	sin( θ )] [x0] = [xResult]
	[sin( θ )	+ 	cos( θ )] [y0] = [yResult]

	//Esta ecuación matricial está hecha para coordenadas dirigidas a la izq 
	(pero funciona igual si el angulo es negativo (para el otro lado(derecha)))
	 */
	else if (mlx_is_key_down(data->display.mlx, MLX_KEY_LEFT))
	{
		data->player.dir_vector.x = save.x * cos(ROTATION_SPEED_R) - save.y * sin(ROTATION_SPEED_R);
		data->player.dir_vector.y = save.x * sin(ROTATION_SPEED_R) + save.y * cos(ROTATION_SPEED_R);
		printf(YELLOW"Rotando %f grados (right)\n" RESET, ROTATION_SPEED);
		draw_all(data);
	}
	else if (mlx_is_key_down(data->display.mlx, MLX_KEY_RIGHT))
	{
		data->player.dir_vector.x = save.x * cos(-ROTATION_SPEED_R) - save.y * sin(-ROTATION_SPEED_R);
		data->player.dir_vector.y = save.x * sin(-ROTATION_SPEED_R) + save.y * cos(-ROTATION_SPEED_R);
		printf(YELLOW"Rotando %f grados (right)\n" RESET, ROTATION_SPEED);
		draw_all(data);
	}
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
