# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 17:35:32 by bgannoun          #+#    #+#              #
#    Updated: 2023/01/13 20:17:59 by bgannoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

OBJ = test.c

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean: 
	rm -rf $(NAME)