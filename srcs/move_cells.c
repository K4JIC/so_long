/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cells.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:10:36 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/05 19:11:15 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	swap_cell(t_game *game, t_position p1, t_position p2)
{
	char	tmp;

	if (!game || !game->map[p1.row][p1.col] || !game->map[p2.row][p2.col])
	{
		ft_putstr_fd("failed to move\n", 2);
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
