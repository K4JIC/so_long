/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:28:33 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/16 05:13:13 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_mini_putnbr_base_fd(int n, int base, char *basechr, int fd)
{
	long	ln;
	char	c;
	int		ret;
	int		count;

	count = 0;
	ln = (long)n;
	if (ln >= base)
	{
		ret = ft_mini_putnbr_base_fd((int)(ln / base), base, basechr, fd);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	c = basechr[ln % base];
	ret = ft_putchar_fd(c, fd);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}

int	ft_putnbr_base_fd(int n, int base, char *basechr, int fd)
{
	long	ln;
	int		ret;
	int		count;

	count = 0;
	ln = (long)n;
	if (ln < 0)
	{
		ret = ft_putchar_fd('-', fd);
		if (ret == -1)
			return (-1);
		count += ret;
		ln *= -1;
	}
	ret = ft_mini_putnbr_base_fd(n, base, basechr, fd);
	if (ret == -1)
		return (-1);
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
	char *basechr = "0123456789abcdef";
	ft_putnbr_base_fd(-128974, 16, basechr, 1);
	close(fd);
	return (0);
}
*/
