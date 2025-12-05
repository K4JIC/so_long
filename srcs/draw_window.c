/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:18:27 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/05 18:50:49 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * int mlx_put_image_to_window() always returns (0).
 * so we cannot use it for detecting error.
 */

static void	put_imgs(t_game *ga, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(ga->mlx, ga->win, ga->imgs.floor, x, y);
	else if (c == '1')
		mlx_put_image_to_window(ga->mlx, ga->win, ga->imgs.wall, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(ga->mlx, ga->win, ga->imgs.collectible, \
			x, y);
	else if (c == 'P')
		mlx_put_image_to_window(ga->mlx, ga->win, ga->imgs.player, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(ga->mlx, ga->win, ga->imgs.goal, x, y);
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
			put_imgs(game, game->map[row][col], col * ISIZE, row * ISIZE);
			col++;
		}
		row++;
	}
	return (SUCCESS);
}
