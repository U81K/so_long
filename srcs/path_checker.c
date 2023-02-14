/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:38:27 by bgannoun          #+#    #+#             */
/*   Updated: 2023/02/14 17:03:27 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

int	check_c_e(char **new_map)
{
	int	i;

	i = 0;
	while (new_map[i])
	{
		if (ft_strchr(new_map[i], 'C'))
			return (1);
		i++;
	}
	return (0);
}

void	flood_fill(char **new_map, int y, int x)
{
	if (new_map[y][x] == '1' || new_map[y][x] == 'X' || new_map[y][x] == 'E')
		return ;
	else
	{
		new_map[y][x] = 'X';
		flood_fill(new_map, y, x + 1);
		flood_fill(new_map, y + 1, x);
		flood_fill(new_map, y, x - 1);
		flood_fill(new_map, y - 1, x);
	}
}

void	get_e(struct s_point *p, char **new_map)
{
	int	y;
	int	x;

	y = 0;
	while (new_map[y])
	{
		x = 0;
		while (new_map[y][x])
		{
			if (new_map[y][x] == 'E')
			{
				p->y = y;
				p->x = x;
			}
			x++;
		}
		y++;
	}
}

int	check_e(struct s_point e, char **map)
{
	if (map[e.y][e.x + 1] == 'X' || map[e.y + 1][e.x] == 'X'
		|| map[e.y][e.x - 1] == 'X' || map[e.y - 1][e.x] == 'X')
		return (1);
	return (0);
}

int	valid_path(t_game game)
{
	struct s_point	p;
	struct s_point	e;
	char			**new_map;

	new_map = copy_map(game);
	get_p(&p, new_map);
	flood_fill(new_map, p.y, p.x);
	get_e(&e, new_map);
	if (check_e(e, new_map) == 1 && check_c_e(new_map) == 0)
	{
		free_map(new_map);
		return (1);
	}
	else
	{
		free_map(new_map);
		ft_printf("Invalide path");
		exit(1);
		return (0);
	}
}
