/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:36:19 by bgannoun          #+#    #+#             */
/*   Updated: 2023/02/06 10:37:23 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

typedef struct	game
{
	char **map;
	char **copy_map;
}				game;

struct com
{
	int	C;
	int	E;
	int	P;
	int i;
	int	x;
	int	y;
};

struct point
{
	int x;
	int y;	
};

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"
#include "../mlx/mlx.h"
// #include "../libft/libft.h"

int map_checker_0(game game);
int	map_checker_1(game game);
int	map_checker_2(game game);
int	valid_path(game game);
char	*ft_strdup(const char *s);

#endif