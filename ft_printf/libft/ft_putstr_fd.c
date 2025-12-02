/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:36:52 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/16 03:01:23 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	count;
	int	ret;

	if (s == NULL)
		return (ft_putstr_fd("(null)", fd));
	i = 0;
	count = 0;
	while (s[i])
	{
		ret = ft_putchar_fd(s[i], fd);
		if (ret == -1)
			return (-1);
		count += ret;
		i++;
	}
	return (count);
}
/*
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("./file", O_WRONLY);
	ft_putstr_fd("amembo", fd);
	close(fd);
	return (0);
}
*/
