/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:22:15 by bgannoun          #+#    #+#             */
/*   Updated: 2023/02/06 10:39:45 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

//ft_split
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
	if (map_checker_0(so_long) == 0 || map_checker_1(so_long) == 0 || map_checker_2(so_long) == 0 || valid_path(so_long) == 0)
		exit(0);
	printf("-----S----");
	close(fd);
	/////
	
	void *mlx_ptr;
	void *win_ptr;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 34*50, 6*50, "mlx 42");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return (1);
	}
	
	// // mlx_key_hook(win_ptr, deal_key, (void *)0);
	// // while(1)
	// // 	;
	// // mlx_destroy_window(mlx_ptr, win_ptr);
	// // mlx_destroy_display();
	mlx_loop(mlx_ptr);
	free(mlx_ptr);
	
	/////
	return (0);
}
