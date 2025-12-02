/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:34:52 by tozaki            #+#    #+#             */
/*   Updated: 2025/10/20 19:18:16 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nt;

	nt = (t_list *)malloc(sizeof(t_list));
	if (!nt)
		return (NULL);
	nt->content = content;
	nt->next = NULL;
	return (nt);
}
/*
#include <stdio.h>

int main(void)
{
	t_list *t;
	t = ft_lstnew("amenbo");
	printf("%s\n", (char *)t->content);
}
*/
