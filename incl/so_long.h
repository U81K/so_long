/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:36:19 by bgannoun          #+#    #+#             */
/*   Updated: 2023/02/10 20:15:52 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

typedef struct	s_game
{
	char **map;
	char **copy_map;
	int	x;
	int y;	
	void *mlx_ptr;
	void *win_ptr;
	void *wall;
	void *player;
	void *free_s;
	void *door;
	void *coin;
	char *wall_path;
	char *player_path;
	char *free_path;
	char *door_path;
	char *coin_path;
	int img_w;
	int img_h;
	int	fd;
	int	map_x;
	int map_y;
	int p_x;
	int p_y;
	int mouve_c;
	int col_count;
	int e_x;
	int e_y;
}				t_game;

struct t_com
{
	int	C;
	int	E;
	int	P;
	int i;
	int	x;
	int	y;
};

struct t_point
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

int		map_checker_0(t_game game);
int		map_checker_1(t_game game);
int		map_checker_2(t_game game);
int		map_checker_3(t_game game);
int		valid_path(t_game game);
char	*ft_strdup(const char *s);
void	free_map(char **map);

#endif