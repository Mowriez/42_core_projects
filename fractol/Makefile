# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 14:54:43 by mtrautne          #+#    #+#              #
#    Updated: 2023/01/14 19:46:00 by mtrautne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
#-fsanitize=address

LIBFT_DIR = ./inc/libft/
LIBFT = $(LIBFT_DIR)libft.a

MLX_DIR = ./inc/mlx/
MLX = $(MLX_DIR)libmlx.a

OBJS = $(SRCS:%.c=%.o)

SRCS_DIR = ./src/
SRCS =	$(SRCS_DIR)fractol.c \
		$(SRCS_DIR)user_input_check.c \
		$(SRCS_DIR)image_processing.c \
		$(SRCS_DIR)colors.c \
		$(SRCS_DIR)mandelbrot.c \
		$(SRCS_DIR)julia.c \
		$(SRCS_DIR)std_vars.c \
		$(SRCS_DIR)input_processing_keyboard.c \
		$(SRCS_DIR)input_processing_mouse.c \
		$(SRCS_DIR)burning_ships.c

HDRS_DIR = ./inc/headers/

#compile objs with -I to include directories with header files
HDRS = -I$(HDRS_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

#compile executable with -L/-l to include directories with libraries/libraries
#themselves.
LIBS = -L$(LIBFT_DIR) -L$(MLX_DIR) -lft -lmlx -lm -framework OpenGL \
-framework AppKit

#compiles source files without linking. Is used to only update the source files
#neccessary. If you would compile all the .c files everytime one of them
#changes, your Makefile would be slower.

%.o: %.c
	$(CC) $(CFLAGS) $(HDRS) -c $^ -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

Bonus:

#mlx clean removes the mlx archive, not just objects. I changed that.
clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(MLX_DIR)

leaks:
	leaks --atExit -- ./$(NAME) 1200 Mandelbrot

norminette:
	@norminette $(SRCS)
	@make norminette -C $(LIBFT_DIR) 

re: fclean all

refast:
	rm -f $(OBJS)
	rm -f $(NAME)
	make all

.PHONY: all clean fclean re refast leaks norminette bonus