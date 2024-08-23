/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:13:52 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/23 11:02:58 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <raycast.h>

void	draw_all(t_game *data);

float transform_angle(float angle)
{
    float two_pi = 2.0f * PI;
    
    if (angle > two_pi)
        return (angle - two_pi);
    if (angle < 0)
        return (angle + two_pi);
    return (angle);
}
/* 
Returns true if its no colitions
and false si hay colisiones
 */
int	checker(float x, float y, char **map)
{
	int new_x;
	int new_y;

	new_x = (int)x;
	new_y = (int)y;
	if (new_x < 0 || new_y < 0)	
		return (0);
	if (map[new_y][new_x] == '1')
		return (0);
	return (1);
}

float	convert_to_radian(float number)
{
	return (number * (PI / 180));
}

/* 
Nota: las adiciones y restas tanto a x e y son segun el vector de direccion que funciona ahora
W --> mira al Oeste
 */
// void	key_events(void *param)
void	movement(void* param)
{
	t_game		*data;
	t_cords		save_pos;
	t_cords		save_plane;
	t_cords		new;

	data = (t_game *)param;

	// For the panzer movement
	new.x = data->player.x;
	new.y = data->player.y;

	//For the rotation
	save_pos.x = data->player.dir_vector.x;
	save_pos.y = data->player.dir_vector.y;

	//For the plane of the camera
	save_plane.x = data->player.camera_plane.x;
	save_plane.y = data->player.camera_plane.y;

	if (mlx_is_key_down(data->display.mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(data->display.mlx);
		printf("Thanks for playing");
	}
	else if (mlx_is_key_down(data->display.mlx, MLX_KEY_W))
	{
		new.x += cos(data->player.angle) * MOVE_SPEED;
		new.y -= sin(data->player.angle) * MOVE_SPEED;
	}
	else if (mlx_is_key_down(data->display.mlx, MLX_KEY_S))
	{
		new.x -= cos(data->player.angle) * MOVE_SPEED;
		new.y += sin(data->player.angle) * MOVE_SPEED;
	}
	else if (mlx_is_key_down(data->display.mlx, MLX_KEY_A))
	{
		new.x += sin(data->player.angle) * MOVE_SPEED;
		new.y += cos(data->player.angle) * MOVE_SPEED;
	}
	else if (mlx_is_key_down(data->display.mlx, MLX_KEY_D))
	{
		new.x -= sin(data->player.angle) * MOVE_SPEED;
		new.y -= cos(data->player.angle) * MOVE_SPEED;
	}
	if (checker(new.x, new.y, data->file.map))
	{
		data->player.x = new.x;
		data->player.y = new.y;
		draw_all(data);
		printf(YELLOW"Mi posición es :(%d, %d)\n" RESET, (int)data->player.x, (int)data->player.y);
	}
	else
		printf(RED"COLISION DETECTED YOUUU WILL NOTT PASSSS 🧙🏻‍♂️\n"RESET);
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
	if ( mlx_is_key_down(data->display.mlx, MLX_KEY_LEFT)  ||  mlx_is_key_down(data->display.mlx, MLX_KEY_Q) )
	{
		//Rotate the direction vector
		data->player.dir_vector.x = save_pos.x * cos(ROTATION_SPEED_R) - save_pos.y * sin(ROTATION_SPEED_R);
		data->player.dir_vector.y = save_pos.x * sin(ROTATION_SPEED_R) + save_pos.y * cos(ROTATION_SPEED_R);

		//Rotate the camera plane
		data->player.camera_plane.x = save_plane.x * cos(ROTATION_SPEED_R) - save_plane.y * sin(ROTATION_SPEED_R);
		data->player.camera_plane.y = save_plane.x * sin(ROTATION_SPEED_R) + save_plane.y * cos(ROTATION_SPEED_R);
		
		printf(YELLOW"Rotando %f grados (right)\n" RESET, ROTATION_SPEED_R);
		data->player.angle -= transform_angle(ROTATION_SPEED_R);
		draw_all(data);
	}
	else if ( mlx_is_key_down(data->display.mlx, MLX_KEY_RIGHT)  ||  mlx_is_key_down(data->display.mlx, MLX_KEY_E) )
	{
		//Rotate the direction vector
		data->player.dir_vector.x = save_pos.x * cos(-ROTATION_SPEED_R) - save_pos.y * sin(-ROTATION_SPEED_R);
		data->player.dir_vector.y = save_pos.x * sin(-ROTATION_SPEED_R) + save_pos.y * cos(-ROTATION_SPEED_R);

		//Rotate the camera plane
		data->player.camera_plane.x = save_plane.x * cos(-ROTATION_SPEED_R) - save_plane.y * sin(-ROTATION_SPEED_R);
		data->player.camera_plane.y = save_plane.x * sin(-ROTATION_SPEED_R) + save_plane.y * cos(-ROTATION_SPEED_R);

		printf(YELLOW"Rotando %f grados (right)\n" RESET, ROTATION_SPEED);
		data->player.angle += transform_angle(ROTATION_SPEED_R);
		draw_all(data);
	}
	else if ( mlx_is_key_down(data->display.mlx, MLX_KEY_UP))
	{
		printf(YELLOW"Rotando %f grados (up)\n" RESET, ROTATION_SPEED);
		data->player.move_y += ROTATION_SPEED * PI;
		if (data->player.move_y > LIMIT_UP_DOWN)
			data->player.move_y = LIMIT_UP_DOWN;
		draw_all(data);
	}
	else if ( mlx_is_key_down(data->display.mlx, MLX_KEY_DOWN))
	{
		printf(YELLOW"Rotando %f grados (down)\n" RESET, ROTATION_SPEED * PI);
		data->player.move_y -= ROTATION_SPEED * PI;
		if (data->player.move_y < -LIMIT_UP_DOWN)
			data->player.move_y = -LIMIT_UP_DOWN;
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
