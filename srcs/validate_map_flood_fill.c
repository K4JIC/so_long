/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_flood_fill.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:05:00 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/05 23:09:54 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill_goal(t_game *game, int row, int col)
{
	char	**map;

	map = game->map;
	if (map[row][col] == '1' || map[row][col] < 0)
		return (FAIL);
	if (map[row][col] == 'E')
		return (SUCCESS);
	map[row][col] *= -1;
	if (flood_fill_goal(map, row + 1, col) == SUCCESS)
		return (SUCCESS);
	if (flood_fill_goal(map, row, col + 1) == SUCCESS)
		return (SUCCESS);
	if (flood_fill_goal(map, row - 1, col) == SUCCESS)
		return (SUCCESS);
	if (flood_fill_goal(map, row, col - 1) == SUCCESS)
		return (SUCCESS);
	return (FAIL);
}

int	flood_fill_collectible(t_game , int row, int col)
{
	if (map[row][col] == '1' || map[row][col] < 0)
		return (FAIL);
	if (map[row][col] == 'C')
	
		return (SUCCESS);
	map[row][col] *= -1;
	if (flood_fill_collectible(map, row + 1, col) == SUCCESS)
		return (SUCCESS);
	if (flood_fill_collectible(map, row, col + 1) == SUCCESS)
		return (SUCCESS);
	if (flood_fill_collectible(map, row - 1, col) == SUCCESS)
		return (SUCCESS);
	if (flood_fill_collectible(map, row, col - 1) == SUCCESS)
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
