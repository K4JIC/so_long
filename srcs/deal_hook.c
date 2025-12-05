/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:49:01 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/05 21:46:40 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	deal_keys(int key, t_game *game)
{
	if (key == XK_Escape)
		mlx_loop_end(game->mlx);
	else if (key == XK_w || key == XK_Up)
		move_player(game, -1, 0);
	else if (key == XK_a || key == XK_Left)
		move_player(game, 0, -1);
	else if (key == XK_s || key == XK_Down)
		move_player(game, 1, 0);
	else if (key == XK_d || key == XK_Right)
		move_player(game, 0, 1);
	return (0);
}

int	deal_button(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}
