/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:53:55 by tozaki            #+#    #+#             */
/*   Updated: 2025/10/22 23:55:39 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*cur;
	t_list	*ncur;

	if (!lst || !f || !del)
		return (NULL);
	nlst = NULL;
	cur = lst;
	while (cur)
	{
		ncur = ft_lstnew((*f)(cur->content));
		if (!ncur)
		{
			ft_lstclear(&nlst, del);
			return (NULL);
		}
		ft_lstadd_back(&nlst, ncur);
		cur = cur->next;
	}
	return (nlst);
}
