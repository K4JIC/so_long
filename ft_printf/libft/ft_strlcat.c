/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:49:26 by tozaki            #+#    #+#             */
/*   Updated: 2025/10/21 18:07:44 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dlen >= size)
		return (size + slen);
	i = 0;
	while (i + dlen < size - 1 && src[i])
	{
		dst[i + dlen] = src[i];
		i++;
	}
	dst[i + dlen] = '\0';
	return (dlen + slen);
}
/*
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	dst1[20] = "hello";
	char	dst2[20] = "hello";
	char	src[] = "world";
	int		out1;
	int		out2;

	out1 = ft_strlcat(dst1, src,8);
	out2 = strlcat(dst2, src, 8);
	printf("copy : %d,%s\noriginal : %d,%s\n", out1,dst1, out2,dst2);
}
*/
