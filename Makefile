# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 12:10:35 by atyurina          #+#    #+#              #
#    Updated: 2024/06/06 20:05:47 by fcharbon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := gtx1050ti
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
		src/sphere_normal.c

OBJ_DIR := obj/
OBJ := $(SRCS:src/%.c=$(OBJ_DIR)%.o)
INCLUDE := includes/rtx.h

$(OBJ_DIR)%.o: src/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -Lincludes/libft -Lincludes/mlx_linux -lm -lmlx_Linux -lXext -lX11 -lz

clean:
	/bin/rm -rf $(OBJ_DIR)
fclean: clean
	/bin/rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
