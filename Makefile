# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 13:23:12 by rimagalh          #+#    #+#              #
#    Updated: 2025/03/08 16:51:27 by rimagalh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
# CFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread

NAME = philo

SRC = src/main.c \
	src/parse.c \
	src/utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

sani: CFLAGS += -g -fsanitize=thread
sani: re

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
