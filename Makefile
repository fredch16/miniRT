# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 13:14:19 by fcharbon          #+#    #+#              #
#    Updated: 2024/05/21 15:11:30 by fcharbon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := gtx1050ti
CC := gcc
CFLAGS := -Wall -Werror -Wextra
SRCS := src/rtx.c \
		src/utilities.c \

OBJ := $(SRCS:.c=.o)
INCLUDE := includes/rtx.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lm

clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
