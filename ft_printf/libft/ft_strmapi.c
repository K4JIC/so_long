/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:43:08 by tozaki            #+#    #+#             */
/*   Updated: 2025/10/22 18:36:38 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*res;
	size_t			len;
	unsigned int	i;

	len = ft_strlen(s);
	res = (char *)malloc(len * sizeof(char) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
#include <stdio.h>

char	caesar(unsigned int i, char c) {return((char)i + c);}

int	main(void)
{
	char	s[] = "ozaki tomoya";

	printf("%s\n", ft_strmapi(s, (*caesar)));
	return (0);
}
*/