/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:22:15 by bgannoun          #+#    #+#             */
/*   Updated: 2023/02/14 17:14:02 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	key_1(t_game *m)
{
	if (m->map[m->p_y][m->p_x] == 'C')
		m->col_count -= 1;
	else if (m->map[m->p_y][m->p_x] == 'E' && m->col_count == 0)
	{
		ft_printf("You Win\n");
		exit(0);
	}
	m->map[m->p_y][m->p_x] = 'P';
}

int	key(int k, t_game *m)
{
	if (k == 53)
		exit(0);
	if (check_if_wall(k, m) == 0 && check_if_exit(k, m) == 0 && (k == 2
			|| k == 0 || k == 1 || k == 13))
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
		ft_printf("move : %d\n", m->mouve_c);
	}
	game_info_1(m);
	key_1(m);
	map_rendering(m);
	return (0);
}

void	main_1(t_game *m, int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("args error");
		exit(1);
	}
	if (check_args(av[1]))
		m->fd = open(av[1], O_RDONLY);
	else
	{
		ft_printf("invalide map file");
		exit(1);
	}
	m->map = read_map(m->fd);
	if (!m->map)
	{
		ft_printf("no map found");
		exit(1);
	}
	if (map_checker_0(*m) == 0 || map_checker_1(*m) == 0
		|| map_checker_2(*m) == 0 || map_checker_3(*m) == 0)
	{
		ft_printf("Map Error\n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_game	m;

	main_1(&m, ac, av);
	valid_path(m);
	game_info(&m);
	close(m.fd);
	m.wall_path = "./textures/wall.xpm";
	m.player_path = "./textures/player.xpm";
	m.free_path = "./textures/free.xpm";
	m.door_path = "./textures/door.xpm";
	m.coin_path = "./textures/coin.xpm";
	m.mlx_ptr = mlx_init();
	m.win_ptr = mlx_new_window(m.mlx_ptr, m.map_x * 50, m.map_y * 50,
			"so_long");
	m.wall = mlx_xpm_file_to_image(m.mlx_ptr, m.wall_path, &m.img_w, &m.img_h);
	m.player = mlx_xpm_file_to_image(m.mlx_ptr, m.player_path, &m.img_w,
			&m.img_h);
	m.free_s = mlx_xpm_file_to_image(m.mlx_ptr, m.free_path, &m.img_w,
			&m.img_h);
	m.door = mlx_xpm_file_to_image(m.mlx_ptr, m.door_path, &m.img_w, &m.img_h);
	m.coin = mlx_xpm_file_to_image(m.mlx_ptr, m.coin_path, &m.img_w, &m.img_h);
	map_rendering(&m);
	mlx_key_hook(m.win_ptr, key, &m);
	mlx_hook(m.win_ptr, 17, 0, destroy_win, &m);
	return (mlx_loop(m.mlx_ptr), 0);
}
