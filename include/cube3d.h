/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 22:27:07 by albartol          #+#    #+#             */
/*   Updated: 2024/07/13 15:55:48 by flopez-r         ###   ########.fr       */
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
# define P_SIZE 64
// # define SPEED 10

# define PLAYER_COL YELLOW
# define WALL_COL GREEN

typedef struct s_game		t_game;
typedef struct s_scene		t_scene;
typedef struct s_scene_file	t_scene_file;
typedef struct s_display	t_display;

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
};

struct s_display
{
	mlx_t		*mlx;
	mlx_image_t	*frames[2];
	int32_t		width;
	int32_t		height;
};

struct s_game
{
	t_scene_file	file;
	t_scene			scene;
	t_display		display;
};

int		read_scene_file(t_scene_file *scene_info, const char *file_path);
int		extract_scene_info(t_scene_file *scene_info);
int		check_scene_info(t_scene_file *scene_info, t_scene *scene);

//Utils
void	free_scene_info(t_scene_file *info);

//Grafics part
int		start_grafics(t_game *data);

#endif