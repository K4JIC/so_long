/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:02:50 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/03 21:07:11 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_imgs(t_game *game)
{
	if (game->imgs.collectible)
		mlx_destroy_image(game->mlx, game->imgs.collectible);
	if (game->imgs.floor)
		mlx_destroy_image(game->mlx, game->imgs.floor);
	if (game->imgs.wall)
		mlx_destroy_image(game->mlx, game->imgs.wall);
	if (game->imgs.player)
		mlx_destroy_image(game->mlx, game->imgs.player);
	if (game->imgs.goal)
		mlx_destroy_image(game->mlx, game->imgs.goal);
}

void	close_mlx(t_game *game)
{
	if (game->map)
		free_map(game->map);
	free_imgs(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
}