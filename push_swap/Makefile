# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 15:53:47 by mtrautne          #+#    #+#              #
#    Updated: 2023/02/20 12:23:30 by mtrautne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
#-fsanitize=address -O3

LIBFT = $(LIBFT_DIR)/libft.a
OBJ = $(SRC:%.c=%.o)

SRC_NOPREFIX =	push_swap.c \
				array_list_build.c \
				helper_fcts.c \
				input_check.c \
				list_manipulation.c \
				radix_sort.c \
				ps_operations_1.c \
				ps_operations_2.c \
				small_stack_sort_1.c \
				small_stack_sort_2.c

SRC = $(addprefix $(SRC_DIR), $(SRC_NOPREFIX))

LIBFT_DIR = ./inc/libft/
HDR_DIR = ./inc/headers/
SRC_DIR = ./src/

#compile objs with -I to include directories with header files
HDR = -I$(HDR_DIR) -I$(LIBFT_DIR)

#compile executable with -L/-l to include directories with libraries/libraries themselves.
#Libraries MUST be compiled after objects!!!! -L can be in front of objects.
LIB = -L$(LIBFT_DIR) -lft

#compile source files without linking. Is used to only update the source files
#neccessary. If you would compile all the .c files everytime one of them
#changes, your Makefile would be slower.
%.o: %.c
	$(CC) $(CFLAGS) $(HDR) -c $^ -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

leaks:
	leaks --atExit -- ./$(NAME)

re: fclean all

# prevents rules from beeing considered files and therefore prohibits
# errors with filenames that are the same as the rules
.PHONY: all clean fclean re