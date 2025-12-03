/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:14:36 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/03 21:23:54 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "get_next_line.h"
#include "libft.h"
#include "mlx.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

# define FLOOR "imgs/cave.xpm"
# define WALL "imgs/wall.xpm"
# define PLAYER "imgs/terminal.xpm"
# define GOAL "imgs/python.xpm"
# define COLLECTIBLE "imgs/c.xpm"
# define ISIZE 32

# define ESC 27
# define W 87
# define A 65
# define S 83
# define D 68

# define SUCCESS 0
# define FAIL 1

typedef struct s_imgs
{
	void	*floor;
	void	*wall;
	void	*player;
	void	*goal;
	void	*collectible;
}			t_imgs;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		win_height;
	int		win_width;
	char	*title;
	char	**map;
	t_imgs	imgs;
}			t_game;

/*load_map*/
char	**load_map(char *filepath);
void	free_map(char **map);

int	launch_window(t_game *game, char *filepath);

void	close_mlx(t_game *game);

#endif