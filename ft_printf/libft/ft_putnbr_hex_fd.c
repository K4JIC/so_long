/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:37:44 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/16 05:19:53 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hex_fd(unsigned int n, char upper_or_lower, int fd)
{
	char	*base;
	int		ret;
	int		count;

	if (upper_or_lower == 'x')
	{
		base = "0123456789abcdef";
	}
	else if (upper_or_lower == 'X')
	{
		base = "0123456789ABCDEF";
	}
	else
		return (-1);
	count = 0;
	ret = ft_putnbr_base_ui_fd(n, 16, base, fd);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}
/*
int	main(void)
{
	ft_putnbr_hex_fd(1666666, 'x', 1);
	return (0);
}
*/
