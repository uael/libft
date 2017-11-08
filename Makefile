# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:52:36 by alucas-           #+#    #+#              #
#    Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror -Iinclude
CC = gcc
OBJ = src/ctype/ft_isalnum.o src/ctype/ft_isalpha.o src/ctype/ft_isascii.o \
	src/ctype/ft_isdigit.o src/ctype/ft_islower.o src/ctype/ft_isprint.o \
	src/ctype/ft_isupper.o src/ctype/ft_tolower.o src/ctype/ft_toupper.o \
	src/mem/ft_bzero.o src/mem/ft_memccpy.o src/mem/ft_memchr.o \
	src/mem/ft_memcmp.o src/mem/ft_memcpy.o src/mem/ft_memmove.o \
	src/mem/ft_memset.o \
	src/string/ft_atoi.o src/string/ft_strcat.o src/string/ft_strchr.o \
	src/string/ft_strcmp.o src/string/ft_strcpy.o src/string/ft_strdup.o \
	src/string/ft_strlcat.o src/string/ft_strlen.o src/string/ft_strncat.o \
	src/string/ft_strncmp.o src/string/ft_strncpy.o src/string/ft_strnlen.o	\
	src/string/ft_strnstr.o src/string/ft_strrchr.o src/string/ft_strstr.o

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
