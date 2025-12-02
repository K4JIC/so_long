/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:40:09 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/15 04:28:17 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*ucs;
	unsigned char	ucc;
	size_t			i;

	if (!s || !n)
		return (NULL);
	ucs = (unsigned char *)s;
	ucc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ucs[i] == ucc)
			return ((void *)&ucs[i]);
		i++;
	}
	return (NULL);
}

char	*ft_submem(const char *s, size_t n)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (n + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < n)
	{
		ret[i] = s[i];
		i++;
	}
	ret[n] = '\0';
	return (ret);
}

t_save	*lst_new(char *content, size_t len, int fd)
{
	t_save	*new_save;

	new_save = (t_save *)malloc(sizeof(t_save) * 1);
	if (!new_save)
		return (NULL);
	if (content && len > 0)
	{
		new_save->content = ft_submem(content, len);
		if (!new_save->content)
			return (free(new_save), NULL);
	}
	else
		new_save->content = NULL;
	new_save->len = len;
	new_save->fd = fd;
	new_save->next = NULL;
	return (new_save);
}

void	lst_add_front(t_save **save, t_save *new_save)
{
	if (!new_save)
		return ;
	if (!save || !*save)
	{
		*save = new_save;
		return ;
	}
	new_save->next = *save;
	*save = new_save;
}

void	remove_lst(t_save **root, t_save **target)
{
	t_save	*cur;
	t_save	*prev;

	if (!(*root) || !*target)
		return ;
	cur = *root;
	prev = NULL;
	while (cur)
	{
		if (cur == *target)
		{
			if (prev)
				prev->next = cur->next;
			else
				*root = cur->next;
			if (cur->content)
				free(cur->content);
			free(cur);
			*target = NULL;
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}
