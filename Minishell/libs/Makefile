# only commented on functional changes compared to the libft Makefile.

NAME = lib42.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft.a

LFT_DIR = ./libft/
PF_DIR = ./ft_printf/
GNL_DIR = ./get_next_line/

LIBFT_OBJ = $(LFT_DIR)ft_calloc.o $(LFT_DIR)ft_isdigit.o $(LFT_DIR)ft_memcpy.o $(LFT_DIR)ft_strdup.o $(LFT_DIR)ft_strncmp.o  \
ft_toupper.o $(LFT_DIR)ft_isalnum.o $(LFT_DIR)ft_isprint.o $(LFT_DIR)ft_memmove.o $(LFT_DIR)ft_strlcat.o $(LFT_DIR)ft_strnstr.o \
ft_atoi.o $(LFT_DIR)ft_isalpha.o $(LFT_DIR)ft_memchr.o $(LFT_DIR)ft_memset.o $(LFT_DIR)ft_strlcpy.o $(LFT_DIR)ft_strrchr.o \
ft_bzero.o $(LFT_DIR)ft_isascii.o $(LFT_DIR)ft_memcmp.o $(LFT_DIR)ft_strchr.o $(LFT_DIR)ft_strlen.o $(LFT_DIR)ft_tolower.o \
ft_substr.o $(LFT_DIR)ft_strjoin.o $(LFT_DIR)ft_strtrim.o $(LFT_DIR)ft_split.o $(LFT_DIR)ft_itoa.o $(LFT_DIR)ft_strmapi.o \
ft_striteri.o $(LFT_DIR)ft_putchar_fd.o $(LFT_DIR)ft_putstr_fd.o $(LFT_DIR)ft_putendl_fd.o $(LFT_DIR)ft_putnbr_fd.o

PF_OBJ = $(PF_DIR)ft_printf.o $(PF_DIR)ft_char.o $(PF_DIR)ft_decint.o $(PF_DIR)ft_hex.o \
		$(PF_DIR)ft_perc.o $(PF_DIR)ft_pointer.o $(PF_DIR)ft_str.o $(PF_DIR)ft_unsigned.o

GNL_OBJ = $(GNL_DIR)get_next_line_bonus.o $(GNL_DIR)get_next_line_utils_bonus.o

all: $(NAME)

$(NAME): $(LIBFT) gnl printf
	@cp $(LFT_DIR)libft.a ./libft_cpy.a
	@mv libft_cpy.a $(NAME)
	@ar -rcs $(NAME) $(PF_OBJ) $(GNL_OBJ)

$(LIBFT): 
	@make -C $(LFT_DIR)

gnl: 
	@make -C $(GNL_DIR)

printf: 
	@make -C $(PF_DIR)

clean:
	@make clean -C $(LFT_DIR)
	@make clean -C $(PF_DIR)
	@make clean -C $(GNL_DIR)
	
fclean:
	@rm -f $(NAME)
	@make fclean -C $(LFT_DIR)
	@make fclean -C $(PF_DIR)
	@make fclean -C $(GNL_DIR)

re: fclean all

.PHONY: all clean fclean re gnl printf 