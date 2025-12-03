/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:02:26 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/16 11:21:33 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joineds;
	size_t	s1len;
	size_t	s2len;
	size_t	totallen;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	totallen = s1len + s2len;
	joineds = (char *)malloc(totallen + 1);
	if (!joineds)
		return (NULL);
	ft_memcpy(joineds, s1, s1len);
	ft_strlcat(joineds, s2, totallen + 1);
	joineds[totallen] = '\0';
	return (joineds);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*js;
// 	char	s1[] = "hello";
// 	char	s2[] = "world";

// 	js = ft_strjoin(s1, s2);
// 	printf("strjoin : %s\n", js);
// 	return (1);
// }
