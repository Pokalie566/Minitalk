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

INCS = -I ./includes

SRC_PATH = src/
OBJ_PATH = obj/

SRCS = ft_printf.c \
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

OBJS := $(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))
SRCS := $(addprefix $(SRC_PATH), $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	ar -r $@ $?

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
