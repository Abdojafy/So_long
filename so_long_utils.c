/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:26:02 by ajafy             #+#    #+#             */
/*   Updated: 2022/05/23 15:21:51 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	ft_exit(t_map *t);

int	ft_checker2(t_map *t, int i, int j)
{
	int	y;
	int	r;
	int	r1;

	y = 1;
	r = 0;
	r1 = 0;
	while (y < (t->y - 2))
	{
		if (t->map[i][y] != '1')
		{
			r++;
		}
		y++;
	}
	y = 1;
	while (y < (t->x - 1))
	{
		if (t->map[y][j] != '1')
			r1++;
		y++;
	}
	if (r == 0 || r1 == 0)
		return (0);
	return (1);
}

void	ft_checker3(t_map *t, int i, int j)
{
	if (t->map[i][j] == 'C')
		t->c++;
	if (t->map[i][j] == 'P')
	{
		t->p++;
		if ((t->y / 2) > j)
			t->pp = 0;
		else
			t->pp = 1;
	}
	if (t->map[i][j] == 'E')
		t->e++;
	if (t->map[i][j] == '1')
	{
		if ((ft_checker2(t, i, j)) == 0)
		{
			ft_printf("La carte ne doit pas être séparé!");
			exit(0);
		}
	}
}

void	ft_checker1(t_map *t)
{
	int	i;
	int	j;

	i = 1;
	t->c = 0;
	t->p = 0;
	t->e = 0;
	while (i < (t->x - 1))
	{
		j = 1;
		while (j < (t->y - 2))
		{
			ft_checker3(t, i, j);
			j++;
		}
		i++;
	}
	if (t->c == 0 || t->p != 1 || t->e == 0)
	{
		ft_printf("La carte doit contenir au moins 1 sortie,");
		ft_printf(" 1 item et 1 position de départ!");
		exit(0);
	}	
}

int	ft_checker_utils(t_map *t, int i, int j)
{
	if (i == t->x - 1)
		t->y--;
	if (t->y != ft_strlen(t->map[i]) || t->x == (ft_strlen(t->map[i])))
		return (0);
	while ((t->map[i][j] != '\n') && (t->map[i][j]))
	{
		if (i == 0 || i == (t->x - 1) || j == 0 || j == (t->y - 1))
		{
			if (t->map[i][j] != '1')
				return (0);
			j++;
		}
		else if ((t->map[i][j] != '0') && (t->map[i][j] != '1')
			&& (t->map[i][j] != 'C') && (t->map[i][j] != 'E')
			&& (t->map[i][j] != 'P'))
			return (0);
		else
			j++;
	}
	return (1);
}

int	ft_checker(t_map *t)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (t->map[i])
	{
		if (ft_checker_utils(t, i, j) == 0)
			return (0);
		j = 0;
		i++;
	}
	return (1);
}
