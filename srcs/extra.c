/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:34:56 by bgannoun          #+#    #+#             */
/*   Updated: 2023/02/06 10:38:45 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;

	p = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	if (p == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		p[i] = (char)s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
