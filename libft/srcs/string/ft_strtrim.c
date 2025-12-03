/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:49:19 by tozaki            #+#    #+#             */
/*   Updated: 2025/10/25 16:16:25 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_ischrset(int c, const char *chrset)
{
	int	i;

	i = 0;
	while (chrset[i])
	{
		if (c == chrset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char		*trimmeds;
	size_t		start;
	size_t		end;

	start = 0;
	while (ft_ischrset(s1[start], set) && s1[start])
		start++;
	end = ft_strlen(s1);
	while (ft_ischrset(s1[end - 1], set) && end > start)
		end--;
	if (end - start <= 0)
	{
		trimmeds = (char *)malloc(1);
		if (!trimmeds)
			return (NULL);
		trimmeds[0] = 0;
		return (trimmeds);
	}
	trimmeds = ft_substr(s1, start, end - start);
	return (trimmeds);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*trimmeds;
	char	set[] = " !";

	trimmeds = ft_strtrim("   hello world!!   !!", set);
	printf("trimmed:%s\n", trimmeds);
	free(trimmeds);
	trimmeds = ft_strtrim("   h!!   !!", set);
	printf("trimmed:%s\n", trimmeds);
	free(trimmeds);
	trimmeds = ft_strtrim("   !!   !!", set);
	printf("trimmed:%s\n", trimmeds);
	free(trimmeds);
	return (0);
}
*/
