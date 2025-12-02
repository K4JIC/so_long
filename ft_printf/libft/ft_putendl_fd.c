/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:49:12 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/15 19:54:05 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	ret;
	int	count;

	count = 0;
	ret = ft_putstr_fd(s, fd);
	if (ret == -1)
		return (-1);
	count += ret;
	ret = ft_putchar_fd('\n', fd);
	if (ret == -1)
		return (-1);
	count += ret;
	return (0);
}
/*
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("./file", O_WRONLY);
	ft_putendl_fd("amembo", fd);
	close(fd);
	return (0);
}
*/
