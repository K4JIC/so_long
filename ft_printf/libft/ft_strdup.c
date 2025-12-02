/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:54:24 by tozaki            #+#    #+#             */
/*   Updated: 2025/10/22 23:58:23 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*cpy;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	cpy = (char *)malloc(len * sizeof(char) + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
/*
#include <stdio.h>

int	main(void)
{
	char s[] = "aiueo";
	char *cpy;

	cpy = ft_strdup(s);
	printf("%s\n", cpy);
	return (1);
}
*/