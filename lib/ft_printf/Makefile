# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeboose <adeboose@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 14:55:27 by adeboose          #+#    #+#              #
#    Updated: 2024/10/15 15:56:45 by adeboose         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
CC = cc
NAME = libftprintf.a

SRC = ft_printf.c \
      ft_formats.c \
      ft_printchar.c \
      ft_printstr.c \
      ft_print_ptr.c \
      ft_printnbr.c \
      ft_print_unsigned.c \
      ft_print_hex.c \
      ft_printpercent.c \
      ft_putstr.c \
      ft_strlen.c \
      ft_putchar.c \
      ft_itoa.c \
      ft_calloc.c \
      ft_memset.c \

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
