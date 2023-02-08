# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 15:30:31 by mtrautne          #+#    #+#              #
#    Updated: 2022/07/25 18:52:47 by mtrautne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# only commented on functional changes compared to the libft Makefile.

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFTDIR = ./libft

LIBFT = ./libft/libft.a

SRCS = 	ft_printf.c ft_char.c ft_decint.c ft_hex.c ft_perc.c ft_pointer.c \
		ft_str.c ft_unsigned.c
		
OBJS = $(SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c $(SRCS)

all: $(NAME)

# make -C: Change to directory dir before read or doing anything else.
$(NAME): $(OBJS)
	@make -C $(LIBFTDIR)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFTDIR)
	
fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re