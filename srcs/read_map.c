/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:19:38 by bgannoun          #+#    #+#             */
/*   Updated: 2023/02/18 16:03:26 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (str + i);
			else
				j++;
		}
		i++;
	}
	return (NULL);
}

char	**read_map(int fd)
{
	char	*line;
	char	**res;
	char	*all;
	int		i;

	if (fd == -1)
		exit_fun();
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if ((i == 0 && !line) || (i == 0 && line[0] == '\n'))
			exit_fun();
		if (!line)
			break ;
		all = ft_strjoin(all, line);
		free(line);
		i++;
	}
	if (ft_strstr(all, "\n\n"))
		exit_fun();
	res = ft_split(all, '\n');
	free(all);
	return (res);
}

void	map_rendering_1(t_game *m, int y, int x)
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
		mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->player,
			x * 50, y * 50);
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
			map_rendering_1(m, y, x);
			x++;
		}
		y++;
	}
}
