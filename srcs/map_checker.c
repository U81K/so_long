/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:00:17 by bgannoun          #+#    #+#             */
/*   Updated: 2023/02/08 17:26:55 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

// check map sheep && equal lines
int map_checker_0(t_game game)
{
	int y;
	int	i;
	int j;
	int x;

	x = 0;
	y = ft_strlen(game.map[0]);
	while (game.map[x])
		x++;
	if (x >= y)
		return (0);
	i = 0;
	j = 0;
	while (game.map[i])
	{
		j = 0;
		while(game.map[i][j])
			j++;
		if (j != y)
			return (0);
		i++;
	}
	return (1);
}

void	map_info(struct t_com *d, t_game game)
{
	d->C = 0;
	d->E = 0;
	d->P = 0;
	d->i = 0;
	d->x = 0;
	while (game.map[d->x])
		d->x++;
	d->x--;
	d->y = ft_strlen(game.map[0]) - 1;
}

// check map component
int	map_checker_1(t_game game)
{
	struct t_com c;
	int	j;
	
	map_info(&c, game);
	while (game.map[c.i])
	{
		j = 0;
		while (game.map[c.i][j])
		{
			if (game.map[c.i][j] == 'C')
				c.C++;
			if (game.map[c.i][j] == 'E')
				c.E++;
			if (game.map[c.i][j] == 'P')
				c.P++;
			j++;
		}
		c.i++;
	}
	if (c.C >= 1 && c.E == 1 && c.P == 1)
		return (1);
	return (0);
}

// check surrounding
int	map_checker_2(t_game game)
{
	int	i;
	struct t_com d;
	
	map_info(&d, game);
	i = 0;
	while (game.map[i])
	{
		if (game.map[i][0] != '1' || game.map[i][d.y] != '1')
			return (0);
		i++;
	}
	i = 0;
	while(game.map[0][i])
	{
		if (game.map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (game.map[d.x][i])
	{
		if (game.map[d.x][i] != '1')
			return (0);
		i++;
	}
	return (1);
}
