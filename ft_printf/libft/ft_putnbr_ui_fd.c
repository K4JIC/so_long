/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ui_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:54:21 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/16 03:27:07 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_ui_fd(unsigned int n, int fd)
{
	char	c;
	int		count;
	int		ret;

	count = 0;
	if (n >= 10)
	{
		ret = ft_putnbr_ui_fd(n / 10, fd);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	c = n % 10 + '0';
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
	ft_putnbr_fd(-2147483648, fd);
	close(fd);
	return (0);
}
*/
