/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:49:11 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/03 15:27:46 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# if BUFFER_SIZE > 600000000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define OPEN_MAX 65535
# include <stddef.h>

typedef struct s_save
{
	char			*content;
	size_t			len;
	int				fd;
	struct s_save	*next;
}	t_save;

/*gnl*/
char	*get_next_line(int fd);

/*utils*/
char	*ft_submem(const char *s, size_t n);
t_save	*lst_new(char *content, size_t len, int fd);
void	lst_add_front(t_save **save, t_save *new_save);
void	remove_lst(t_save **root, t_save **target);
#endif
