/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:12:34 by tozaki            #+#    #+#             */
/*   Updated: 2025/10/22 23:52:40 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cur;
	t_list	*tmp;

	if (!lst || !(*lst) || !del)
		return ;
	cur = *lst;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		ft_lstdelone(tmp, *del);
	}
	*lst = NULL;
}
