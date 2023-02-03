/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:22:15 by bgannoun          #+#    #+#             */
/*   Updated: 2023/02/03 19:16:25 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

static int	word_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*str_count(char *str, char c)
{
	int			i;
	int			str_count;
	char		*word;

	i = 0;
	str_count = 0;
	while (str[i] && str[i] != c)
	{
		str_count++;
		i++;
	}
	word = (char *)malloc(sizeof(char) * str_count + 1);
	if (!word)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;

	if (!s)
		return (0);
	res = malloc(sizeof(char *) * (word_count((char *)s, c) + 1));
	if (!res)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			res[j] = str_count(&((char *)s)[i], c);
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	res[j] = 0;
	return (res);
}

// read the map to a **ptr
char	**read_map(int fd)
{
	char	*line;
	char	**res;
	char	*all;
	
	while(1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		all = ft_strjoin(all, line);
	}
	res = ft_split(all, '\n');
	return (res);
}

// check if the path is valid
struct point
{
	int x;
	int y;	
};

int get_count_c(game game)
{
	int	i;
	int	j;
	int count;
	
	i = 0;
	count = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
		{
			if (game.map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count + 1);
}

void get_p(struct point *p, game game)
{
	int	i;
	int	j;
	
	i = 0;
	while (game.map[i])
	{
		j = 0;
		while (game.map[i][j])
		{
			if (game.map[i][j] == 'P')
			{
				p->x = i;
				p->y = j;
			}
			j++;
		}
		i++;
	}
}

void search_path(game game, int count)
{
	int x = 0;
	int y = 0;
	game.map[x][y] = '1';
}

void ffa(game game, int x, int y)
{
	if (game.map[x][y] == '1' || game.map[x][y] == 'E' || game.map[x][y] == 'C')
		return;
	else
		game.map[x][y] = '1';
	ffa(game, x, y + 1);
	ffa(game, x - 1, y);
	ffa(game, x, y - 1);
	ffa(game, x + 1, y);
}

int	valid_path(game game)
{
	struct point p;
	int count;
	int c;
	
	get_p(&p, game);
	count = get_count_c(game);
	printf("collectibale count : %d\n", count);
	printf("point index : %d,%d\n", p.x, p.y);
	ffa(game, p.x, p.y);
	// game.map[p.x][p.y] = '1';
	// game.map[p.x][p.y] = '1';
	// if (game.map[p.x][p.y] == 'E' || game.map[p.x][p.y] == 'C')
	// 	c++;
	// else if (game.map[p.x][p.y + 1] != '1')
	// 	valid_path(game);
	// // else
	// // 	p.y--;
	// else if (game.map[p.x + 1][p.y] != '1')
	// 	valid_path(game);
	// // else
	// // 	p.x--;
	// else if (game.map[p.x][p.y - 1] != '1')
	// 	valid_path(game);
	// // else
	// // 	p.y++;
	// else if (game.map[p.x - 1][p.y] != '1')
	// 	valid_path(game);
	// else if ()
	// else
	// 	p.x++;
	return (0);
}

int	main(int ac, char **av)
{
	game so_long;
	int	fd;
	int	j;
	
	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	so_long.map = read_map(fd);
	j = 0;
	// printf("!!%d!!\n", map_checker_2(so_long));
	// map_checker_2(so_long);
	valid_path(so_long);
	while (so_long.map[j])
		printf("%s\n", so_long.map[j++]);
	// printf("%d\n", valid_path(so_long));
	// printf("??%d??\n", get_count_c(so_long));
	if (map_checker_0(so_long) == 0 || map_checker_1(so_long) == 0 || map_checker_2(so_long) == 0)
		exit(0);
	printf("-----S----");
	close(fd);
	return (0);
}
