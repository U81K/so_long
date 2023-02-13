/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:13:53 by bgannoun          #+#    #+#             */
/*   Updated: 2023/02/13 18:39:40 by bgannoun         ###   ########.fr       */
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
