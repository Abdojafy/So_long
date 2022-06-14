/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:55:35 by ajafy             #+#    #+#             */
/*   Updated: 2022/05/24 19:23:32 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define WALL  "/Users/ajafy/Desktop/xpm/wall.xpm"
# define PLAYER  "/Users/ajafy/Desktop/xpm/player.xpm"
# define PLAYERLEFT "/Users/ajafy/Desktop/xpm/playerleft.xpm"
# define COIN1  "/Users/ajafy/Desktop/xpm/coin1.xpm"
# define COIN2  "/Users/ajafy/Desktop/xpm/coin2.xpm"
# define COIN3  "/Users/ajafy/Desktop/xpm/coin3.xpm"
# define COIN4  "/Users/ajafy/Desktop/xpm/coin4.xpm"
# define COIN5  "/Users/ajafy/Desktop/xpm/coin5.xpm"
# define BACKGROUND  "/Users/ajafy/Desktop/xpm/background.xpm"
# define EXITCLOSE  "/Users/ajafy/Desktop/xpm/exitclose.xpm"
# define EXITOPEN  "/Users/ajafy/Desktop/xpm/exitopen.xpm"
# define FIRE1  "/Users/ajafy/Desktop/xpm/fire1.xpm"
# define FIRE2  "/Users/ajafy/Desktop/xpm/fire2.xpm"
# define FIRE3  "/Users/ajafy/Desktop/xpm/fire3.xpm"
# define FIRE4  "/Users/ajafy/Desktop/xpm/fire4.xpm"
# define GAMEOVER1 "/Users/ajafy/Desktop/xpm/gameover1.xpm"
# define GAMEOVER2 "/Users/ajafy/Desktop/xpm/gameover2.xpm"
# define GAMEOVER3 "/Users/ajafy/Desktop/xpm/gameover3.xpm"

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<mlx.h>
# include"printf/libftprintf.h"
# include"get_next_line/get_next_line.h"

typedef struct s_map
{
	int		x;
	int		y;
	int		c;
	int		p;
	int		e;
	int		f;
	int		pp;
	int		inccoin;
	int		incfire;
	int		incgo;
	int		counter;
	char	**map;
	void	*mlx_win;
	void	*mlx;
	void	*imgwall;
	void	*imgplayer;
	void	*imgpll;
	void	*imgbg;
	void	*imgcoin1;
	void	*imgcoin2;
	void	*imgcoin3;
	void	*imgcoin4;
	void	*imgcoin5;
	void	*imgexito;
	void	*imgexitc;
	void	*imgfire1;
	void	*imgfire2;
	void	*imgfire3;
	void	*imgfire4;
	void	*imggo1;
	void	*imggo2;
	void	*imggo3;

}t_map;

#endif