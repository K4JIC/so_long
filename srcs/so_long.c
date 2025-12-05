/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:02:06 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/05 22:11:23 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (1);
	ft_bzero(&game, sizeof(game));
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (1);
	game.title = "so_long";
	if (launch_window(&game, argv[1]) == FAIL)
	{
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		ft_putstr_fd("Failed to launch window.\n", 2);
		return (FAIL);
	}
	ft_printf("there is %d collectible objects\n", game.collectible_count);
	mlx_hook(game.win, KeyPress, KeyPressMask, deal_keys, &game);
	mlx_hook(game.win, DestroyNotify, StructureNotifyMask, deal_button, &game);
	mlx_loop(game.mlx);
	close_mlx(&game);
	return (0);
}
