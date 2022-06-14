/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:04:49 by ajafy             #+#    #+#             */
/*   Updated: 2022/05/23 15:07:38 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	ft_exit(t_map *t)
{
	exit(0);
	return (0);
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
