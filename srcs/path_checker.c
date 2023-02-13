/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:38:27 by bgannoun          #+#    #+#             */
/*   Updated: 2023/02/13 18:30:28 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

char	**copy_map(t_game game)
{
	char	**copy_map;
	int		i;
	int		j;

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

int	check_e(struct s_point p_E, char **map)
{
	if (map[p_E.y][p_E.x + 1] == 'X' || map[p_E.y + 1][p_E.x] == 'X'
		|| map[p_E.y][p_E.x - 1] == 'X' || map[p_E.y - 1][p_E.x] == 'X')
		return (1);
	return (0);
}

int	valid_path(t_game game)
{
	struct s_point	p_P;
	struct s_point	p_E;
	char			**new_map;

	new_map = copy_map(game);
	get_p(&p_P, new_map);
	flood_fill(new_map, p_P.y, p_P.x);
	get_e(&p_E, new_map);
	if (check_e(p_E, new_map) == 1 && check_c_e(new_map) == 0)
	{
		free_map(new_map);
		return (1);
	}
	else
	{
		free_map(new_map);
		printf("Invalide path");
		exit(1);
		return (0);
	}
}
