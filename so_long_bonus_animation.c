/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_animation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:30:39 by ajafy             #+#    #+#             */
/*   Updated: 2022/05/23 16:51:30 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

int	ft_exit(t_map *t);

void	ft_animation_coin(t_map *t, int h, int w)
{
	if (t->inccoin <= 60)
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imgcoin2, h, w);
	else if (t->inccoin <= 120)
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imgcoin3, h, w);
	else if (t->inccoin <= 180)
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imgcoin4, h, w);
	else if (t->inccoin <= 240)
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imgcoin5, h, w);
	else
	{
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imgcoin1, h, w);
		t->inccoin = 0;
	}
	t->inccoin++;
}

void	ft_animation_fire(t_map *t, int h, int w)
{
	if (t->incfire <= 25)
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imgfire2, h, w);
	else if (t->incfire <= 50)
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imgfire3, h, w);
	else if (t->incfire <= 75)
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imgfire4, h, w);
	else
	{
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imgfire1, h, w);
		t->incfire = 0;
	}
	t->incfire++;
}

void	ft_animation_gameover(t_map *t, int h, int w)
{
	if (t->incgo <= 20)
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imggo2, h, w);
	else if (t->incgo <= 40)
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imggo3, h, w);
	else if (t->incgo > 40)
		ft_exit(0);
	else
	{
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imggo1, h, w);
		t->incgo = 0;
	}
	t->incgo++;
}

void	ft_check_animation(t_map *t, int i, int j)
{
	int	h;
	int	w;

	w = i * 50;
	h = j * 50;
	if (t->map[i][j] == 'C')
		ft_animation_coin(t, h, w);
	if (t->map[i][j] == 'F')
		ft_animation_fire(t, h, w);
	if (t->map[i][j] == 'G')
		ft_animation_gameover(t, h, w);
}

int	ft_animation(t_map *t)
{
	int	i;
	int	j;

	i = 0;
	while (t->map[i])
	{
		j = 0;
		while (t->map[i][j])
		{
			ft_check_animation(t, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
