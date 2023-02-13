/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:56:04 by bgannoun          #+#    #+#             */
/*   Updated: 2023/02/13 22:00:58 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

char	**copy_map(t_game game)
{
	char	**copy_map;
	int		i;

	i = 0;
	while (game.map[i])
		i++;
	copy_map = malloc(sizeof(char *) * (i + 1));
	if (!copy_map)
		return (NULL);
	i = 0;
	while (game.map[i])
	{
		copy_map[i] = ft_strdup(game.map[i]);
		i++;
	}
	copy_map[i] = NULL;
	return (copy_map);
}

void	get_p(struct s_point *p, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				p->y = i;
				p->x = j;
			}
			j++;
		}
		i++;
	}
}

void	game_info(t_game *game)
{
	int	x;
	int	y;

	game->map_y = 0;
	while (game->map[game->map_y])
		game->map_y++;
	game->map_x = ft_strlen(game->map[0]);
	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'P')
			{
				game->p_x = y;
				game->p_y = x;
			}
			y++;
		}
		x++;
	}
}

void	game_info_1(t_game *m)
{
	int	x;
	int	y;

	m->col_count = 0;
	y = 0;
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x])
		{
			if (m->map[y][x] == 'C')
				m->col_count += 1;
			x++;
		}
		y++;
	}
}
