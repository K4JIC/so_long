/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:49:01 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/04 19:50:47 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(t_game *game, int row, int col);

int	deal_key(int key, t_game *game)
{
	if (key == XK_Escape)
		mlx_loop_end(game->mlx);
	else if (key == XK_W || key == XK_Up)
		move_player(game, -1, 0);
	else if (key == XK_A || key == XK_Left)
		move_player(game, 0, -1);
	else if (key == XK_S || key == XK_Down)
		move_player(game, 1, 0);
	else if (key == XK_D || key == XK_Right)
		move_player(game, 0, 1);
	return (0);
}

/**
 * - Pの位置を探す
 * - Pが動けるか判断
 * - Pを動かす（移動先のマスと入れ替え）
 * - 画面を描画
 * 
 */

int	swap_cell(t_game *game, t_position p1, t_position p2)
{
	char	tmp;

	if (!game || !game->map[p1.row][p1.col] || !game->map[p2.row][p2.col])
	{
		ft_printf("failed to move\n");
		return (FAIL);
	}
	tmp = game->map[p1.row][p1.col];
	game->map[p1.row][p1.col] = game->map[p2.row][p2.col];
	game->map[p2.row][p2.col] = tmp;
	return (SUCCESS);
}

int	delete_cell(t_game *game, t_position p)
{
	if (!game || !game->map[p.row][p.col])
		return (FAIL);
	game->map[p.row][p.col] = '0';
	return (SUCCESS);
}

int	get_collectible(t_game *game, t_position p)
{
	if (!game || !game->map[p.row][p.col])
		return (FAIL);
	delete_cell(game, p);
	game->collectible_count--;
	ft_printf("%d collectible object is left\n", game->collectible_count);
	return (SUCCESS);
}

int	get_goal(t_game *game, t_position p)
{
	if (!game || !game->map[p.row][p.col])
		return (FAIL);
	if (game->collectible_count == 0)
	{
		ft_printf("game clear ! congratulation!!!\n");
		mlx_loop_end(game->mlx);
	}
	return (SUCCESS);
}

int	move_player(t_game *game, int row, int col)
{
	t_position	destination;

	destination.row = game->player.row + row;
	destination.col = game->player.col + col;
	
	if (!is_accessible(game, destination))
		return (FAIL);
	else
	{
		if (is_goal(game, destination))
			get_goal(game, destination);
		if (is_collectible(game, destination))
			get_collectible(game, destination);
		if (swap_cell(game, game->player, destination))
			return (FAIL);
		game->player = destination;
	}
	draw_window(game);
	return (SUCCESS);
}