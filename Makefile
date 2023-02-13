# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 17:35:32 by bgannoun          #+#    #+#              #
#    Updated: 2023/02/13 17:15:29 by bgannoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

OBJ = srcs/main.c \
	srcs/map_checker.c \
	srcs/path_checker.c \
	srcs/get_next_line.c \
	srcs/get_next_line_utils.c \
	srcs/extra.c \
	srcs/ft_split.c

archives = archives/libmlx.a \

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(archives)

all: $(NAME)

clean: 
	rm -rf $(NAME)

re: clean all

# gcc main.c map_checker.c path_checker.c get_next_line.c get_next_line_utils.c 
# ../archives/libft.a ../libmlx.a 
# -Lmlx -lmlx -framework OpenGL -framework AppKit -o so_long