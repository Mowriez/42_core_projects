# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 15:53:47 by mtrautne          #+#    #+#              #
#    Updated: 2023/03/18 19:09:22 by mtrautne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror
#-fsanitize=address -O3

LIBFT = $(LIBFT_DIR)libft.a
OBJ = $(SRC:%.c=%.o)

SRC_NOPREFIX =	pipex.c \
				array_modification.c \
				exec_helpers.c \
				input_error_free_helpers.c \
				struct_helpers.c


SRC = $(addprefix $(SRC_DIR), $(SRC_NOPREFIX))

LIBFT_DIR = ./src/libft/
HDR_DIR = ./inc/
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
	@$(CC) $(CFLAGS) $(HDR) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJ) $(LIB) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

# prevents rules from beeing considered files and therefore prohibits
# errors with filenames that are the same as the rules
.PHONY: all clean fclean re