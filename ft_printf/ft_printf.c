/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:57:13 by bgannoun          #+#    #+#             */
/*   Updated: 2022/10/25 14:51:37 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex(long long unsigned int n, char	*base)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += hex(n / 16, base);
		count += hex(n % 16, base);
	}
	else
		count += ft_putchar(base[n]);
	return (count);
}

int	unsign(unsigned int n)
{
	int	count;

	count = 0;
	count += ft_putnbr(n);
	return (count);
}

int	percent(va_list args, char c)
{
	if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'x')
		return (hex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (c == 'u')
		return (unsign(va_arg(args, unsigned int)));
	else if (c == 'p')
	{
		ft_putstr("0x");
		return (hex(va_arg(args, long long unsigned int),
				"0123456789abcdef") + 2);
	}
	return (0);
}

int	ft_printf(const char *placeholder, ...)
{
	va_list	list;
	int		i;
	int		count;

	va_start(list, placeholder);
	i = 0;
	count = 0;
	while (placeholder[i])
	{
		if (placeholder[i] == '%')
		{
			i++;
			count += percent(list, placeholder[i]);
		}
		else
			count += ft_putchar(placeholder[i]);
		i++;
	}
	va_end(list);
	return (count);
}
