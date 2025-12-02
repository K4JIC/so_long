/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:01:36 by tozaki            #+#    #+#             */
/*   Updated: 2025/10/22 23:58:51 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>

void	caesar(unsigned int i, char *s) {*s = (char)i + *s;}

int	main(void)
{
	char	s[] = "ozaki tomoya";
	ft_striteri(s, (*caesar));
	printf("%s\n", s);
	return (0);
}
*/
