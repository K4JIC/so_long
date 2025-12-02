/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:15:32 by tozaki            #+#    #+#             */
/*   Updated: 2025/10/21 16:11:32 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	slen;

	slen = ft_strlen(s);
	while (slen + 1)
	{
		if (s[slen] == (char)c)
			return ((char *)&s[slen]);
		slen--;
	}
	return (NULL);
}
/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[] = "tripouille";
	char s2[] = "ltripouiel";
	char s3[] = "";
	printf("1 %d\n", ft_strrchr(s, 't') == s);
	printf("2 %s %s\n", ft_strrchr(s, 'l'),  s + 8);
	printf("3 %d\n", ft_strrchr(s2, 'l') == s2 + 9);
	printf("4 %d\n", ft_strrchr(s, 'z') == NULL);
	printf("5 %d\n", ft_strrchr(s, 0) == s + strlen(s));
	printf("6 %d\n", ft_strrchr(s, 't' + 256) == s);
	char * empty = (char*)calloc(1, 1);
	printf("7 %d\n", ft_strrchr(empty, 'V') == NULL);
	printf("8 %d\n", ft_strrchr(s3, 0) == s3);
	return (0);
}
*/
