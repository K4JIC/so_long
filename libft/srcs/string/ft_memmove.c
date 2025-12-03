/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:05:26 by tozaki            #+#    #+#             */
/*   Updated: 2025/10/22 17:39:16 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ucdest;
	unsigned char	*ucsrc;
	size_t			i;

	if (!dest && !src && !n)
		return (NULL);
	ucdest = (unsigned char *)dest;
	ucsrc = (unsigned char *)src;
	i = 0;
	if (dest <= src)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		while (i < n)
		{
			ucdest[n - i - 1] = ucsrc[n - i - 1];
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[] = "aiueo";
	char	*dest;

	dest = src - 1;
	ft_memmove(dest, src, 5);
	printf("%s\n", dest);
}
*/
