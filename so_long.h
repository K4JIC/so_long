/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tozaki <tozaki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:14:36 by tozaki            #+#    #+#             */
/*   Updated: 2025/12/02 20:21:26 by tozaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define FLOOR "../imgs/tile.xpm"
# define WALL "../imgs/python.xpm"
# define PLAYER "../imgs/player.xpm"
# define GOAL "../imgs/goal.xpm"
# define GOAL "../imgs/c.xpm"

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
	t_imgs	imgs;
}			t_game;

#endif