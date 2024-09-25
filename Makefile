# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 16:58:28 by albartol          #+#    #+#              #
#    Updated: 2024/09/25 14:57:44 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc

INCLUDE := -Iinclude -Ilib/libft/include -Ilib/MLX42/include/MLX42

# CFLAGS := -Wall -Wextra -Werror -O3 -g3 $(INCLUDE)
CFLAGS := -Wall -Wextra -Werror -O3 -g3 $(INCLUDE) -fsanitize=address

LIBFT := lib/libft/libft.a
LIBFT_DIR := lib/libft
FT := -L$(LIBFT_DIR) -lft
MKDIR := mkdir -p
HEADERS :=	check_scene.h \
			cube3d.h \
			extract_scene.h \
			raycast.h \
			utils.h
			
MLX42 := lib/MLX42/build/libmlx42.a
MLX42_DIR := lib/MLX42
MLX42_BUILD := lib/MLX42/build
MLX := -L$(MLX42_BUILD) -lmlx42 -ldl -lglfw -pthread -lm

# UNAME := $(shell uname)
# ifeq ($(UNAME), Darwin)
# 	MLX := -lmlx -framework OpenGL -framework AppKit
# endif

LIBS := $(FT) $(MLX)

SRC_DIR			:= src
OBJ_DIR			:= obj
PARSE_DIR		:= parse
GAME_LOOP_DIR	:= game_loop
UTILS_DIR		:= utils
RAYCAST_DIR		:= raycast
LIB_DIR			:= include

RED := \033[0;91m
GREEN := \033[0;92m
CYAN := \033[0;96m
BLUE := \033[0;34m
PURPLE := \033[0;35m
YELLOW := \033[0;93m
RESET := \033[0m


# ---------- MANDATORY ----------
SRC :=	main.c

# Parse
CHK :=		check_colors.c \
			check_elements.c \
			check_inside_walls.c \
			check_map.c \
			check_scene_info.c \
		
EXT :=		extract_elements.c \
			extract_map.c \
			extract_scene_info.c \
			read_scene_file.c

PARSE := $(CHK) $(EXT)

RAYCAST	:=	dda.c \
			render.c \
			draw_img.c \
			init_ray_values.c \
			draw_map.c \
			preload_textures.c \
			raycast.c

UTIL :=		in_range.c \
			print_error.c \
			create_color.c \
			check_file_type.c \
			exit_msg.c \
			free_scene_info.c \
			free_and_exit.c \
			print_map.c

GAME_LOOP :=	game_loop.c \
				keys_check.c \
				mouse_pov.c \
				rotate_lr.c \
				rotate_ud.c

# Add prefixes:
GAME_LOOP	:= $(addprefix $(GAME_LOOP_DIR)/, $(GAME_LOOP))
UTIL 		:= $(addprefix $(UTILS_DIR)/, $(UTIL))
PARSE		:= $(addprefix $(PARSE_DIR)/, $(PARSE))
RAYCAST		:= $(addprefix $(RAYCAST_DIR)/, $(RAYCAST))
HEADERS		:= $(addprefix $(LIB_DIR)/, $(HEADERS))

SOURCES		:= $(SRC) $(PARSE) $(UTIL) $(RAYCAST) $(GAME_LOOP)
OBJS		:= $(SOURCES:%.c=$(OBJ_DIR)/%.o)

SRCS		:= $(addprefix $(SRC_DIR)/, $(SOURCES))

NAME		:= cube3D
# ---------- MANDATORY END ----------

# ---------- BONUS ----------
BNS :=	

BNS_SOURCES := $(BNS)

BNS_SRCS := $(addprefix $(SRC_DIR)/, $(BNS_SOURCES))

BNS_OBJS := $(BNS_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

BONUS := cube3D_bonus
# ---------- BONUS END ----------

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX42)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@
	@echo "$(GREEN)Program $(NAME) created ✅$(RESET)"

bonus: $(OBJ_DIR) $(BONUS)

$(BONUS): $(BNS_OBJS) $(LIBFT) $(MLX42)
	$(CC) $(CFLAGS) $(BNS_OBJS) $(LIBS) -o $@
	@echo "$(GREEN)Program $(BONUS) created ✅$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@echo "$(YELLOW)Compiling...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@echo "$(YELLOW)Creating object directories...$(RESET)"
	$(MKDIR) $(OBJ_DIR)
	$(MKDIR) $(OBJ_DIR)/$(PARSE_DIR)
	$(MKDIR) $(OBJ_DIR)/$(UTILS_DIR)
	$(MKDIR) $(OBJ_DIR)/$(RAYCAST_DIR)
	$(MKDIR) $(OBJ_DIR)/$(GAME_LOOP_DIR)

$(LIBFT):
	@echo "$(YELLOW)Compiling libft...$(RESET)"
	$(MAKE) -j -C $(LIBFT_DIR)

$(MLX42):
	@echo "$(YELLOW)Compiling MLX42...$(RESET)"
	cmake -S $(MLX42_DIR) -B $(MLX42_BUILD)
	$(MAKE) -j -C $(MLX42_BUILD)

clean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(MLX42_BUILD)
	rm -rf $(OBJ_DIR)

# clean:
# 	$(MAKE) fclean -C $(LIBFT_DIR)
# 	# $(MAKE) clean -C $(MLX42_BUILD)
# 	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus