/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 19:51:12 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/05 16:07:01 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * - 長方形になっているか
 * - 外縁はすべて１になっているか
 * - P,Gが複数ないか
 * - マップに知らない文字がないか
 * - クリアできる形か
 */

int	is_rectangular(char **map)
{
	int	row;
	int	col;
	int	prev_col;

	prev_col = 0;
	row = 1;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
			col++;
		if (prev_col && prev_col != col)
			return (0);
		prev_col = col;
		row++;
	}
	return (1);
}

int	is_surrounded(char **map)
{
	int	row;
	int	col;
	int	rowmax;
	int	colmax;

	rowmax = 0;
	while (map[rowmax])
		rowmax++;
	colmax = 0;
	while (map[0][colmax])
		colmax++;
	col = 0;
	while (col < colmax)
	{
		if (map[0][col] != '1' || map[rowmax - 1][col] != '1')
			return (0);
		col++;
	}
	row = 0;
	while (row < rowmax)
	{
		if (map[row][0] != '1' || map[row][colmax - 1] != '1')
			return (0);
		row++;
	}
	return (1);
}

int	count_symbols(char **map, char c)
{
	int	count;
	int	row;
	int	col;

	count = 0;
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == c)
				count++;
			col++;
		}
		row++;
	}
	return (count);
}

static int	is_instr(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	is_defined_char(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (!is_instr(map[row][col], "10CPE"))
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

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

int	validate_map(t_game *game)
{
	if (!is_rectangular(game->map))
		return ((void)ft_printf("The map must be rectangular\n"), FAIL);
	if (!is_surrounded(game->map))
		return ((void)ft_printf("The map must be surrounded by '1's\n"), FAIL);
	if (!is_defined_char(game->map))
		return ((void)ft_printf\
	("The map must contain only the characters: P, E, C, 0 and 1.\n"), FAIL);
	if (count_symbols(game->map, 'P') != 1)
		return ((void)\
		ft_printf("The map must contain only one 'P' character.\n"), FAIL);
	if (count_symbols(game->map, 'E') != 1)
		return ((void)\
		ft_printf("The map must contain only one 'E' character.\n"), FAIL);
	set_player_address(game);
	if (flood_fill(game->map, game->player.row, game->player.col) != SUCCESS)
		return ((void)ft_printf("The map cannot be cleared.\n"), FAIL);
	clean_flood(game->map);
	return (SUCCESS);
}