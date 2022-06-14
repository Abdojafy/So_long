/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:55:35 by ajafy             #+#    #+#             */
/*   Updated: 2022/05/24 19:24:35 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WALL  "/Users/ajafy/Desktop/xpm/wall.xpm"
# define PLAYER  "/Users/ajafy/Desktop/xpm/player.xpm"
# define PLAYERLEFT "/Users/ajafy/Desktop/xpm/playerleft.xpm"
# define COIN1  "/Users/ajafy/Desktop/xpm/coin1.xpm"
# define BACKGROUND  "/Users/ajafy/Desktop/xpm/background.xpm"
# define EXITCLOSE  "/Users/ajafy/Desktop/xpm/exitclose.xpm"
# define EXITOPEN  "/Users/ajafy/Desktop/xpm/exitopen.xpm"

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
	int		pp;
	int		counter;
	char	**map;
	void	*mlx_win;
	void	*mlx;
	void	*imgwall;
	void	*imgpl;
	void	*imgpll;
	void	*imgbg;
	void	*imgcoin1;
	void	*imgexito;
	void	*imgexitc;

}t_map;

#endif