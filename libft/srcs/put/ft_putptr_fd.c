/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 21:53:03 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/16 03:18:07 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_mini_putptr_fd(unsigned long long n, int fd)
{
	char	*basechar;
	int		index;
	int		count;
	int		ret;

	basechar = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		ret = ft_mini_putptr_fd(n / 16, fd);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	index = n % 16;
	ret = ft_putchar_fd(basechar[index], fd);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}

int	ft_putptr_fd(unsigned long long n, int fd)
{
	int	count;
	int	ret;

	if (!n)
		return (ft_putstr_fd("(nil)", fd));
	count = 0;
	ret = ft_putstr_fd("0x", fd);
	if (ret == -1)
		return (-1);
	count += ret;
	ret = ft_mini_putptr_fd(n, fd);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}
/*
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	*pd;
	int	d;
	int	res;

	d = 1;
	pd = &d;
	res = ft_putptr_fd((unsigned long long)pd, 1);
	if (res == -1)
		return (-1);
	printf("\n");
	printf("%p\n", pd);
	printf("%d\n", res);
	return (0);
}
*/
