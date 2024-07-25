# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 12:10:35 by atyurina          #+#    #+#              #
#    Updated: 2024/07/25 13:45:41 by atyurina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := rtx2050
CC := gcc
CFLAGS := -Wall -Werror -Wextra -g
SRCS := src/rtx.c \
		src/tuple_utils.c \
		src/colour_utils.c \
		src/mlx_utils.c \
		src/drawing.c \
		src/matrix_utils.c src/matrix_utils_2.c src/matrix_set.c src/matrix_rotation.c\
		src/matrix_submatrix.c src/matrix_determinant.c src/matrix_multiplication.c \
		src/ray_intersect_utils.c \
		src/lists.c \
		src/ray_transform.c \
		src/sphere_normal.c \
		src/lighting.c \
		src/camera.c \
		src/parser_read.c src/parser_check.c src/parser_check_element.c

OBJ_DIR := obj/
OBJ := $(SRCS:src/%.c=$(OBJ_DIR)%.o)
INCLUDE := includes/rtx.h

$(OBJ_DIR)%.o: src/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lft -Lincludes/libft -Lincludes/mlx_linux -lm -lmlx_Linux -lXext -lX11 -lz

clean:
	/bin/rm -rf $(OBJ_DIR)
fclean: clean
	/bin/rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
