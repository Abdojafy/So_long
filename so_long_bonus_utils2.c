/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:48:53 by ajafy             #+#    #+#             */
/*   Updated: 2022/05/23 21:28:59 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	ft_lose(t_map *t);
void	ft_win(t_map *t);
char	*ft_itoa(int n);
void	ft_movefire(t_map *t);

int	ft_checkleft(t_map *t, int i, int j)
{
	if (t->map[i][j] == 'P')
	{
		if (t->map[i][j - 1] != '1' && t->map[i][j - 1] != 'E'
			&& t->map[i][j - 1] != 'F')
		{
			if (t->map[i][j - 1] == 'C')
				t->c--;
			t->map[i][j] = '0';
			t->map[i][j - 1] = 'P';
			t->pp = 1;
			t->counter++;
			ft_movefire(t);
			return (0);
		}
		if (t->map[i][j - 1] == 'E' && t->c == 0)
			ft_win(t);
		if (t->map[i][j - 1] == 'F')
		{
			t->map[i][j] = '0';
			t->map[i][j - 1] = 'G';
			ft_lose(t);
		}
	}
	return (1);
}

int	ft_checkright(t_map *t, int i, int j)
{
	if (t->map[i][j] == 'P')
	{
		if (t->map[i][j + 1] != '1' && t->map[i][j + 1] != 'E'
			&& t->map[i][j + 1] != 'F')
		{
			if (t->map[i][j + 1] == 'C')
				t->c--;
			t->map[i][j] = '0';
			t->map[i][j + 1] = 'P';
			t->pp = 0;
			ft_movefire(t);
			t->counter++;
			return (0);
		}
		if (t->map[i][j + 1] == 'E' && t->c == 0)
			ft_win(t);
		if (t->map[i][j + 1] == 'F')
		{
			t->map[i][j] = '0';
			t->map[i][j + 1] = 'G';
			ft_lose(t);
		}
	}
	return (1);
}

void	ft_checkup(t_map *t, int i, int j)
{
	if (t->map[i][j] == 'P')
	{
		if (t->map[i - 1][j] != '1' && t->map[i - 1][j] != 'E'
			&& t->map[i - 1][j] != 'F')
		{
			if (t->map[i - 1][j] == 'C')
				t->c--;
			t->map[i][j] = '0';
			t->map[i - 1][j] = 'P';
			t->counter++;
			ft_movefire(t);
		}
		if (t->map[i - 1][j] == 'E' && t->c == 0)
			ft_win(t);
		if (t->map[i - 1][j] == 'F')
		{
			t->map[i][j] = '0';
			t->map[i - 1][j] = 'G';
			ft_lose(t);
		}
	}
}

int	ft_checkdown(t_map *t, int i, int j, int k)
{
	if (t->map[i][j] == 'P')
	{
		if (t->map[i + 1][j] != '1' && t->map[i + 1][j] != 'E'
			&& t->map[i + 1][j] != 'F')
		{
			if (t->map[i + 1][j] == 'C')
				t->c--;
			t->map[i][j] = '0';
			t->map[i + 1][j] = 'P';
			k++;
			t->counter++;
			ft_movefire(t);
		}
		if (t->map[i + 1][j] == 'E' && t->c == 0)
			ft_win(t);
		if (t->map[i + 1][j] == 'F')
		{
			t->map[i][j] = '0';
			t->map[i + 1][j] = 'G';
			ft_lose(t);
		}		
	}
	return (k);
}

void	ft_counter(t_map *t, int h, int w)
{
	char	*str;

	mlx_put_image_to_window (t->mlx, t->mlx_win, t->imgbg, h, w);
	str = ft_itoa(t->counter);
	mlx_string_put(t->mlx, t->mlx_win, 10, 10, 0XFFFFFFFF, str);
	free(str);
}
