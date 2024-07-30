/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:14:48 by flopez-r          #+#    #+#             */
/*   Updated: 2024/07/30 16:30:46 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

float	transform_angle(float angle)
{
	if (angle > 360)
		return (angle - 360);
	if (angle < 0)
		return (angle + 360);
	return (angle);
}

float	convert_to_radian(float number)
{
	return (number * (PI / 180));
}

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

void	movement(void *param)
{
	t_player	*player;
	float		x;
	float		y;

	player = (t_player *)param;
	x = player->x;
	y = player->y;
	if (mlx_is_key_down(player->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(player->mlx);
	//LEFT AND RIGHT
	if (mlx_is_key_down(player->mlx, MLX_KEY_RIGHT))
		player->angle = transform_angle(player->angle - ROTATION_SPEED);
	if (mlx_is_key_down(player->mlx, MLX_KEY_LEFT))
		player->angle = transform_angle(player->angle + ROTATION_SPEED);
	//WASD
	if (mlx_is_key_down(player->mlx, MLX_KEY_W))
	{
		x += cos(convert_to_radian(player->angle)) * SPEED;
		y -= sin(convert_to_radian(player->angle)) * SPEED;
	}
	if (mlx_is_key_down(player->mlx, MLX_KEY_S))
	{
		x -= cos(convert_to_radian(player->angle)) * SPEED;
		y += sin(convert_to_radian(player->angle)) * SPEED;
	}
	if (mlx_is_key_down(player->mlx, MLX_KEY_A))
	{
		x -= sin(convert_to_radian(player->angle)) * SPEED;
		y -= cos(convert_to_radian(player->angle)) * SPEED;
	}
	if (mlx_is_key_down(player->mlx, MLX_KEY_D))
	{
		x += sin(convert_to_radian(player->angle)) * SPEED;
		y += cos(convert_to_radian(player->angle)) * SPEED;
	}
	if (checker(x, y, player->map))
		return ;
	player->x = x;
	player->y = y;
	player->img->instances[0].x = player->x;
	player->img->instances[0].y = player->y;
}

// printf("Pos (%f, %f) --> %f - %f \n", player->x, player->y, (player->angle /
//  (180 * PI)), player->angle);