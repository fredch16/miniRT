# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 13:14:19 by fcharbon          #+#    #+#              #
#    Updated: 2024/05/22 17:18:20 by fcharbon         ###   ########.fr        #
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

OBJ := $(SRCS:.c=.o)
INCLUDE := includes/rtx.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -Lincludes/libft -Lincludes/mlx_linux -lm -lmlx_Linux -lXext -lX11 -lz

clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
