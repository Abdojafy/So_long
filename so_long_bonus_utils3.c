/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_utils3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:04:49 by ajafy             #+#    #+#             */
/*   Updated: 2022/05/23 17:08:29 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	ft_drow_map(t_map *t);
int		ft_animation(t_map *t);
int		ft_keyprint(int c, t_map *t);
int		ft_size(char *av);
int		ft_checker(t_map *t);

int	ft_exit(t_map *t)
{
	exit(0);
	return (0);
}

void	ft_lose(t_map *t)
{
	mlx_clear_window(t->mlx, t->mlx_win);
	ft_drow_map(t);
	ft_printf("Game Over !");
}

void	ft_win(t_map *t)
{
	ft_printf("Bingo !");
	ft_exit(t);
}

void	ft_allouer(int fd, t_map *t)
{
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	t->map = (char **) malloc((t->x + 1) * sizeof(char *));
	if (!t->map)
		exit(0);
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		t->map[i] = temp;
		i++;
	}
	t->map[i] = NULL;
}

void	ft_utils(t_map *t, char *c, int fd)
{
	t->x = (ft_size(c));
	fd = open(c, O_RDONLY);
	ft_allouer(fd, t);
	t->y = (ft_strlen(t->map[0]));
	if (ft_checker(t) == 0)
	{
		ft_printf("Erreur en map !");
		exit(0);
	}
}
