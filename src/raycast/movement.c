/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:13:52 by flopez-r          #+#    #+#             */
/*   Updated: 2024/08/19 15:20:46 by flopez-r         ###   ########.fr       */
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

// float	transform_angle(float angle)
// {
// 	if (angle > 360)
// 		return (angle - 360);
// 	if (angle < 0)
// 		return (angle + 360);
// 	return (angle);
// }

/* 
Holaaa, este es un sistema de colisiones provisional (como el so_long)
Tenemos el mismo problema con las colisiones que en tu versión anterior del
ray casting (atraviesa esquinas) --> podemos hacer las colisiones tomando
la distancia en la que se encuentra el jugador respecto a las paredes en lugar
de hacerlo con el mapa
Ej:
	P --------------------------> WALL | Distancia = 20 (puede avanzar)
	        P ------------------> WALL | Distancia = 15 (puede avanzar)
	                 P ---------> WALL | Distancia = 8  (puede avanzar)
	                     P -----> WALL | Distancia = 5  (puede avanzar) 
	                          P > WALL | Distancia = 0  (no puede avanzar, se detecta colisión)
:D
o....
Podríamos agarrarnos el width y height del mapa y controlar los segfaults
(aunque creo que es mejor hacerlo de la 2da manera (distancias) como dijimos desde el principio)

Edit:
	le agregué un map[y][x] == 0 y al parecer ahora funciona....
 */
int	checker(int x, int y, char **map)
{
	// printf("bef --> (%d, %d)\n", x, y);
	y /= P_SIZE;
	x /= P_SIZE;
	// printf("Aft --> (%d, %d)\n", x, y);
	if (x < 0 || y < 0)
		return (EXIT_FAILURE);
	if (map[y][x] == 0 || map[y][x] == '1')
	{
		printf("Soy una pared\n");
		return (EXIT_FAILURE);
	}
	return(EXIT_SUCCESS);
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
	// else if (mlx_is_key_down(data->display.mlx, MLX_KEY_W))
	// {
	// 	new.x += cos(data->player.angle) * MOVE_SPEED;
	// 	new.y -= sin(data->player.angle) * MOVE_SPEED;
	// }
	// else if (mlx_is_key_down(data->display.mlx, MLX_KEY_S))
	// {
	// 	new.x -= cos(data->player.angle) * MOVE_SPEED;
	// 	new.y += sin(data->player.angle) * MOVE_SPEED;
	// }
	// else if (mlx_is_key_down(data->display.mlx, MLX_KEY_A))
	// {
	// 	new.x += sin(data->player.angle) * MOVE_SPEED;
	// 	new.y += cos(data->player.angle) * MOVE_SPEED;
	// }
	// else if (mlx_is_key_down(data->display.mlx, MLX_KEY_D))
	// {
	// 	new.x -= sin(data->player.angle) * MOVE_SPEED;
	// 	new.y -= cos(data->player.angle) * MOVE_SPEED;
	// }
	// if (checker((int)new.x, (int)new.y, data->file.map))
	// {
	// 	data->player.x = new.x;
	// 	data->player.y = new.y;
	// 	draw_all(data);
	// 	printf(YELLOW"Mi posición es :(%d, %d)\n" RESET, (int)data->player.x, (int)data->player.y);
	// }
	// else
	// 	printf(RED"COLISION DETECTED YOUUU WILL NOTT PASSSS 🧙🏻‍♂️\n"RESET);
	// //Rotation
	// /* 
	// Dada la matriz de rotacion:
	// [cos( θ )	- 	sin( θ )]
	// [sin( θ )	+ 	cos( θ )]

	// podemos hacer una ecuación matricial donde: x0, y0 son las coordenadas originales del player
	// y θ el angulo de movimiento (rotation speed)
	
	// [cos( θ )	- 	sin( θ )] [x0] = [xResult]
	// [sin( θ )	+ 	cos( θ )] [y0] = [yResult]

	// //Esta ecuación matricial está hecha para coordenadas dirigidas a la izq 
	// (pero funciona igual si el angulo es negativo (para el otro lado(derecha)))
	//  */
	// if ( mlx_is_key_down(data->display.mlx, MLX_KEY_LEFT)  ||  mlx_is_key_down(data->display.mlx, MLX_KEY_Q) )
	// {
	// 	//Rotate the direction vector
	// 	data->player.dir_vector.x = save_pos.x * cos(ROTATION_SPEED_R) - save_pos.y * sin(ROTATION_SPEED_R);
	// 	data->player.dir_vector.y = save_pos.x * sin(ROTATION_SPEED_R) + save_pos.y * cos(ROTATION_SPEED_R);

	// 	//Rotate the camera plane
	// 	data->player.camera_plane.x = save_plane.x * cos(ROTATION_SPEED_R) - save_plane.y * sin(ROTATION_SPEED_R);
	// 	data->player.camera_plane.y = save_plane.x * sin(ROTATION_SPEED_R) + save_plane.y * cos(ROTATION_SPEED_R);
		
	// 	printf(YELLOW"Rotando %f grados (right)\n" RESET, ROTATION_SPEED_R);
	// 	data->player.angle -= transform_angle(ROTATION_SPEED_R);
	// 	draw_all(data);
	// }
	// else if ( mlx_is_key_down(data->display.mlx, MLX_KEY_RIGHT)  ||  mlx_is_key_down(data->display.mlx, MLX_KEY_E) )
	// {
	// 	//Rotate the direction vector
	// 	data->player.dir_vector.x = save_pos.x * cos(-ROTATION_SPEED_R) - save_pos.y * sin(-ROTATION_SPEED_R);
	// 	data->player.dir_vector.y = save_pos.x * sin(-ROTATION_SPEED_R) + save_pos.y * cos(-ROTATION_SPEED_R);

	// 	//Rotate the camera plane
	// 	data->player.camera_plane.x = save_plane.x * cos(-ROTATION_SPEED_R) - save_plane.y * sin(-ROTATION_SPEED_R);
	// 	data->player.camera_plane.y = save_plane.x * sin(-ROTATION_SPEED_R) + save_plane.y * cos(-ROTATION_SPEED_R);

	// 	printf(YELLOW"Rotando %f grados (right)\n" RESET, ROTATION_SPEED);
	// 	data->player.angle += transform_angle(ROTATION_SPEED_R);
	// 	draw_all(data);
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
