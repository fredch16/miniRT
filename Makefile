# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 12:10:35 by atyurina          #+#    #+#              #
#    Updated: 2024/09/12 13:47:51 by atyurina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := rtx2050
CC := gcc
CFLAGS := -Wall -Werror -Wextra -g
SRCS := src/rtx.c \
		src/tuple_utils.c \
		src/tuple_utils2.c \
		src/tuple_utils3.c \
		src/colour_utils.c \
		src/mlx_utils.c \
		src/matrix_utils.c src/matrix_utils_2.c src/matrix_set.c src/matrix_rotation.c\
		src/matrix_submatrix.c src/matrix_determinant.c src/matrix_multiplication.c \
		src/ray_intersect_utils.c \
		src/lists.c \
		src/ray_transform.c \
		src/object_normals.c \
		src/lighting.c \
		src/camera.c \
		src/intersect_cy.c \
		src/parser_read.c src/parser_check.c src/parser_check_element.c \
		src/parser_set_data.c \
		src/parser_check_dbl.c src/parser_check_rgb.c src/parser_get_idx.c \
		src/parser_check_vec.c \
		src/parser_check_xyz.c src/parser_set_obj.c src/parser_fill_obj.c \
		src/parser_obj_conversion.c \
		src/memory_free.c

OBJ_DIR := obj/
OBJ := $(SRCS:src/%.c=$(OBJ_DIR)%.o)
INCLUDE := includes/rtx.h

$(OBJ_DIR)%.o: src/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lft -Lincludes/libft -Lincludes/mlx_linux -lm -lmlx_Linux -lXext -lX11 -lz
	$(CC) $(OBJ) -o $(NAME) -lft -Lincludes/libft -Lincludes/mlx_linux -lm -lmlx_Linux -lXext -lX11 -lz

clean:
	/bin/rm -rf $(OBJ_DIR)
fclean: clean
	/bin/rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
