/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:20:18 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/05 16:39:55 by tozaki           ###   ########.fr       */
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

static int	load_imgs(t_game *game)
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

static void	set_window_size(t_game *game)
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

void	set_player_address(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			if (game->map[row][col] == 'P')
			{
				game->player.row = row;
				game->player.col = col;
				return ;
			}
			col++;
		}
		row++;
	}
}

void	set_number_of_collectible(t_game *game)
{
	int	count;
	int	row;
	int	col;

	count = 0;
	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			if (game->map[row][col] == 'C')
				count++;
			col++;
		}
		row++;
	}
	game->collectible_count = count;
}

int	launch_window(t_game *game, char *filepath)
{
	if (validate_file(filepath) == FAIL)
		return (FAIL);
	game->map = load_map(filepath);
	if (!game->map)
		return (FAIL);
	if (validate_map(game) == FAIL)
		return (free_map(game->map), FAIL);
	if (load_imgs(game) == FAIL)
		return (free_map(game->map), FAIL);
	set_window_size(game);
	set_player_address(game);
	set_number_of_collectible(game);
	ft_printf("player is at (%d, %d)\n", game->player.col, game->player.row);
	ft_printf("there is %d collectible objects\n", game->collectible_count);
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height, \
							game->title);
	if (!game->win)
		return (free_map(game->map), FAIL);
	if (draw_window(game) == FAIL)
		return (mlx_destroy_window(game->mlx, game->win), free_map(game->map), \
		FAIL);
	return (SUCCESS);
}