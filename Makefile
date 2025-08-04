# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tordner <tordner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 15:28:00 by tordner           #+#    #+#              #
#    Updated: 2025/08/04 21:12:52 by tordner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

OS = $(shell uname)

SRC_DIR = srcs
OBJ_DIR = objs

SRCS =  $(SRC_DIR)/main.c       \
        $(SRC_DIR)/parse.c    \
        $(SRC_DIR)/utils.c    \
        $(SRC_DIR)/ft_split.c    \
        $(SRC_DIR)/data.c    \
        $(SRC_DIR)/line_find_helper.c    \
        $(SRC_DIR)/errors.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = cc -Wall -Wextra -Werror -Iincludes

ifeq ($(OS), Linux)
    MLX_PATH = ./mlx_linux
    MLX = $(MLX_PATH)/libmlx.a
    LIBS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
    CFLAGS = -g -Imlx_linux
else
    MLX_PATH = ./mlx
    MLX = $(MLX_PATH)/libmlx.a
    LIBS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
    CFLAGS = -g -Imlx
endif

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_PATH)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MLX_PATH) clean

re: fclean all

.PHONY: all clean fclean re