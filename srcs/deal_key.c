/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:49:01 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/05 19:11:04 by tozaki           ###   ########.fr       */
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


