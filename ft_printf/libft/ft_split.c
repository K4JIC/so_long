/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 00:41:30 by tozaki            #+#    #+#             */
/*   Updated: 2025/11/16 11:22:25 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_countwords(const char *str, char c)
{
	int	flag;
	int	count;
	int	i;

	flag = 1;
	count = 0;
	i = 0;
	while (str[i] == c && str[i])
		i++;
	while (str[i])
	{
		if (str[i] != c && flag)
			count++;
		flag = 0;
		if (str[i] == c)
			flag = 1;
		i++;
	}
	return (count);
}

static char	*ft_get_next_word(char *str[], const char c)
{
	char	*cpy;
	size_t	start;
	size_t	end;
	int		i;

	i = 0;
	while (((*str)[i] == c) && (*str)[i])
		i++;
	start = i;
	while (((*str)[i] != c) && (*str)[i])
		i++;
	end = i;
	cpy = ft_substr(*str, start, end - start);
	if (cpy == NULL)
		return (NULL);
	(*str) = *str + end + 1;
	return (cpy);
}

void	free_sp(char **sp)
{
	int	i;

	i = 0;
	while (sp[i])
	{
		if (sp[i])
			free(sp[i]);
		i++;
	}
	free(sp);
}

char	**ft_split(const char *s, char c)
{
	char	**sp;
	int		number_of_words;
	int		i;
	char	*str;

	str = (char *)s;
	number_of_words = ft_countwords(s, c);
	sp = (char **)malloc((number_of_words + 1) * sizeof(char *));
	if (!sp)
		return (NULL);
	i = 0;
	while (i < number_of_words)
	{
		sp[i] = ft_get_next_word(&str, c);
		if (!sp[i])
			free_sp(sp);
		i++;
	}
	sp[number_of_words] = NULL;
	return (sp);
}
/*
#include <stdio.h>

int main(void)
{
 char *str1 = "--anoj--sbai--sdi";
 char charset = '-';
 char **sp;
 int i = 0;

 sp = ft_split(str1, charset);
 while (i < 3)
 {
     printf("%s\n", sp[i]);
     i++;
 }
 return (0);
}  
*/
