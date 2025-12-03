/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 14:46:16 by tozaki            #+#    #+#             */
/*   Updated: 2025/10/22 18:38:04 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	sublen;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	sublen = slen - start;
	if (sublen > len)
		sublen = len;
	if (start >= slen)
		sublen = 0;
	sub = (char *)malloc(sublen * sizeof(char) + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < sublen && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
#include <stdio.h>

int	main(void)
{
	char			s[] = "helloworld";
	unsigned int	start = 3;
	size_t 			len = 4;
	char			*sub;

	sub = ft_substr(s, start, len);
	printf("substr : %s\n", sub);
	free(sub);
	return (1);
}
*/
