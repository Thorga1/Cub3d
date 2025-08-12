# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tordner <tordner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 15:28:00 by tordner           #+#    #+#              #
#    Updated: 2025/08/12 21:01:28 by tordner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3d

OS := $(shell uname)

SRC_DIR := srcs
OBJ_DIR := objs

SRCS := $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

CC := cc
CFLAGS := -Wall -Wextra -Werror -Iincludes -g -MMD -MP

ifeq ($(OS), Linux)
	MLX_PATH := ./mlx_linux
	MLX := $(MLX_PATH)/libmlx.a
	CFLAGS += -Imlx_linux
	LIBS := -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
else
	MLX_PATH := ./mlx
	MLX := $(MLX_PATH)/libmlx.a
	CFLAGS += -Imlx
	LIBS := -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(OBJS) $(LIBS) -o $@

# Compile .c -> .o into objs/, creating subdirs as needed
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_PATH)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re