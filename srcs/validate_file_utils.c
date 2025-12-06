/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:27:58 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/06 12:37:11 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	measure_filesize(char *filepath)
{
	int	fd;
	int	buf[BUFFER_SIZE];
	int	bytesize;
	int	res;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return ((void)ft_putstr_fd("Fail to open the file.", 2),
	FAIL_TO_OPEN);
	bytesize = 0;
	res = 1;
	while (res)
	{
		res = read(fd, buf, BUFFER_SIZE);
		if (res == -1)
			return ((void)ft_putstr_fd("Fail to open the file.", 2),
		FAIL_TO_READ);
		bytesize += res;
	}
	close(fd);
	return (bytesize);
}
