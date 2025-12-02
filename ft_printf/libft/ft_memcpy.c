/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:43:25 by tozaki            #+#    #+#             */
/*   Updated: 2025/10/22 17:50:53 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ucdest;
	unsigned char	*ucsrc;
	size_t			i;

	if (!n)
		return (dest);
	if (!dest && !src)
		return (NULL);
	ucdest = (unsigned char *)dest;
	ucsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ucdest[i] = ucsrc[i];
		i++;
	}
	return (dest);
}
