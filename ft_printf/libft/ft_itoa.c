/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:01:14 by tozaki            #+#    #+#             */
/*   Updated: 2025/10/22 18:30:34 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_intlen(long n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long		num;
	size_t		len;
	int			sign;
	char		*ascii;

	num = n;
	len = ft_intlen(num);
	sign = (num < 0);
	if (num < 0)
		num *= -1;
	ascii = (char *)malloc((sign + len) * sizeof(char) + 1);
	if (!ascii)
		return (NULL);
	ascii[sign + len] = '\0';
	while (len)
	{
		ascii[sign + len - 1] = num % 10 + '0';
		num /= 10;
		len--;
	}
	if (sign == 1)
		ascii[0] = '-';
	return (ascii);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_itoa(0));            // "0"
	printf("%s\n", ft_itoa(42));           // "42"
	printf("%s\n", ft_itoa(-42));          // "-42"
	printf("%s\n", ft_itoa(2147483647));   // "2147483647"
	printf("%s\n", ft_itoa(-2147483648));  // "-2147483648"
}
*/
