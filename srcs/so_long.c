/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:02:06 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/02 20:22:02 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	if (param)
		(void)key;
	ft_putchar('x');
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		width = 960;
	int		hight = 960;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "test");
	// img_ptr = mlx_new_image(mlx_ptr, 100, 100);
	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "../imgs/tile.xpm", &width, &hight);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 100, 100);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}
