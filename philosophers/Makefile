# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 17:11:49 by mtrautne          #+#    #+#              #
#    Updated: 2023/04/04 20:23:27 by mtrautne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror 
#-g -fsanitize=address

OBJ = $(SRC:%.c=%.o)

SRC_NODIR =	init_helpers.c \
			init.c \
			input_processing.c \
			main.c \
			messages.c \
			misc_helpers.c \
			routine_helpers.c \
			routines.c \
			timekeeper.c

HDR = ./inc/philo.h

SRC = $(addprefix ./src/,$(SRC_NODIR))

#compile source files without linking. Is used to only update the source files
#neccessary. If you would compile all the .c files everytime one of them
#changes, your Makefile would be slower.
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJ) $(HDR)
	$(CC) $(CFLAGS) $(OBJ) -pthread -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

# prevents rules from beeing considered files and therefore prohibits
# errors with filenames that are the same as the rules
.PHONY: all clean fclean re