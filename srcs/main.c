/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:22:15 by bgannoun          #+#    #+#             */
/*   Updated: 2023/02/02 11:13:19 by bgannoun         ###   ########.fr       */
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

int	valid_path(game game)
{
	struct point p;
	int count;

	get_p(&p, game);
	count = get_count_c(game);
	// printf("%d\n", count);
	if (game.map[p.x][p.y + 1] != '1')
	{
		valid_path(game);
	}
	if (game.map[p.x + 1][p.y] != '1')
	{
		valid_path(game);
	}
	if (game.map[p.x][p.y - 1] != '1')
	{
		valid_path(game);
	}
	if (game.map[p.x - 1][p.y] != '1')
	{
		valid_path(game);
	}
	// 				if (game.map[p.x][p.y] == 'E')
	// 					return (1);
	// 			}
	// 		}
	// 	}
	// }
	// printf("test");
	// printf("i = %d\nj = %d\n", p.x, p.y);
	// if (game.map[p.x][p.y] == 'E')
	// 	return (1);
	// else
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
	while (so_long.map[j])
		printf("%s\n", so_long.map[j++]);
	// printf("!!%d!!\n", map_checker_2(so_long));
	// map_checker_2(so_long);
	valid_path(so_long);
	// printf("%d\n", valid_path(so_long));
	// printf("??%d??\n", get_count_c(so_long));
	if (map_checker_0(so_long) == 0 || map_checker_1(so_long) == 0 || map_checker_2(so_long) == 0)
		exit(0);
	printf("-----S----");
	close(fd);
	return (0);
}
