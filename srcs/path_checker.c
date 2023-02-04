/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:38:27 by bgannoun          #+#    #+#             */
/*   Updated: 2023/02/04 19:39:49 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

char **copy_map(game game)
{
	char **copy_map;
	int	i;
	int	j;

	i = 0;
	while (game.map[i])
		i++;
	copy_map = malloc(sizeof(char *) * (i + 1));
	if (!copy_map)
		return (NULL);
	i = 0;
	while (game.map[i])
	{
		copy_map[i] = strdup(game.map[i]);
		i++;
	}
	copy_map[i] = NULL;
	return (copy_map);
}

void get_p(struct point *p, char **map)
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
				p->x = i;
				p->y = j;
			}
			j++;
		}
		i++;
	}
}

int check_c_e(char **new_map)
{
	int i;

	i = 0;
	while (new_map[i])
	{
		if (ft_strchr(new_map[i], 'C') || ft_strchr(new_map[i], 'E'))
			return (1);
		i++;
	}
	return (0);
}

void flood_fill(char **new_map, int x, int y)
{
	if (new_map[x][y] == '1')
		return;
	else
		new_map[x][y] = '1';
	flood_fill(new_map, x, y + 1);
	flood_fill(new_map, x - 1, y);
	flood_fill(new_map, x, y - 1);
	flood_fill(new_map, x + 1, y);
}

int	valid_path(game game)
{
	struct point p;
	char **new_map;
	
	new_map = copy_map(game);
	get_p(&p, new_map);
	flood_fill(new_map, p.x, p.y);
	if (check_c_e(new_map) == 0)
		return (1);
	else
		return (0);
}
