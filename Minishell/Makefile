# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 22:55:36 by estruckm          #+#    #+#              #
#    Updated: 2023/05/31 14:22:59 by mtrautne         ###   ########.fr        # 
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CCFLAG = -Wall -Werror -Wextra
# -fsanitize=address

SRCS =	minishell.c \
		clean_up_1.c \
		clean_up_2.c \
		main_run_fcts.c \
		\
		parsing/env_init.c \
		parsing/env_utils.c \
		parsing/int_redir.c \
		parsing/int_main.c \
		parsing/int_utils_1.c \
		parsing/int_utils_2.c \
		parsing/int_utils_3.c \
		parsing/lex_check_input_1.c \
		parsing/lex_check_input_2.c \
		parsing/lex_check_input_3.c \
		parsing/lex_expand_input_1.c \
		parsing/lex_expand_input_2.c \
		parsing/lex_expand_input_3.c \
		parsing/lex_main.c \
		parsing/lex_utils_1.c \
		parsing/lex_utils_2.c \
		parsing/par_main.c \
		parsing/visualize_helpers.c \
		\
		builtins/builtin_cd.c \
		builtins/builtin_echo.c \
		builtins/builtin_env.c \
		builtins/builtin_exit.c \
		builtins/builtin_export.c \
		builtins/builtin_export_2.c \
		builtins/builtin_pwd.c \
		builtins/builtin_unset.c \
		builtins/builtins_exe.c \
		builtins/builtins_exe_2.c \
		\
		exe/exe_cmds.c \
		exe/exe_heredoc.c \
		exe/exe_redir.c \
		exe/exe_utils.c \
		exe/signals.c \
		exe/utils.c

D_SRCS = ./srcs/
SRC = $(addprefix $(D_SRCS), $(SRCS))

D_LIB = ./libs/
LIB = $(D_LIB)lib42.a

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o:%.c
	@$(CC) $(CCFLAG) -I $(HOME)/goinfre/.brew/opt/readline/include/ -o $@ -c $<
	@echo "\033[34m$@ built successfully!\033[0m"

$(NAME): $(OBJ) $(LIB)
	@$(CC) $(CCFLAG) $(OBJ) $(LIB) -L $(HOME)/goinfre/.brew/opt/readline/lib/ -lreadline -o $(NAME)
	@make seashell

$(LIB):
	@make -C $(D_LIB)
	@echo "\033[34mlib42 built successfully!\033[0m"

clean:
	@make clean -C $(D_LIB)
	@rm -f $(OBJ)
	@echo "\033[34mcleaned successfully!\033[0m"

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@make fclean -C $(D_LIB)
	@echo "\033[34mfcleaned successfully!\033[0m"

re : fclean all

leaks:
	leaks --atExit -- ./$(NAME)

seashell:
	@echo "\033[1;32m        _.-''|''-._ \033[0m"
	@echo "\033[1;32m     .-'     |     '-. \033[0m"
	@echo "\033[1;32m   .-\       |       /-. \033[0m"
	@echo "\033[1;32m .-'  \      |      /  '-. \033[0m"
	@echo "\033[1;32m \     \ MINISHELL /     / \033[0m"
	@echo "\033[1;32m   \    \  READY  /    / \033[0m"
	@echo "\033[1;32m     \   \   |   /   / \033[0m"
	@echo "\033[1;32m       \  \  |  /  / \033[0m"
	@echo "\033[1;32m     _.- \ \ | / / -._ \033[0m"
	@echo "\033[1;32m    {_______\|/_______} \033[0m"

.PHONY: all clean fclean re seashell