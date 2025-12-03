/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:14:44 by tozaki            #+#    #+#             */
/*   Updated: 2025/10/18 20:24:27 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ucs;
	size_t			i;

	ucs = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ucs[i] == (unsigned char)c)
			return ((void *)&ucs[i]);
		i++;
	}
	return (NULL);
}
