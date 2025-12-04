/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:18:27 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/04 18:19:13 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	put_imgs(t_game *ga, char c, int x, int y)
{
	int	res;

	res = 0;
	if (c == '0')
		res = mlx_put_image_to_window(ga->mlx, ga->win, ga->imgs.floor, x, y);
	else if (c == '1')
		res = mlx_put_image_to_window(ga->mlx, ga->win, ga->imgs.wall, x, y);
	else if (c == 'C')
		res = mlx_put_image_to_window(ga->mlx, ga->win, ga->imgs.collectible, \
			x, y);
	else if (c == 'P')
		res = mlx_put_image_to_window(ga->mlx, ga->win, ga->imgs.player, x, y);
	else if (c == 'E')
		res = mlx_put_image_to_window(ga->mlx, ga->win, ga->imgs.goal, x, y);
	if (!res)
		return (FAIL);
	return (SUCCESS);
}

int	draw_window(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			// if (!put_imgs(game, game->map[row][col], col * ISIZE, row * ISIZE))
			// 	return (FAIL);
			put_imgs(game, game->map[row][col], col * ISIZE, row * ISIZE);
			col++;
		}
		row++;
	}
	return (SUCCESS);
}