/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:36:19 by bgannoun          #+#    #+#             */
/*   Updated: 2023/02/13 22:08:41 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_game
{
	char	**map;
	char	**copy_map;
	int		x;
	int		y;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall;
	void	*player;
	void	*free_s;
	void	*door;
	void	*coin;
	char	*wall_path;
	char	*player_path;
	char	*free_path;
	char	*door_path;
	char	*coin_path;
	int		img_w;
	int		img_h;
	int		fd;
	int		map_x;
	int		map_y;
	int		p_x;
	int		p_y;
	int		mouve_c;
	int		col_count;
	int		e_x;
	int		e_y;
}			t_game;

struct		s_com
{
	int		c;
	int		e;
	int		p;
	int		i;
	int		x;
	int		y;
};

struct		s_point
{
	int		x;
	int		y;
};

int			map_checker_0(t_game game);
int			map_checker_1(t_game game);
int			map_checker_2(t_game game);
int			map_checker_3(t_game game);
int			valid_path(t_game game);
char		*ft_strdup(const char *s);
void		free_map(char **map);
char		**ft_split(char const *s, char c);
int			check_args(char *av);
int			destroy_win(t_game *m);
int			check_if_wall(int k, t_game *m);
int			check_if_exit(int k, t_game *m);
char		*ft_strdup(const char *s);
void		map_rendering(t_game *m);
char		**read_map(int fd);
char		**copy_map(t_game game);
void		get_p(struct s_point *p, char **map);
void		game_info(t_game *game);
void		game_info_1(t_game *m);

#endif