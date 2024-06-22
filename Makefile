# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 16:58:28 by albartol          #+#    #+#              #
#    Updated: 2024/06/22 18:46:40 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc

INCLUDE := -Iinclude

# CFLAGS := -Wall -Wextra -Werror -O2 $(INCLUDE)
CFLAGS := -Wall -Wextra -Werror -ggdb $(INCLUDE)

LIBFT := lib/libft/libft.a
LIBFT_DIR := lib/libft
FT := -L$(LIBFT_DIR) -lft

MINILIBX :=	lib/minilibx-linux/libmlx.a
MINILIBX_DIR :=	lib/minilibx-linux
MLX :=	-L$(MINILIBX_DIR) -lmlx

MATH := -lm

LIBS := $(MATH) $(FT) $(MLX)

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
SRC :=	main.c read_scene_file.c

EXT := extract_scene_info.c extract_elements.c extract_map.c

CHK := check_scene_info.c check_elements.c check_map.c check_colors.c

UTIL := print_error.c in_range.c create_color.c

SOURCES := $(SRC) $(EXT) $(CHK) $(UTIL)

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

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@
	@echo "$(GREEN)Program $(NAME) created ✅$(RESET)"

bonus: $(OBJ_DIR) $(BONUS)

$(BONUS): $(BNS_OBJS) $(LIBFT) $(MINILIBX)
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

$(MINILIBX):
	@echo "$(YELLOW)Compiling minilibx-linux...$(RESET)"
	$(MAKE) -j -C $(MINILIBX_DIR)

clean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MINILIBX_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus