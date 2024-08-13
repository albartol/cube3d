# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 16:58:28 by albartol          #+#    #+#              #
#    Updated: 2024/08/13 16:20:30 by flopez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc

INCLUDE := -Iinclude -Ilib/libft/include -Ilib/MLX42/include/MLX42

CFLAGS := -Wall -Wextra -Werror -O2 $(INCLUDE)
# CFLAGS := -Wall -Wextra -Werror -ggdb $(INCLUDE) -fsanitize=address

LIBFT := lib/libft/libft.a
LIBFT_DIR := lib/libft
FT := -L$(LIBFT_DIR) -lft

MLX42 :=	lib/MLX42/build/libmlx42.a
MLX42_DIR := lib/MLX42
MLX42_BUILD := lib/MLX42/build
MLX :=	-L$(MLX42_BUILD) -lmlx42 -ldl -lglfw -pthread -lm

# UNAME := $(shell uname)
# ifeq ($(UNAME), Darwin)
# 	MLX := -lmlx -framework OpenGL -framework AppKit
# endif

LIBS := $(FT) $(MLX)

SRC_DIR	:= src
OBJ_DIR	:= obj

RED := \033[0;91m
GREEN := \033[0;92m
CYAN := \033[0;96m
BLUE := \033[0;34m
PURPLE := \033[0;35m
YELLOW := \033[0;93m
RESET := \033[0m

# ---------- MANDATORY ----------
SRC :=	main.c \
		read_scene_file.c
		
EXT := extract_scene_info.c \
		extract_elements.c \
		extract_map.c

CHK := check_scene_info.c \
		check_elements.c \
		check_map.c \
		check_colors.c

# GRAFICS := start_grafics.c \
# 			put_map.c \
# 			fill_color.c\
# 			movement.c

RAYCAST	:=	raycast.c \
			dda.c \
			key_events.c

UTIL := print_error.c \
		in_range.c \
		create_color.c \
		check_file_type.c \
		exit_msg.c \
		free_scene_info.c \
		free_and_exit.c
		
SOURCES := $(SRC) $(EXT) $(CHK) $(UTIL) $(RAYCAST)

SRCS := $(addprefix $(SRC_DIR)/, $(SOURCES))

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME := cube3D
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

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(YELLOW)Compiling...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@echo "$(YELLOW)Creating object directories...$(RESET)"
	mkdir -p $(OBJ_DIR)

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