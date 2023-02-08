/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:22:15 by bgannoun          #+#    #+#             */
/*   Updated: 2023/02/07 17:43:39 by bgannoun         ###   ########.fr       */
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

typedef struct map_info
{
	int x;
	int y;
	int p_x;
	int p_y;
}				info;

void	game_info(game game, info *map)
{
	// int x;
	// int y;
	
	map->y = 0;
	while (game.map[map->y])
		map->y++;
	map->x = ft_strlen(game.map[0]);
	int x;
	int y;

	x = 0;
	while(game.map[x])
	{
		y = 0;
		while (game.map[x][y])
		{
			if (game.map[x][y] == 'P')
			{
				map->p_x = x;
				map->p_y = y;
			}
			y++;
		}
		x++;
	}
}

void player_movement(int k, game game, info data)
{
	int x;
	int y;
	
	y = data.p_x;
	x = data.p_y;
	if (k == 2)
	{
		printf("---x = %d---\n", data.p_x);
		printf("---y = %d---\n", data.p_y);
		// mlx_put_image_to_window(mlx_ptr, win_ptr, free_s, x*50, y*50);
		// mlx_put_image_to_window(mlx_ptr, win_ptr, free_s, x++*50, y*50);
	}
}

int key_dzb(int k, game *game)
{
	info data;
	
	game_info(*game, &data);
	if (k == 2 || k == 1 || k == 0 || k == 13)
		player_movement(k, *game, data);
	return (0);
}


int	main(int ac, char **av)
{
	game so_long;
	info map;
	int	fd;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	so_long.map = read_map(fd);
	// int j;
	// j = 0;
	// while (so_long.map[j])
	// 	printf("%s\n", so_long.map[j++]);
	if (map_checker_0(so_long) == 0 || map_checker_1(so_long) == 0 || map_checker_2(so_long) == 0 || valid_path(so_long) == 0)
		exit(1);
	// else
	// 	printf("Success");
	game_info(so_long, &map);
	close(fd);
	/////
	
	void *mlx_ptr;
	void *win_ptr;
	void *wall;
	void *player;
	void *free_s;
	void *door;
	void *coin;
	char *wall_path = "./textures/wall.xpm";
	char *player_path = "./textures/player.xpm";
	char *free_path = "./textures/free.xpm";
	char *door_path = "./textures/door.xpm";
	char *coin_path = "./textures/coin.xpm";
	int img_w;
	int img_h;
	
	// img_w = 32;
	// img_h = 32;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, map.x*50, map.y*50, "SOMNIUM");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return (1);
	}
	wall = mlx_xpm_file_to_image(mlx_ptr, wall_path, &img_w, &img_h);
	player = mlx_xpm_file_to_image(mlx_ptr, player_path, &img_w, &img_h);
	free_s = mlx_xpm_file_to_image(mlx_ptr, free_path, &img_w, &img_h);
	door = mlx_xpm_file_to_image(mlx_ptr, door_path, &img_w, &img_h);
	coin = mlx_xpm_file_to_image(mlx_ptr, coin_path, &img_w, &img_h);
	int x;
	int y;
	
	y = 0;
	while (so_long.map[y])
	{
		x = 0;
		while (so_long.map[y][x])
		{
			if (so_long.map[y][x] == '1')
				mlx_put_image_to_window(mlx_ptr, win_ptr, wall, x*50, y*50);
			else
				mlx_put_image_to_window(mlx_ptr, win_ptr, free_s, x*50, y*50);
			if (so_long.map[y][x] == 'C')
				mlx_put_image_to_window(mlx_ptr, win_ptr, coin, x*50, y*50); 
			else if (so_long.map[y][x] == 'E')
				mlx_put_image_to_window(mlx_ptr, win_ptr, door, x*50, y*50);
			else if (so_long.map[y][x] == 'P')
				mlx_put_image_to_window(mlx_ptr, win_ptr, player, x*50, y*50);
			x++;
		}
		y++;
	}
	// int *key;
	mlx_key_hook(win_ptr, key_dzb, &so_long);
	mlx_loop(mlx_ptr);
	// free(mlx_ptr);
	
	/////
	return (0);
}
