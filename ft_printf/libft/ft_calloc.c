/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:37:11 by tozaki            #+#    #+#             */
/*   Updated: 2025/10/21 19:19:47 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	len;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	len = nmemb * size;
	if (nmemb == 0 || size == 0)
		len = 1;
	mem = malloc(len);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, len);
	return (mem);
}
/*
#include <stdio.h>

int main(void)
{
	int *mem;
	size_t size;

	size = 3;
	mem = (int *)ft_calloc(3, sizeof(int));
	for (int i = 0; i < 3; i++)
		printf("mem[%d] : %d\n", i, mem[i]);
	free(mem);
	return (0);
}
*/
