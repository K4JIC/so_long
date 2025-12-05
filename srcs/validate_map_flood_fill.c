/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_flood_fill.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:05:00 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/05 19:05:12 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(char **map, int row, int col)
{
	if (map[row][col] == '1' || map[row][col] < 0)
		return (FAIL);
	if (map[row][col] == 'E')
		return (SUCCESS);
	map[row][col] *= -1;
	if (flood_fill(map, row + 1, col) == SUCCESS)
		return (SUCCESS);
	if (flood_fill(map, row, col + 1) == SUCCESS)
		return (SUCCESS);
	if (flood_fill(map, row - 1, col) == SUCCESS)
		return (SUCCESS);
	if (flood_fill(map, row, col - 1) == SUCCESS)
		return (SUCCESS);
	return (FAIL);
}

void	clean_flood(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] < 0)
				map[row][col] *= -1;
			col++;
		}
		row++;
	}
}
