# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrautne <mtrautne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 20:29:51 by mtrautne          #+#    #+#              #
#    Updated: 2023/07/19 18:14:14 by mtrautne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex00

SRCS =	ClapTrap.cpp \
		main.cpp

OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
