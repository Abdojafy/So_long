/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:48:53 by ajafy             #+#    #+#             */
/*   Updated: 2022/05/23 15:06:30 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_win(t_map *t);

void	ft_checkleft(t_map *t, int i, int j)
{
	while (t->map[i][j])
	{
		if (t->map[i][j] == 'P')
		{
			if (t->map[i][j - 1] != '1' && t->map[i][j - 1] != 'E')
			{
				if (t->map[i][j - 1] == 'C')
					t->c--;
				t->map[i][j] = '0';
				t->map[i][j - 1] = 'P';
				t->pp = 1;
				t->counter++;
				ft_printf("%d\n", t->counter);
				break ;
			}
			if (t->map[i][j - 1] == 'E' && t->c == 0)
				ft_win(t);
		}
	j++;
	}
}

void	ft_checkright(t_map *t, int i, int j)
{
	while (t->map[i][j])
	{
		if (t->map[i][j] == 'P')
		{
			if (t->map[i][j + 1] != '1' && t->map[i][j + 1] != 'E')
			{
				if (t->map[i][j + 1] == 'C')
					t->c--;
				t->map[i][j] = '0';
				t->map[i][j + 1] = 'P';
				t->pp = 0;
				t->counter++;
				ft_printf("%d\n", t->counter);
				break ;
			}
			if (t->map[i][j + 1] == 'E' && t->c == 0)
				ft_win(t);
		}
		j++;
	}
}

void	ft_checkup(t_map *t, int i, int j)
{
	while (t->map[i][j])
	{
		if (t->map[i][j] == 'P')
		{
			if (t->map[i - 1][j] != '1' && t->map[i - 1][j] != 'E')
			{
				if (t->map[i - 1][j] == 'C')
					t->c--;
				t->map[i][j] = '0';
				t->map[i - 1][j] = 'P';
				t->counter++;
				ft_printf("%d\n", t->counter);
			}
			if (t->map[i - 1][j] == 'E' && t->c == 0)
				ft_win(t);
		}
	j++;
	}
}

int	ft_checkdown(t_map *t, int i, int j, int k)
{
	while (t->map[i][j])
	{
		if (t->map[i][j] == 'P')
		{
			if (t->map[i + 1][j] != '1' && t->map[i + 1][j] != 'E')
			{
				if (t->map[i + 1][j] == 'C')
					t->c--;
				t->map[i][j] = '0';
				t->map[i + 1][j] = 'P';
				k++;
				t->counter++;
				ft_printf("%d\n", t->counter);
			}
			if (t->map[i + 1][j] == 'E' && t->c == 0)
				ft_win(t);
		}
		j++;
	}
	return (k);
}
