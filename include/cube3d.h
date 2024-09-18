/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 22:27:07 by albartol          #+#    #+#             */
/*   Updated: 2024/09/18 16:28:23 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

// close, read, write
# include <unistd.h>

// malloc, free, exit
# include <stdlib.h>

// printf, perror
# include <stdio.h>

// errno
# include <errno.h>

// strerror
# include <string.h>

// open
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

// all functions
# include <math.h>

// all functions
# include <MLX42.h>

//Bool values
#include <stdbool.h>

# include <libft.h>

# include <utils.h>

# define MAX_LINES SHRT_MAX

# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define CYAN "\033[0;96m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define YELLOW "\033[0;93m"
# define RESET "\033[0m"
# define SPEED 6
# define VISIBILITY 100

# define PLAYER_COL YELLOW
# define WALL_COL GREEN

typedef struct s_game		t_game;
typedef struct s_scene		t_scene;
typedef struct s_scene_file	t_scene_file;
typedef struct s_display	t_display;
typedef struct s_grafics	t_grafics;
typedef	struct s_player		t_player;

//Raycast
typedef struct s_dda		t_dda;
typedef struct s_cords_i 	t_cords_i;
typedef struct s_cords_d 	t_cords_d;

struct s_scene_file
{
	t_list	*file_content;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*floor_color;
	char	*celling_color;
	char	**map;
};

struct s_scene
{
	mlx_texture_t	*north_texture;
	mlx_texture_t	*south_texture;
	mlx_texture_t	*west_texture;
	mlx_texture_t	*east_texture;
	uint32_t		floor_color;
	uint32_t		celling_color;
	size_t			map_width;
	size_t			map_height;
	size_t			player_x;
	size_t			player_y;
	int				angle;
};

struct s_display
{
	mlx_t		*mlx;
	mlx_image_t	*frames[2];
	mlx_image_t	*map;
};

//Raycast
struct s_cords_i
{
	int	x;
	int	y;
};

struct s_cords_d
{
	double	x;
	double	y;
};
struct s_dda
{
	t_cords_d 		origin;			// Initial position
	t_cords_d		v_dir;			// Initial direction vector
	t_cords_d		camera_plane;	// Plano de camara del jugador --> the FOV is 2 * atan(0.66/1.0)=66°
	t_cords_d 		ray_dir;		// La dirección del rayo
	double			camera_x;

	// DDA DATA
	t_cords_d		delta_dist;		//Razon para calcular la hipotenusa
	t_cords_d		side_dist;		//Distancia inicial de la hipotenusa de x e y
	t_cords_d		step;			//Pasos a tomar en x e y
	int				side;			//0 for X and 1 for Y
	t_cords_i		map_pos;

	//For Draw
	double	x_hit;
	mlx_texture_t	*texture;
};

struct s_player
{
	t_cords_d	pos;
	double		move_y;
	float		angle;
	t_cords_d	camera_plane;
	t_cords_d	dir_vector;
};

struct s_game
{
	t_scene_file	file;
	t_scene			scene;
	t_display		display;
	t_player		player;
	int				draw;
	int				mouse;
};



int		read_scene_file(t_scene_file *scene_info, const char *file_path);
int		extract_scene_info(t_scene_file *scene_info);
int		check_scene_info(t_game *data);

//Utils
void	free_scene_info(t_scene_file *info);
int		free_and_exit(t_game *data, int exit);
void	print_map(char **map);

//Ray casting
int		raycast(t_game *data);
int		preload_textures(t_game *data);

//Grafics part
// void	key_events(mlx_key_data_t keydata, void* param);
// void	key_events(void *param);
// int		start_grafics(t_game *data);
// void	movement(void *param);

// float	convert_to_radian(float number);
// int		put_map(char **map, t_display *display);
// int		draw_line(t_game *data, size_t x1, size_t y1, size_t x2, size_t y2);
int		put_map(char **map, t_display *display, mlx_image_t	*wall);
void	fill_color(mlx_image_t *img, uint32_t r, uint32_t g, uint32_t b, uint32_t t);


#endif