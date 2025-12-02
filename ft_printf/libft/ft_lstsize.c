/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:48:00 by tozaki            #+#    #+#             */
/*   Updated: 2025/10/22 18:32:50 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*cur;
	int		len;

	if (!lst)
		return (0);
	cur = lst;
	len = 1;
	while (cur->next)
	{
		cur = cur->next;
		len++;
	}
	return (len);
}
