/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:42:38 by tozaki            #+#    #+#             */
/*   Updated: 2025/10/22 16:25:07 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ucs;
	size_t			i;

	ucs = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ucs[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
