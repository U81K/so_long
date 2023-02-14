# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/23 17:04:27 by bgannoun          #+#    #+#              #
#    Updated: 2022/10/23 19:12:32 by bgannoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a


CC = gcc -Wall -Werror -Wextra -I.

SRC = ft_putchar.c \
        ft_putnbr.c \
        ft_printf.c \
        ft_putstr.c \

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
		$(CC) $(SRC) -c
		ar crs $(NAME) $(OBJ)

all: $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
