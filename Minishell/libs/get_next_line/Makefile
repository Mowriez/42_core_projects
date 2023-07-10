# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 12:21:54 by mtrautne          #+#    #+#              #
#    Updated: 2023/05/16 20:47:27 by mtrautne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $(SRC)

all: $(NAME)

$(NAME): $(OBJ)

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re