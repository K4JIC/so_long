/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:45:37 by tozaki            #+#    #+#             */
/*   Updated: 2025/10/22 23:55:00 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list	*cur;

	if (!lst || !f)
		return ;
	cur = lst;
	while (cur)
	{
		f(cur->content);
		cur = cur->next;
	}
}
