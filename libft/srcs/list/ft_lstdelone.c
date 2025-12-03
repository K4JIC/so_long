/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:45:43 by tozaki            #+#    #+#             */
/*   Updated: 2025/10/22 23:54:42 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	*fir = ft_lstnew("amenbo");
	t_list	*sec = ft_lstnew("akaina");
	t_list	*thi = ft_lstnew(ft_strdup("aiueo"));

	ft_lstadd_back(&fir, sec);
	ft_lstadd_back(&fir, thi);
	printf("first : %s\n", (char*)fir->content);
	printf("second : %s\n", (char*)fir->next->content);
	printf("third : %s\n", (char*)fir->next->next->content);

	ft_lstdelone(fir->next->next, *free);
	printf("first : %s\n", (char*)fir->content);
	printf("second : %s\n", (char*)fir->next->content);
	printf("third : %s\n", (char*)fir->next->next->content);
	return (0);
}
*/
