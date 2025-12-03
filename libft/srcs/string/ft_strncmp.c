/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:22:59 by tozaki            #+#    #+#             */
/*   Updated: 2025/10/21 16:18:45 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ucs1;
	unsigned char	*ucs2;
	size_t			i;

	if (n == 0)
		return (0);
	ucs1 = (unsigned char *)s1;
	ucs2 = (unsigned char *)s2;
	i = 0;
	while ((ucs1[i] == ucs2[i]) && ucs1[i] && ucs2[i] && i < n - 1)
		i++;
	return (ucs1[i] - ucs2[i]);
}
/*
#include <stdio.h>

int	main(void)
{
	char s1[] = "aiueo";
	char s2[] = "aiuro";
	int	i;

	i = ft_strncmp(s1, s2, 5);
	printf("%d\n", i);
	return (0);
}
*/
