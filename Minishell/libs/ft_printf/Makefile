# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 15:30:31 by mtrautne          #+#    #+#              #
#    Updated: 2023/05/16 20:47:10 by mtrautne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# only commented on functional changes compared to the libft Makefile.

NAME = printf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = 	ft_printf.c ft_char.c ft_decint.c ft_hex.c ft_perc.c ft_pointer.c \
		ft_str.c ft_unsigned.c
		
OBJS = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $(SRCS)

all: $(NAME)

$(NAME): $(OBJS)

clean:
	@rm -f $(OBJS)
	
fclean:
	@rm -f $(OBJS)

re: fclean all

.PHONY: all clean fclean re