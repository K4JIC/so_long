/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 19:51:12 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/05 19:04:31 by tozaki           ###   ########.fr       */
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
