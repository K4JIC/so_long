/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:55:52 by tozaki            #+#    #+#             */
/*   Updated: 2025/10/23 03:36:57 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*cs;
	size_t			i;

	if (!s)
		return ;
	cs = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		cs[i] = 0;
		i++;
	}
}
