/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:08:58 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/06 16:15:46 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	has_consecutive_newline(char *str)
{
	int	prev_char_is_newline;
	int	i;

	if (str[0] == '\n')
		return (1);
	prev_char_is_newline = 0;
	i = 0;
	while (str[i])
	{
		if (prev_char_is_newline == 1 && str[i] == '\n')
			return (1);
		prev_char_is_newline = 0;
		if (str[i] == '\n')
			prev_char_is_newline = 1;
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
	buf = malloc(bytesize + 1);
	if (!buf)
		return (-1);
	fd = open(filepath, O_RDONLY);
	res = read(fd, buf, bytesize);
	if (res == -1)
		return (free(buf), -1);
	close(fd);
	buf[bytesize] = '\0';
	if (has_consecutive_newline(buf))
		return (free(buf), 0);
	return (free(buf), 1);
}

int	is_valid_filename(char *filepath)
{
	size_t	fname_len;
	char	*last_slash_ptr;

	last_slash_ptr = ft_strrchr((const char *)filepath, '/');
	if (!last_slash_ptr)
		last_slash_ptr = filepath;
	fname_len = ft_strlen(last_slash_ptr + 1);
	if (ft_strncmp(last_slash_ptr + 1 + fname_len - 4, ".ber", 4) != 0)
		return (0);
	if (fname_len == 4)
		return (0);
	return (1);
}

int	validate_file(char *filepath)
{
	int	filesize;

	if (!is_valid_filename(filepath))
		return (ft_putstr_fd \
		("The file name must be in the format <filepath/filename>.ber\n", 2), \
		FAIL);
	filesize = measure_filesize(filepath);
	if (filesize == FAIL_TO_OPEN)
		return (ft_putstr_fd("Failed to open the file.\n", 2), FAIL);
	else if (filesize == FAIL_TO_READ)
		return (ft_putstr_fd("Failed to read the file.\n", 2), FAIL);
	else if (filesize == 0)
		return (ft_putstr_fd("Empty file.\n", 2), FAIL);
	if (!is_valid_use_of_newline(filepath))
		return (ft_putstr_fd("Unexpected newline found.\n", 2), FAIL);
	return (SUCCESS);
}
