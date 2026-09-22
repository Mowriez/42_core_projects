# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 17:29:15 by mtrautne          #+#    #+#              #
#    Updated: 2024/01/01 22:13:48 by mtrautne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g

NAME = RPN

INC_DIR =	./inc
SRC_DIR =	./src
OBJ_DIR =	./obj

CPPFILES =	main \
						MyExceptions \
						RPN

HEADER =		MyExceptions \
						RPN

INCL =	$(addsuffix .hpp, $(addprefix $(INC_DIR)/, $(HEADER)))
SRCS = 	$(addsuffix .cpp, $(addprefix $(SRC_DIR)/, $(CPPFILES)))
OBJS = 	$(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(CPPFILES)))

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCL) | $(OBJ_DIR)
	$(CXX) $(FLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $^ -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
