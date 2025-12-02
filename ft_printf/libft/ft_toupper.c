/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:48:23 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/16 11:21:16 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_toupper(int c)
{
	unsigned char	ucc;

	ucc = (unsigned char)c;
	if (c == EOF)
		return (EOF);
	if ('a' <= c && c <= 'z')
		return (c ^ 32);
	return (ucc);
}
/*
#ifdef TEST
#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	main(void)
{
	char	charset[] = {
		'c',
		'a',
		'z',
		254,
		255,
		-1,
		0
	};
	int	len = ft_strlen(charset);
	for (int	i = 0; i < len; i++)
	{
		printf("output  : %d\n", ft_toupper(charset[i]));
		printf("expected: %d\n\n", toupper(charset[i]));
	}
}

#endif
*/
