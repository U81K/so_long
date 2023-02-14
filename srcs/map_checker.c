/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:00:17 by bgannoun          #+#    #+#             */
/*   Updated: 2023/02/14 17:24:32 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

/* check map sheep && equal lines */
int	map_checker_0(t_game game)
{
	int	y;
	int	i;
	int	j;
	int	x;

	x = 0;
	y = ft_strlen(game.map[0]);
	while (game.map[x])
		x++;
	if (x == y)
		return (0);
	i = 0;
	j = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
			j++;
		if (j != y)
			return (0);
		i++;
	}
	return (1);
}

void	map_info(struct s_com *d, t_game game)
{
	d->c = 0;
	d->e = 0;
	d->p = 0;
	d->i = 0;
	d->x = 0;
	while (game.map[d->x])
		d->x++;
	d->x--;
	d->y = ft_strlen(game.map[0]) - 1;
}

/* check map component */
int	map_checker_1(t_game game)
{
	struct s_com	c;
	int				j;

	map_info(&c, game);
	while (game.map[c.i])
	{
		j = 0;
		while (game.map[c.i][j])
		{
			if (game.map[c.i][j] == 'C')
				c.c++;
			if (game.map[c.i][j] == 'E')
				c.e++;
			if (game.map[c.i][j] == 'P')
				c.p++;
			j++;
		}
		c.i++;
	}
	if (c.c >= 1 && c.e == 1 && c.p == 1)
		return (1);
	return (0);
}

/* check surrounding */
int	map_checker_2(t_game game)
{
	int				i;
	struct s_com	d;

	map_info(&d, game);
	i = 0;
	while (game.map[i])
	{
		if (game.map[i][0] != '1' || game.map[i][d.y] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (game.map[0][i] && game.map[d.x][i])
	{
		if (game.map[0][i] != '1' || game.map[d.x][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	map_checker_3(t_game game)
{
	int	y;
	int	x;

	y = 0;
	while (game.map[y])
	{
		x = 0;
		while (game.map[y][x])
		{
			if (ft_strchr("01PCE\n", game.map[y][x]) == 0)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
