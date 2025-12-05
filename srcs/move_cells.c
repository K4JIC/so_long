/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cells.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:10:36 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/05 22:09:08 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	swap_cell(t_game *game, t_position pos1, t_position pos2)
{
	char	tmp;

	if (!game || !game->map[pos1.row][pos1.col]
		|| !game->map[pos2.row][pos2.col])
	{
		ft_putstr_fd("failed to move\n", 2);
		return (FAIL);
	}
	tmp = game->map[pos1.row][pos1.col];
	game->map[pos1.row][pos1.col] = game->map[pos2.row][pos2.col];
	game->map[pos2.row][pos2.col] = tmp;
	return (SUCCESS);
}

int	delete_cell(t_game *game, t_position pos)
{
	if (!game || !game->map[pos.row][pos.col])
		return (FAIL);
	game->map[pos.row][pos.col] = '0';
	return (SUCCESS);
}

int	get_collectible(t_game *game, t_position pos)
{
	if (!game || !game->map[pos.row][pos.col])
		return (FAIL);
	delete_cell(game, pos);
	game->collectible_count -= 1;
	ft_printf("%d collectible object is left\n", game->collectible_count);
	return (SUCCESS);
}

int	get_goal(t_game *game, t_position pos)
{
	if (!game || !game->map[pos.row][pos.col])
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
	if (is_goal(game, destination))
		get_goal(game, destination);
	if (is_collectible(game, destination))
		get_collectible(game, destination);
	if (swap_cell(game, game->player, destination))
		return (FAIL);
	game->player = destination;
	game->move_count++;
	ft_printf("Player moved %d step\n", game->move_count);
	ft_printf("%d collectible object is left\n", game->collectible_count);
	draw_window(game);
	return (SUCCESS);
}
