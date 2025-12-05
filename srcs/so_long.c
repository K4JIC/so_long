/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:02:06 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/05 18:40:40 by tozaki           ###   ########.fr       */
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
	game.title = "so_long";
	if (launch_window(&game, argv[1]) == FAIL)
		return (mlx_destroy_display(game.mlx), free(game.mlx), FAIL);
	mlx_key_hook(game.win, deal_key, &game);
	game.end_loop = 0;
	mlx_loop(game.mlx);
	close_mlx(&game);
	return (0);
}
