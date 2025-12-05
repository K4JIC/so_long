/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:08:58 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/05 16:41:13 by tozaki           ###   ########.fr       */
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

static int	has_continuous_newline(char *str)
{
	int	in_newline;
	int	i;

	in_newline = 0;
	i = 0;
	while (str[i])
	{
		if (in_newline == 1 && str[i] == '\n')
			return (1);
		in_newline = 0;
		if (str[i] == '\n')
			in_newline = 1;
		i++;
	}
	return (0);
}

int	is_valid_use_of_newline(char *filepath)
{
	int		bytesize;
	char	*buf;
	int		fd;
	int		res;

	bytesize = measure_filesize(filepath);
	if (bytesize == -1)
		return (-1);
	buf = malloc(bytesize);
	if (!buf)
		return (-1);
	fd = open(filepath, O_RDONLY);
	res = read(fd, buf, BUFFER_SIZE);
	if (res == -1)
		return (free(buf), -1);
	close(fd);
	buf[bytesize] = '\0';
	if (has_continuous_newline(buf))
		return (free(buf), 0);
	return (free(buf), 1);
}

int	is_valid_filename(char *filepath)
{
	size_t	slen;

	slen = ft_strlen(filepath);
	if (ft_strncmp(filepath + slen - 4, ".ber", 4) != 0)
	{
		ft_printf("The file name must be in the format \
			<filepath/filename>.ber\n");
		return (0);
	}
	if (slen == 4)
	{
		
		return (0);
	}
	return (1);
}

int	validate_file(char *filepath)
{
	if (!is_valid_filename(filepath))
		return (ft_putstr_fd("The file name must be in the format \
			<filepath/filename>.ber\n", 2), FAIL);
	if (!is_valid_use_of_newline(filepath))
		return (ft_putstr_fd("Unexpected newline found.\n", 2), FAIL);
	return (SUCCESS);
}