/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celltype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:31:16 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/04 18:38:08 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_cell(t_game *game, t_position p, char c)
{
	if (game->map[p.row][p.col] == c)
		return (1);
	return (0);
}

int	is_accessible(t_game *game, t_position p)
{
	return (!is_cell(game, p, '1'));
}

int	is_collectible(t_game *game, t_position p)
{
	return (is_cell(game, p, 'C'));
}

int	is_goal(t_game *game, t_position p)
{
	return (is_cell(game, p, 'E'));
}