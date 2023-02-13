/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:22:15 by bgannoun          #+#    #+#             */
/*   Updated: 2023/02/13 20:09:29 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

int	key_dzb(int k, t_game *m)
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

int	main(int ac, char **av)
{
	t_game	m;

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
	if (map_checker_0(m) == 0 || map_checker_1(m) == 0 || map_checker_2(m) == 0
		|| map_checker_3(m) == 0)
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
	m.win_ptr = mlx_new_window(m.mlx_ptr, m.map_x * 50, m.map_y * 50,
			"SOMNIUM");
	m.wall = mlx_xpm_file_to_image(m.mlx_ptr, m.wall_path, &m.img_w, &m.img_h);
	m.player = mlx_xpm_file_to_image(m.mlx_ptr, m.player_path, &m.img_w,
			&m.img_h);
	m.free_s = mlx_xpm_file_to_image(m.mlx_ptr, m.free_path, &m.img_w,
			&m.img_h);
	m.door = mlx_xpm_file_to_image(m.mlx_ptr, m.door_path, &m.img_w, &m.img_h);
	m.coin = mlx_xpm_file_to_image(m.mlx_ptr, m.coin_path, &m.img_w, &m.img_h);
	map_rendering(&m);
	mlx_key_hook(m.win_ptr, key_dzb, &m);
	mlx_hook(m.win_ptr, 17, 0, destroy_win, &m);
	return (mlx_loop(m.mlx_ptr), 0);
}
