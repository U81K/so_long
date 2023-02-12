/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:22:15 by bgannoun          #+#    #+#             */
/*   Updated: 2023/02/12 17:25:32 by bgannoun         ###   ########.fr       */
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
		free(line);
	}
	res = ft_split(all, '\n');
	free(all);
	return (res);
}

typedef struct map_info
{
	int x;
	int y;
	int p_x;
	int p_y;
}				info;

void	game_info(t_game *game)
{
	int x;
	int y;

	game->map_y = 0;
	while (game->map[game->map_y])
		game->map_y++;
	game->map_x = ft_strlen(game->map[0]);

	x = 0;
	while(game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'P')
			{
				game->p_x = y;
				game->p_y = x;
			}
			y++;
		}
		x++;
	}
}

void	game_info_1(t_game *m)
{
	int x;
	int y;
	
	m->col_count = 0;
	y = 0;
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x])
		{
			if (m->map[y][x] == 'C')
				m->col_count += 1;
			x++;
		}
		y++;
	}
}

// void player_movement(int k, game game)
// {
// 	int x;
// 	int y;
	
// 	y = data.p_x;
// 	x = data.p_y;
// 	if (k == 2)
// 	{
// 		printf("---x = %d---\n", data.p_x);
// 		printf("---y = %d---\n", data.p_y);
// 		// mlx_put_image_to_window(mlx_ptr, win_ptr, free_s, x*50, y*50);
// 		// mlx_put_image_to_window(mlx_ptr, win_ptr, free_s, x++*50, y*50);
// 	}
// }

// void free_space(t_game *m)
// {
// 	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->free_s, m->p_x*50, m->p_y*50);
// }

// void	move_right(t_game *m)
// {
// 	// int x;
// 	// int y;

// 	// x = m.p_x;
// 	// y = m.p_y;
// 	// printf("x = %d ; y = %d\n", m->p_x, m->p_y);
	
// 	free_space(m);
// 	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->player, (m->p_x++)*50, m->p_y*50);
// 	// move_right(m);
// 	// mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->free_s, m->p_x*50, m->p_y*50);
// 	return;
// }

void map_rendering(t_game *m)
{
	int x;
	int y;
	y = 0;
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x])
		{
			if (m->map[y][x] == '1')
				mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->wall, x*50, y*50);
			else
				mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->free_s, x*50, y*50);
			if (m->map[y][x] == 'C')
				mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->coin, x*50, y*50); 
			else if (m->map[y][x] == 'E')
				mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->door, x*50, y*50);
			else if (m->map[y][x] == 'P')
				mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->player, x*50, y*50);
			x++;
		}
		y++;
	}
}

// return 1 if there is a wall
int check_if_wall(int k, t_game *m)
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

int check_if_exit(int k, t_game *m)
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

// void free_map(char **map)
// {
// 	int i;

// 	i = 0;
// 	while (map[i])
// 		i++;
// 	i--;
// 	while (map[i])
// 	{
// 		free(map[i]);
// 		i--;
// 	}
// 	free(map);
// }

int key_dzb(int k, t_game *m)
{
	if (k == 53)
		exit(0);
	if (check_if_wall(k, m) == 0 && check_if_exit(k, m) == 0 && (k == 2 || k == 0 || k == 1 || k == 13))
	{
		m->map[m->p_y][m->p_x] = '0';
		if (k == 2)
			m->p_x += 1;
		else if (k == 0)
			m->p_x -= 1;
		else if (k == 1)
			m->p_y += 1;
		else if (k == 13)
			m->p_y -= 1;
		m->mouve_c += 1;
		printf("move : %d\n", m->mouve_c);
	}
	game_info_1(m);
	if (m->map[m->p_y][m->p_x] == 'C')
		m->col_count -= 1;
	else if (m->map[m->p_y][m->p_x] == 'E' && m->col_count == 0)
	{
		printf("You Win\n");
		exit(0);
	}
	m->map[m->p_y][m->p_x] = 'P';
	map_rendering(m);
	return (0);
}

int check_args(char *av)
{
	if (strstr(av, ".ber"))
		return (1);
	else
		return (0);
}

// void close_callback(t_game *m)
// {
// 	mlx_destroy_window(m->mlx_ptr, m->win_ptr);
// 	exit(0);
// }
int	on_destroy(t_game *m)
{
	printf("window is destroyed");
	mlx_destroy_window(m->mlx_ptr, m->win_ptr);
	exit(0);
}

int	main(int ac, char **av)
{
	t_game m;

	if (ac != 2)
	{
		printf("args error");
		exit(1);
	}
	if (check_args(av[1]))
		m.fd = open(av[1], O_RDONLY);
	else
	{
		printf("invalide map file");
		exit(1);
	}
	m.map = read_map(m.fd);
	if (!m.map)
	{
		printf("no map found");
		exit(1);
	}
	if (map_checker_0(m) == 0 || map_checker_1(m) == 0 || map_checker_2(m) == 0 || map_checker_3(m) == 0)
	{
		printf("Map Error\n");
		exit(1);
	}
	valid_path(m);
	game_info(&m);
	close(m.fd);

	m.wall_path = "./textures/wall.xpm";
	m.player_path = "./textures/player.xpm";
	m.free_path = "./textures/free.xpm";
	m.door_path = "./textures/door.xpm";
	m.coin_path = "./textures/coin.xpm";
	
	m.mlx_ptr = mlx_init();
	m.win_ptr = mlx_new_window(m.mlx_ptr, m.map_x*50, m.map_y*50, "SOMNIUM");
	// if (m.win_ptr == NULL)
	// {
	// 	free(m.win_ptr);
	// 	return (1);
	// }
	m.wall = mlx_xpm_file_to_image(m.mlx_ptr, m.wall_path, &m.img_w, &m.img_h);
	// if (m.wall == NULL)
	// {
	// }
	// if (m.img_w != 50 || m.img_h != 50)
	// {
	// 	free(m.mlx_ptr);
	// }
	m.player = mlx_xpm_file_to_image(m.mlx_ptr, m.player_path, &m.img_w, &m.img_h);
	m.free_s = mlx_xpm_file_to_image(m.mlx_ptr, m.free_path, &m.img_w, &m.img_h);
	m.door = mlx_xpm_file_to_image(m.mlx_ptr, m.door_path, &m.img_w, &m.img_h);
	m.coin = mlx_xpm_file_to_image(m.mlx_ptr, m.coin_path, &m.img_w, &m.img_h);
	map_rendering(&m);
	mlx_key_hook(m.win_ptr, key_dzb, &m);
	mlx_hook(m.win_ptr, 17, 0, on_destroy, &m);
	// mlx_key_hook(m.win_ptr, key_dzb, &m);
	// mlx_loop_hook(m.win_ptr, 17, 0, close_callback, &m);
	mlx_loop(m.mlx_ptr);
	// mlx_destroy_window(m.mlx_ptr, m.win_ptr);
	return (0);
}
