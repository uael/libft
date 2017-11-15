# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:52:36 by alucas-           #+#    #+#              #
#    Updated: 2017/11/15 17:42:48 by null             ###   ########.fr        #
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

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

SRC_NAME += \
	ft_atoi.o \
	ft_bzero.o \
	ft_digits.o \
	ft_dstdtor.o \
	ft_dstralloc.o \
	ft_dstrappend.o \
	ft_dstrat.o \
	ft_dstrbeg.o \
	ft_dstrend.o \
	ft_dstrgrow.o \
	ft_dstrpop.o \
	ft_dstrpopn.o \
	ft_dstrprepend.o \
	ft_dstrpush.o \
	ft_dstrpushcpy.o \
	ft_dstrpushn.o \
	ft_dstrpushncpy.o \
	ft_dstrsht.o \
	ft_dstrshtn.o \
	ft_dstrunsht.o \
	ft_dstrunshtcpy.o \
	ft_dstrunshtn.o \
	ft_dstrunshtncpy.o \
	ft_isalnum.o \
	ft_isalpha.o \
	ft_isascii.o \
	ft_isdigit.o \
	ft_islower.o \
	ft_isprint.o \
	ft_isspace.o \
	ft_isupper.o \
	ft_itoa.o \
	ft_itoa_base.o \
	ft_lstadd.o \
	ft_lstdel.o \
	ft_lstdelone.o \
	ft_lstiter.o \
	ft_lstmap.o \
	ft_lstnew.o \
	ft_memalloc.o \
	ft_memccpy.o \
	ft_memchr.o \
	ft_memcmp.o \
	ft_memcpy.o \
	ft_memdel.o \
	ft_memmove.o \
	ft_memrcpy.o \
	ft_memrealloc.o \
	ft_memset.o \
	ft_putchar.o \
	ft_putchar_fd.o \
	ft_putendl.o \
	ft_putendl_fd.o \
	ft_putnbr.o \
	ft_putnbr_fd.o \
	ft_putstr.o \
	ft_putstr_fd.o \
	ft_strcat.o \
	ft_strchr.o \
	ft_strclr.o \
	ft_strcmp.o \
	ft_strcpy.o \
	ft_strdel.o \
	ft_strdup.o \
	ft_strequ.o \
	ft_striter.o \
	ft_striteri.o \
	ft_strjoin.o \
	ft_strlcat.o \
	ft_strlen.o \
	ft_strmap.o \
	ft_strmapi.o \
	ft_strnbr.o \
	ft_strncat.o \
	ft_strncmp.o \
	ft_strncpy.o \
	ft_strnequ.o \
	ft_strnew.o \
	ft_strnlen.o \
	ft_strnstr.o \
	ft_strrchr.o \
	ft_strsplit.o \
	ft_strstr.o \
	ft_strsub.o \
	ft_strtrim.o \
	ft_strword.o \
	ft_tolower.o \
	ft_toupper.o

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
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
