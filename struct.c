/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:49:00 by bgannoun          #+#    #+#             */
/*   Updated: 2023/01/29 18:20:54 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct	s_point
{
	char *f_name;
	char *l_name;
}				t_point;

int	main(void)
{
	t_point bilal;
	t_point *ptr;

	bilal.f_name = "bilal";
	bilal.l_name = "gannouni";
	ptr = &bilal;
	ptr->f_name = "a";
	ptr->l_name = "b";
	 
	printf("%s\n%s", bilal.f_name, bilal.l_name);
	return (0);
}