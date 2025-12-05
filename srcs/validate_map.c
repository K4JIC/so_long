/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:00:19 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/05 19:26:01 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(t_game *game)
{
	if (!is_rectangular(game->map))
		return ((void)ft_putstr_fd("The map must be rectangular.\n", 2), FAIL);
	if (!is_surrounded(game->map))
		return ((void)ft_putstr_fd("The map must be surrounded by '1's.\n", 2), \
		FAIL);
	if (!is_defined_char(game->map))
		return ((void)ft_putstr_fd \
		("The map must contain only the characters: P, E, C, 0 and 1.\n", 2), \
		FAIL);
	if (count_symbols(game->map, 'P') != 1)
		return ((void) \
		ft_putstr_fd("The map must contain only one 'P' character.\n", 2), \
		FAIL);
	if (count_symbols(game->map, 'E') != 1)
		return ((void) \
		ft_putstr_fd("The map must contain only one 'E' character.\n", 2), \
		FAIL);
	set_player_address(game);
	if (flood_fill(game->map, game->player.row, game->player.col) != SUCCESS)
		return ((void)ft_putstr_fd("The map cannot be cleared.\n", 2), FAIL);
	clean_flood(game->map);
	return (SUCCESS);
}
