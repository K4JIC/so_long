/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:57:00 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/14 17:33:28 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return ((9 <= c && c <= 13) || c == 32);
}

int	ft_atoi(const char *nptr)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return ((int)(sign * res));
}

//#include <stdio.h>

//int	main(int argc,char **argv)
//{
//	(void)argc;
//	printf("%d\n", ft_atoi(argv[1]));
//	printf("%d\n", ft_atoi(argv[1]));
//	printf("%d\n", ft_atoi(argv[1]));
//	printf("%d\n", ft_atoi(argv[1]));
//	printf("%d\n", ft_atoi(argv[1]));
//	printf("%d\n", ft_atoi(argv[1]));
//	printf("%d\n", ft_atoi(argv[1]));
//	printf("%d\n", ft_atoi(argv[1]));
//	printf("%d\n", ft_atoi(argv[1]));
//	printf("%d\n", ft_atoi(argv[1]));
//	printf("%d\n", ft_atoi(argv[1]));
//	printf("%d\n", ft_atoi(argv[1]));
//	return (0);
//}
