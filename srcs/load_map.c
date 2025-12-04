/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:27:37 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/04 16:23:36 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**lst_to_arr(t_list *head)
{
	int		size;
	int		i;
	char	**map;
	t_list	*tmp;
	t_list	*next_node;
	
	size = ft_lstsize(head);
	map = malloc(sizeof(t_list) * (size + 1));
	if (map == NULL)
	{
		ft_lstclear(&head, free);
		return (NULL);
	}
	i = 0;
	tmp = head;
	while (tmp != NULL)
	{
		map[i] = tmp->content;
		next_node = tmp->next;
		free(tmp);
		tmp = next_node;
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**load_map(char *filepath)
{
	int		fd;
	char	*raw_line;
	char	*trimmed_line;
	t_list	*head;
	t_list	*new;

	head = NULL;
	fd = open(filepath, O_RDONLY);
	while (1)
	{
		raw_line = get_next_line(fd);
		if (!raw_line)
			break ;
		trimmed_line = ft_strtrim(raw_line, "\n");
		free(raw_line);
		if (trimmed_line == NULL)
		{
			ft_lstclear(&head, free);
			close(fd);
			return (NULL);
		}
		new = ft_lstnew(trimmed_line);
		if (!new)
			return (NULL);
		ft_lstadd_back(&head, new);
	}
	close(fd);
	return (lst_to_arr(head));
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	char	**map;

// 	(void)argc;
// 	map = load_map(argv[1]);
// 	for (int i = 0; i < 5; i++)
// 		printf("%s\n", map[i]);
// 	free_map(map);
// 	return (0);
// }