/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_ui_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:28:33 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/16 11:20:18 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_putnbr_base_ui_fd(unsigned int n, unsigned int base, \
char *basechr, int fd)
{
	char	c;
	int		ret;
	int		count;

	count = 0;
	if (n >= base)
	{
		ret = ft_putnbr_base_ui_fd(n / base, base, basechr, fd);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	c = basechr[n % base];
	ret = ft_putchar_fd(c, fd);
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
