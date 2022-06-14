/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_utils4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:12:57 by ajafy             #+#    #+#             */
/*   Updated: 2022/05/23 22:30:25 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_drow_map(t_map *t);

void	ft_movefire1(t_map *t, int i, int j, int r)
{
	if (t->map[i][j] == 'F')
	{
		r = rand();
		if (r % 2 == 0)
		{
			if (t->map[i][j - 1] != '1' && t->map[i][j - 1] != 'E'
				&& t->map[i][j - 1] != 'P' && t->map[i][j - 1] != 'C')
			{
				t->map[i][j] = '0';
				t->map[i][j - 1] = 'F';
				ft_drow_map(t);
			}
		}
		else
		{
			if (t->map[i][j + 1] != '1' && t->map[i][j + 1] != 'E'
				&& t->map[i][j + 1] != 'P' && t->map[i][j + 1] != 'C')
			{
				t->map[i][j] = '0';
				t->map[i][j + 1] = 'F';
				ft_drow_map(t);
			}
		}
	}
}

void	ft_movefire(t_map *t)
{
	int	i;
	int	j;
	int	r;

	i = 0;
	while (t->map[i])
	{
		j = 0;
		while (t->map[i][j])
		{
			ft_movefire1(t, i, j, r);
			j++;
		}
		i++;
	}
}
