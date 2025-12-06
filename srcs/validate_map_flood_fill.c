/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_flood_fill.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:05:00 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/06 13:17:06 by tozaki           ###   ########.fr       */
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
	if (flood_fill_goal(game, row + 1, col) == SUCCESS)
		return (SUCCESS);
	if (flood_fill_goal(game, row, col + 1) == SUCCESS)
		return (SUCCESS);
	if (flood_fill_goal(game, row - 1, col) == SUCCESS)
		return (SUCCESS);
	if (flood_fill_goal(game, row, col - 1) == SUCCESS)
		return (SUCCESS);
	return (FAIL);
}

int	flood_fill_collectible(t_game *game, int row, int col, int *count)
{
	char			**map;

	map = game->map;
	if (map[row][col] == '1' || map[row][col] < 0)
		return (FAIL);
	if (map[row][col] == 'C')
	{
		(*count)++;
		if (*count == game->collectible_count)
			return (SUCCESS);
	}
	map[row][col] *= -1;
	if (flood_fill_collectible(game, row + 1, col, count) == SUCCESS)
		return (SUCCESS);
	if (flood_fill_collectible(game, row, col + 1, count) == SUCCESS)
		return (SUCCESS);
	if (flood_fill_collectible(game, row - 1, col, count) == SUCCESS)
		return (SUCCESS);
	if (flood_fill_collectible(game, row, col - 1, count) == SUCCESS)
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

int	flood_fill(t_game *game)
{
	int	row;
	int	col;
	int	count;

	if (game->player.row == 0 || game->collectible_count == 0)
		return (FAIL);
	row = game->player.row;
	col = game->player.col;
	if (flood_fill_goal(game, row, col) == FAIL)
		return (FAIL);
	clean_flood(game->map);
	count = 0;
	if (flood_fill_collectible(game, row, col, &count) == FAIL)
		return (FAIL);
	clean_flood(game->map);
	return (SUCCESS);
}
