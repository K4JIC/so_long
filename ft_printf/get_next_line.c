/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:39:43 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/23 14:44:14 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static t_save	*find_or_create_save(t_save **root, int fd)
{
	t_save	*cur;
	t_save	*new;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	cur = *root;
	while (cur)
	{
		if (cur->fd == fd)
			return (cur);
		cur = cur->next;
	}
	new = lst_new(NULL, 0, fd);
	if (!new)
		return (NULL);
	lst_add_front(root, new);
	return (new);
}

static int	read_to_save(t_save *save)
{
	int		bytesize;
	char	*buf;
	char	*tmp;
	int		i;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (-1);
	bytesize = read(save->fd, buf, BUFFER_SIZE);
	if (bytesize <= 0)
		return (free(buf), bytesize);
	tmp = save->content;
	save->content = (char *)malloc(sizeof(char) * (save->len + bytesize));
	if (!save->content)
		return (free(tmp), free(buf), -1);
	i = -1;
	while (++i < (int)save->len && tmp)
		save->content[i] = tmp[i];
	i = -1;
	while (++i < (int)bytesize)
		save->content[save->len + i] = buf[i];
	save->len += bytesize;
	return (free(tmp), free(buf), bytesize);
}

static char	*extract_line(t_save *save, int linelen, t_save *root, \
		int bytesize)
{
	char	*line;
	char	*tmp;
	char	*nlptr;

	line = ft_submem(save->content, linelen);
	if (!line)
		return (NULL);
	save->len -= linelen;
	tmp = save->content;
	nlptr = (char *)ft_memchr(tmp, '\n', linelen);
	if (nlptr && save->len > 0)
	{
		save->content = ft_submem(nlptr + 1, save->len);
		if (!save->content)
		{
			save->content = tmp;
			save->len += linelen;
			return (free(line), NULL);
		}
	}
	else
		save->content = NULL;
	if (bytesize == 0 && save->len)
		remove_lst(&root, &save);
	return (free(tmp), line);
}

static char	*generate_line(t_save *save, t_save *root, int bytesize)
{
	char	*nlptr;
	int		linelen;
	char	*line;

	if (!save)
		return (NULL);
	nlptr = (char *)ft_memchr(save->content, '\n', save->len);
	if (!nlptr)
		linelen = save->len;
	else
		linelen = nlptr - save->content + 1;
	line = extract_line(save, linelen, root, bytesize);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_save	*root = NULL;
	t_save			*save;
	int				bytesize;
	char			*line;

	save = find_or_create_save(&root, fd);
	if (!save)
		return (NULL);
	bytesize = 1;
	if (save->content && ft_memchr(save->content, '\n', save->len))
	{
		line = generate_line(save, root, bytesize);
		if (!line)
			return (remove_lst(&root, &save), NULL);
		return (line);
	}
	while (bytesize > 0 && !(ft_memchr(save->content, '\n', save->len)))
		bytesize = read_to_save(save);
	if (bytesize == -1 || !save->len)
		return (remove_lst(&root, &save), NULL);
	line = generate_line(save, root, bytesize);
	if (!line)
		return (remove_lst(&root, &save), NULL);
	return (line);
}
