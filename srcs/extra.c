/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:34:56 by bgannoun          #+#    #+#             */
/*   Updated: 2023/02/13 22:08:20 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	free_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
		i++;
	j = 0;
	while (j < i)
	{
		free(map[j]);
		j++;
	}
	free(map);
}

int	check_args(char *av)
{
	if (strstr(av, ".ber"))
		return (1);
	else
		return (0);
}

int	destroy_win(t_game *m)
{
	mlx_destroy_window(m->mlx_ptr, m->win_ptr);
	exit(0);
}

/* return 1 if there is a wall */
int	check_if_wall(int k, t_game *m)
{
	if (k == 2)
	{
		if (m->map[m->p_y][m->p_x + 1] == '1')
			return (1);
	}
	if (k == 0)
	{
		if (m->map[m->p_y][m->p_x - 1] == '1')
			return (1);
	}
	if (k == 1)
	{
		if (m->map[m->p_y + 1][m->p_x] == '1')
			return (1);
	}
	if (k == 13)
	{
		if (m->map[m->p_y - 1][m->p_x] == '1')
			return (1);
	}
	return (0);
}

int	check_if_exit(int k, t_game *m)
{
	if (m->col_count != 0)
	{
		if (k == 2)
		{
			if (m->map[m->p_y][m->p_x + 1] == 'E')
				return (1);
		}
		if (k == 0)
		{
			if (m->map[m->p_y][m->p_x - 1] == 'E')
				return (1);
		}
		if (k == 1)
		{
			if (m->map[m->p_y + 1][m->p_x] == 'E')
				return (1);
		}
		if (k == 13)
		{
			if (m->map[m->p_y - 1][m->p_x] == 'E')
				return (1);
		}
	}
	return (0);
}
