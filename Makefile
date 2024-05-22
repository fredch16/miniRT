# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 13:14:19 by fcharbon          #+#    #+#              #
#    Updated: 2024/05/22 19:26:08 by fcharbon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := gtx1050ti
CC := gcc
CFLAGS := -Wall -Werror -Wextra
SRCS := src/rtx.c \
		src/vector_utils.c \
		src/colour_utils.c \
		src/mlx_utils.c \
		src/drawing.c \
		src/matrix_utils.c

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
