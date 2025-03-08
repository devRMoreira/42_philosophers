# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rimagalh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/08 13:23:12 by rimagalh          #+#    #+#              #
#    Updated: 2025/03/08 15:00:20 by rimagalh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
# CFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread
CFLAGS = -g -fsanitize=thread

NAME = philo

SRC = src/main.c \
	src/parse.c \

OBJ = $(SRC:.c=.o)

LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean


fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean


re: fclean all

.PHONY: all clean fclean re
