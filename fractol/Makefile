# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 14:54:43 by mtrautne          #+#    #+#              #
#    Updated: 2023/02/25 11:41:14 by mtrautne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS =  -O3 -std=gnu89

# --- Operating System & MLX Setup ---
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux)
    MLX_DIR = ./inc/mlx/minilibx-linux
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
else
    MLX_DIR = ./inc/mlx/minilibx_opengl_20191021
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

MLX = $(MLX_DIR)/libmlx.a

# --- Libft Setup ---
LIBFT_DIR = ./inc/libft/
LIBFT = $(LIBFT_DIR)libft.a

# --- Sources & Objects ---
SRCS_DIR = ./src/
SRCS =  $(SRCS_DIR)fractol.c \
        $(SRCS_DIR)user_input_check.c \
        $(SRCS_DIR)image_processing.c \
        $(SRCS_DIR)colors.c \
        $(SRCS_DIR)mandelbrot.c \
        $(SRCS_DIR)julia.c \
        $(SRCS_DIR)std_vars.c \
        $(SRCS_DIR)input_processing_keyboard.c \
        $(SRCS_DIR)input_processing_mouse.c \
        $(SRCS_DIR)burning_ships.c

OBJS = $(SRCS:%.c=%.o)

# --- Includes & Libraries ---
HDRS_DIR = ./inc/headers/
HDRS = -I$(HDRS_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
LIBS = -L$(LIBFT_DIR) -lft $(MLX_FLAGS)

# --- Rules ---
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(HDRS) -c $< -o $@

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)
	@echo "$(BLU)libmlx.a built successfully!$(RES)"

bonus: all

clean:
	rm -f $(OBJS)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	-@$(MAKE) clean -C $(MLX_DIR)

re: fclean all

refast:
	rm -f $(OBJS)
	rm -f $(NAME)
	@$(MAKE) all

leaks:
	leaks --atExit -- ./$(NAME) 1200 Mandelbrot

norminette:
	@norminette $(SRCS)
	@$(MAKE) norminette -C $(LIBFT_DIR)

.PHONY: all clean fclean re refast leaks norminette bonus