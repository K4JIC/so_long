/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:20:18 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/03 20:01:54 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * - mapを読み込む "load_map"
 * - windowのサイズを決める
 * - windowを確保する <mlx_new_window>
 * - imageを読み込む <mlx_xpm_file_to_image>
 * - mapの情報に従ってimageをwindowに貼り付ける <mlx_put_image_to_window>
 * param : t_game game, filepath
 * return : t_game game (game->win, game->imgs更新)
 */

#include "so_long.h"

int	load_imgs(t_game *game)
{
	int	w;
	int	h;

	game->imgs.floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &w, &h);
	game->imgs.wall = mlx_xpm_file_to_image(game->mlx, WALL, &w, &h);
	game->imgs.player = mlx_xpm_file_to_image(game->mlx, PLAYER, &w, &h);
	game->imgs.goal = mlx_xpm_file_to_image(game->mlx, GOAL, &w, &h);
	game->imgs.collectible = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE, \
												&w, &h);
	if (!game->imgs.floor || !game->imgs.wall || !game->imgs.player || \
		!game->imgs.goal || !game->imgs.collectible)
	{
		write(2, "failed to load images\n", 23);
		return (FAIL);
	}
	return (SUCCESS);
}

void	set_window_size(t_game *game)
{
	int	i;

	i = 0;
	game->win_width = ft_strlen(game->map[0]) * ISIZE;
	while (game->map[i])
	{
		game->win_height += ISIZE;
		i++;
	}
}

int	put_imgs(t_game *ga, char c, int x, int y)
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

int	fill_window(t_game *game)
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

int	launch_window(t_game *game, char *filepath)
{
	game->map = load_map(filepath);
	if (!game->map)
		return (FAIL);
	if (load_imgs(game) == FAIL)
		return (FAIL);
	set_window_size(game);
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height, \
							game->title);
	if (!game->win)
		return (FAIL);
	if (fill_window(game) == FAIL)
		return (FAIL);
	return (SUCCESS);
}