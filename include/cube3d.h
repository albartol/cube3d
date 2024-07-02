/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 22:27:07 by albartol          #+#    #+#             */
/*   Updated: 2024/07/02 12:27:58 by flopez-r         ###   ########.fr       */
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
# include "../lib/minilibx-linux/mlx.h"

# include "../lib/libft/include/libft.h"

# include "utils.h"

# define MAX_LINES SHRT_MAX

# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define CYAN "\033[0;96m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define YELLOW "\033[0;93m"
# define RESET "\033[0m"

enum e_keys
{
	UP = 126,
	DOWN = 125,
	RIGHT = 124,
	LEFT = 123,
	W_UP = 13,
	S_DOWN = 1,
	D_RIGHT = 2,
	A_LEFT = 0,
	END = 53,
	Q_END = 0,
	WSL_LEFT = 65361,
	WSL_UP = 65362,
	WSL_RIGTH = 65363,
	WSL_DOWN = 65364,
	WSL_END = 65307
};

enum e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_game		t_game;
typedef struct s_scene		t_scene;
typedef struct s_textures	t_textures;
typedef struct s_scene_file	t_scene_file;
typedef struct s_image		t_image;
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

struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
};

struct s_textures
{
	t_image	north_texture;
	t_image	south_texture;
	t_image	west_texture;
	t_image	east_texture;
};

struct s_scene
{
	t_textures	textures;
	int			floor_color;
	int			celling_color;
};

struct s_display
{
	void	*mlx_ptr;
	void	*win_ptr;
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

#endif