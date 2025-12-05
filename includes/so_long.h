/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:14:36 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/05 19:57:39 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>

# define FLOOR "imgs/cave.xpm"
# define WALL "imgs/wall.xpm"
# define PLAYER "imgs/terminal.xpm"
# define GOAL "imgs/python.xpm"
# define COLLECTIBLE "imgs/c.xpm"
# define ISIZE 32

# define SUCCESS 0
# define FAIL 1

# define FAILED_TO_OPEN -1
# define EMPTY_FILE -2
# define FAILED_TO_READ -3

typedef struct s_imgs
{
	void	*floor;
	void	*wall;
	void	*player;
	void	*goal;
	void	*collectible;
}			t_imgs;

typedef struct s_position
{
	int	row;
	int	col;
}		t_position;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	char		*title;
	char		**map;
	t_imgs		imgs;
	t_position	player;
	int			collectible_count;
}			t_game;

/*load_map*/
char	**load_map(char *filepath);
void	free_map(char **map);

/*launch_window*/
int		draw_window(t_game *game);
int		launch_window(t_game *game, char *filepath);
void	set_player_address(t_game *game);

/*celltype*/
int		is_accessible(t_game *game, t_position p);
int		is_collectible(t_game *game, t_position p);
int		is_goal(t_game *game, t_position p);

/*move_cells*/
int		swap_cell(t_game *game, t_position p1, t_position p2);
int		move_player(t_game *game, int row, int col);

/*deal_key*/
int		deal_keys(int key, t_game *game);

/*validate_file*/
int		validate_file(char *filepath);
/*validate_file_utils*/
int		measure_filesize(char *filepath);

/*validate_map*/
int		validate_map(t_game *game);
/*validate_map_utils*/
int		is_rectangular(char **map);
int		is_surrounded(char **map);
int		count_symbols(char **map, char c);
int		is_defined_char(char **map);
/*validate_map_flood_fill*/
int		flood_fill(char **map, int row, int col);
void	clean_flood(char **map);

/*close_window*/
void	close_mlx(t_game *game);

#endif