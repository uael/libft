# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:52:36 by alucas-           #+#    #+#              #
#    Updated: 2017/11/15 18:48:45 by null             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT = libft
NAME = $(PROJECT).a

NOC=\033[0m
OKC=\033[94;1m
ERC=\033[31m
WAC=\033[33m

CC = gcc
CFLAGS += -Wall -Werror -Wextra

SRC_PATH = ./src/
INC_PATH = ./include/
OBJ_PATH = ./obj/
OBJS_PATH = ./obj/ ./obj/ctype/ ./obj/io ./obj/lib ./obj/mem ./obj/string

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

SRC_NAME += \
	ctype/ft_isalnum.c \
	ctype/ft_isalpha.c \
	ctype/ft_isascii.c \
	ctype/ft_isdigit.c \
	ctype/ft_islower.c \
	ctype/ft_isprint.c \
	ctype/ft_isspace.c \
	ctype/ft_isupper.c \
	ctype/ft_tolower.c \
	ctype/ft_toupper.c \
	io/ft_putchar.c \
	io/ft_putchar_fd.c \
	io/ft_putendl.c \
	io/ft_putendl_fd.c \
	io/ft_putnbr.c \
	io/ft_putnbr_fd.c \
	io/ft_putstr.c \
	io/ft_putstr_fd.c \
	lib/ft_atoi.c \
	lib/ft_digits.c \
	lib/ft_itoa.c \
	lib/ft_itoa_base.c \
	mem/ft_calloc.c \
	mem/ft_malloc.c \
	mem/ft_realloc.c \
	string/ft_bzero.c \
	string/ft_memccpy.c \
	string/ft_memchr.c \
	string/ft_memcmp.c \
	string/ft_memcpy.c \
	string/ft_memmove.c \
	string/ft_memrcpy.c \
	string/ft_memset.c \
	string/ft_strcat.c \
	string/ft_strchr.c \
	string/ft_strclr.c \
	string/ft_strcmp.c \
	string/ft_strcpy.c \
	string/ft_strdup.c \
	string/ft_strlcat.c \
	string/ft_strlen.c \
	string/ft_strnbr.c \
	string/ft_strncat.c \
	string/ft_strncmp.c \
	string/ft_strncpy.c \
	string/ft_strnlen.c \
	string/ft_strnstr.c \
	string/ft_strrchr.c \
	string/ft_strstr.c

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@echo -n =

$(NAME): $(OBJ)
	@echo "$(OKC)$(PROJECT): Creating the library$(NOC)"
	@ar -rc $(NAME) $?
	@echo "$(OKC)$(PROJECT): Generating the index$(NOC)"
	@ranlib $(NAME)
	@echo "$(OKC)$(PROJECT): $(PROJECT) ready$(NOC)"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(WAC)$(PROJECT): Removing obj path: '$(OBJ_PATH)'$(NOC)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(WAC)$(PROJECT): Removing '$(NAME)'$(NOC)"

re: fclean all

.PHONY: clean fclean re
