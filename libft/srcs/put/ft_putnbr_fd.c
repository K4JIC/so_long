/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:54:21 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/16 11:28:37 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_mini_putnbr_fd(long ln, int fd)
{
	char	c;
	int		count;
	int		ret;

	count = 0;
	if (ln >= 10)
	{
		ret = ft_mini_putnbr_fd(ln / 10, fd);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	c = ln % 10 + '0';
	ret = ft_putchar_fd(c, fd);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}

int	ft_putnbr_fd(int n, int fd)
{
	long	ln;
	int		count;
	int		ret;

	ln = (long)n;
	count = 0;
	if (ln < 0)
	{
		ret = ft_putchar_fd('-', fd);
		if (ret == -1)
			return (-1);
		count += ret;
		ln *= -1;
	}
	ret = ft_mini_putnbr_fd(ln, fd);
	count += ret;
	return (count);
}

/*
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("./file", O_WRONLY);
	ft_putnbr_fd(-2147483648, fd);
	close(fd);
	return (0);
}
*/
