/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:08:46 by tozaki            #+#    #+#             */
/*   Updated: 2025/10/17 18:09:40 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	ft_isupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

static int	ft_islower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if (c == EOF)
		return (0);
	if (ft_isupper(c) || ft_islower(c))
		return (1);
	return (0);
}

/*
#include <ctype.h>
#include <stdio.h>

void	test(int c)
{
	printf("--%c--\n", c);
	printf("copy     : %d\n", ft_isalpha(c));
	printf("original : %d\n\n", isalpha(c));
}

int	main(void)
{
	char c;

	c = 'a';
	test(c);
	test(64);
	return (1);
}
*/
