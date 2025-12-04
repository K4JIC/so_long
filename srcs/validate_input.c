/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 21:08:58 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/04 22:02:44 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_mapfilename(char *filepath)
{
	size_t	slen;

	slen = ft_strlen(filepath);
	if (ft_strncmp(filepath + slen - 4, ".ber", 4) != 0)
	{
		ft_printf("The file name must be in the format \
			<filepath/filename>.ber\n");
		return (FAIL);
	}
	if (slen == 4)
	{
		ft_printf("The file name must be in the format \
			<filepath/filename>.ber\n");
		return (FAIL);
	}
}