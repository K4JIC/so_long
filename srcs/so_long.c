/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:02:06 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/03 21:25:08 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"
#include "so_long.h"
#include "libft.h"

int	deal_key(int key, t_game *game)
{
	if (key == ESC)
		key++;
	close_mlx(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (1);
	ft_bzero(&game, sizeof(game));
	game.mlx = mlx_init();
	game.title = "test";
	launch_window(&game, argv[1]);
	// game.win = mlx_new_window(game.mlx, 1000, 1000, "test");
	// game.imgs.floor = mlx_xpm_file_to_image(game.mlx, "imgs/cave.xpm", &width, &hight);
	// mlx_put_image_to_window(game.mlx, game.win, game.imgs.floor, 100, 100);
	mlx_key_hook(game.win, deal_key, &game);
	mlx_loop(game.mlx);
	return(0);
}
