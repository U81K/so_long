/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:08:12 by bgannoun          #+#    #+#             */
/*   Updated: 2022/10/23 20:00:33 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <ctype.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_putnbr(long int n);
int	ft_putstr(char *str);
int	ft_printf(const char *placeholder, ...);

#endif