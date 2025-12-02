/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:43:20 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/16 11:40:42 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

static int	allocate_putfunc(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar_fd((char)va_arg(ap, int), 1));
	if (c == 's')
		return (ft_putstr_fd(va_arg(ap, char *), 1));
	if (c == 'p')
		return (ft_putptr_fd((unsigned long long)va_arg(ap, void *), 1));
	if (c == 'd')
		return (ft_putnbr_fd(va_arg(ap, int), 1));
	if (c == 'i')
		return (ft_putnbr_fd(va_arg(ap, int), 1));
	if (c == 'u')
		return (ft_putnbr_ui_fd(va_arg(ap, unsigned int), 1));
	if (c == 'x')
		return (ft_putnbr_hex_fd(va_arg(ap, int), 'x', 1));
	if (c == 'X')
		return (ft_putnbr_hex_fd(va_arg(ap, int), 'X', 1));
	if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (ft_putchar_fd('%', 1));
}

static int	mini_read_format(int *per_flag, char c, va_list ap)
{
	int	res;

	res = 0;
	if (*per_flag == 1)
	{
		res = allocate_putfunc(c, ap);
		if (res == -1)
			return (-1);
		*per_flag = 0;
	}
	else
	{
		if (c == '%')
			*per_flag = 1;
		else
			res = ft_putchar_fd(c, 1);
		if (res == -1)
			return (-1);
	}
	return (res);
}

static int	read_format(const char *format, va_list ap)
{
	int	per_flag;
	int	i;
	int	count;
	int	res;

	per_flag = 0;
	i = 0;
	count = 0;
	while (format[i])
	{
		res = mini_read_format(&per_flag, format[i], ap);
		if (res == -1)
			return (-1);
		count += res;
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = read_format(format, ap);
	if (count == -1)
		return (-1);
	va_end(ap);
	return (count);
}
