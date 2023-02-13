/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:19:38 by bgannoun          #+#    #+#             */
/*   Updated: 2023/02/13 18:23:57 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

char	**read_map(int fd)
{
	char	*line;
	char	**res;
	char	*all;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		all = ft_strjoin(all, line);
		free(line);
	}
	res = ft_split(all, '\n');
	free(all);
	return (res);
}

void	map_rendering(t_game *m)
{
	int	x;
	int	y;

	y = 0;
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x])
		{
			if (m->map[y][x] == '1')
				mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->wall, x * 50,
					y * 50);
			else
				mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->free_s, x
					* 50, y * 50);
			if (m->map[y][x] == 'C')
				mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->coin, x * 50,
					y * 50);
			else if (m->map[y][x] == 'E')
				mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->door, x * 50,
					y * 50);
			else if (m->map[y][x] == 'P')
				mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->player, x
					* 50, y * 50);
			x++;
		}
		y++;
	}
}
