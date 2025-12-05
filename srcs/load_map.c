/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:27:37 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/05 18:23:35 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**load_map(char *filepath)
{
	int		fd;
	int		bytesize;
	char	*buf;
	int		res;
	char	**map;

	bytesize = measure_filesize(filepath);
	if (bytesize == -1)
		return (NULL);
	fd = open(filepath, O_RDONLY);
	buf = malloc(bytesize + 1);
	if (!buf)
		return (NULL);
	res = read(fd, buf, bytesize);
	if (res == -1)
		return (free(buf), NULL);
	close(fd);
	buf[bytesize] = '\0';
	map = ft_split(buf, '\n');
	if (!map)
		return (free(buf), NULL);
	return (free(buf), map);
}

void	free_map(char **map)
{
	free_sp(map);
}

// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	char	**map;

// 	(void)argc;
// 	map = load_map(argv[1]);
// 	for (int i = 0; i < 5; i++)
// 		printf("%s\n", map[i]);
// 	free_map(map);
// 	return (0);
// }