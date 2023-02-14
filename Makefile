# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 17:35:32 by bgannoun          #+#    #+#              #
#    Updated: 2023/02/14 18:07:57 by bgannoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf
OBJ		=	$(SRC:.c=.o)

SRC = srcs/main.c \
	srcs/map_checker.c \
	srcs/path_checker.c \
	srcs/get_next_line.c \
	srcs/get_next_line_utils.c \
	srcs/extra.c \
	srcs/ft_split.c \
	srcs/read_map.c \
	srcs/more_fun.c

archives = ft_printf/libftprintf.a \

$(NAME): $(OBJ)
	cd ft_printf && make
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(archives)

all: $(NAME)

clean:
	cd ft_printf && make clean
	$(RM) $(OBJ)

fclean: clean
	cd ft_printf && make fclean
	$(RM) $(NAME)

re: fclean all
	cd ft_printf && make re