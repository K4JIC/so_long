/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:27:58 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/05 19:28:30 by tozaki           ###   ########.fr       */
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
	bytesize = 0;
	res = 1;
	while (res)
	{
		res = read(fd, buf, BUFFER_SIZE);
		if (res == -1)
			return (-1);
		bytesize += res;
	}
	close(fd);
	return (bytesize);
}
