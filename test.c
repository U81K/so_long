/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:22:18 by bgannoun          #+#    #+#             */
/*   Updated: 2023/01/20 22:15:58 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>

int deal_key(int key, void *param)
{
	printf("x");
	// mlx_pixel_put(mlx_ptr, win_ptr, );
	return (0);
}

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 34*50, 6*50, "mlx 42");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return (1);
	}
	
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	// while(1)
	// 	;
	// mlx_destroy_window(mlx_ptr, win_ptr);
	// mlx_destroy_display();
	mlx_loop(mlx_ptr);
	free(mlx_ptr);
	return (0);
}
