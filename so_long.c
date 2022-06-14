/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:54:18 by ajafy             #+#    #+#             */
/*   Updated: 2022/05/23 13:58:36 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_allouer(int fd, t_map *t);
int		ft_checker(t_map *t);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_keyprint(int c, t_map *t);
int		ft_exit(t_map *t);
void	ft_checker1(t_map *t);

int	ft_size(char *av)
{
	int		fd;
	char	*s;
	int		x;

	fd = open(av, O_RDONLY);
	s = get_next_line(fd);
	x = 0;
	while (s)
	{
		x++;
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	free(s);
	return (x);
}

void	ft_initialiser(t_map *t)
{
	int		w;
	int		h;

	t->imgbg = mlx_xpm_file_to_image (t->mlx, BACKGROUND, &h, &w);
	t->imgcoin1 = mlx_xpm_file_to_image (t->mlx, COIN1, &h, &w);
	t->imgpl = mlx_xpm_file_to_image (t->mlx, PLAYER, &h, &w);
	t->imgpll = mlx_xpm_file_to_image (t->mlx, PLAYERLEFT, &h, &w);
	t->imgexitc = mlx_xpm_file_to_image (t->mlx, EXITCLOSE, &h, &w);
	t->imgexito = mlx_xpm_file_to_image (t->mlx, EXITOPEN, &h, &w);
	t->imgwall = mlx_xpm_file_to_image (t->mlx, WALL, &h, &w);
}

void	ft_drow(t_map *t, int i, int j)
{
	int		w;
	int		h;

	w = i * 50;
	h = j * 50;
	if (t->map[i][j] == '1')
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imgwall, h, w);
	if (t->map[i][j] == '0')
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imgbg, h, w);
	if (t->map[i][j] == 'P' && t->pp == 0)
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imgpl, h, w);
	if (t->map[i][j] == 'P' && t->pp == 1)
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imgpll, h, w);
	if (t->map[i][j] == 'C')
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imgcoin1, h, w);
	if (t->map[i][j] == 'E' && t->c != 0)
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imgexitc, h, w);
	if (t->map[i][j] == 'E' && t->c == 0)
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imgexito, h, w);
}

void	ft_drow_map(t_map *t)
{
	int		i;
	int		j;
	int		w;
	int		h;

	ft_initialiser(t);
	h = 0;
	w = 0;
	i = 0;
	while (t->map[i])
	{
		j = 0;
		h = 0;
		while (t->map[i][j])
		{
			ft_drow(t, i, j);
			j++;
			h += 50;
		}
		w += 50;
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_map	t;
	int		fd;

	t.counter = 0;
	if (ac != 2)
		exit(0);
	if ((ft_strlen(ft_strrchr(av[1], '.')) != 4)
		|| (ft_strncmp(ft_strrchr(av[1], '.'), ".ber", 4) != 0))
		exit(0);
	t.x = (ft_size(av[1]));
	fd = open(av[1], O_RDONLY);
	ft_allouer(fd, &t);
	t.y = (ft_strlen(t.map[0]));
	if (ft_checker(&t) == 0)
	{
		ft_printf("Erreur en map !");
		exit(0);
	}
	ft_checker1(&t);
	t.mlx = mlx_init();
	t.mlx_win = mlx_new_window(t.mlx, t.y * 50, t.x * 50, "so_long");
	ft_drow_map(&t);
	mlx_hook(t.mlx_win, 02, 0, ft_keyprint, &t);
	mlx_hook(t.mlx_win, 17, 0, ft_exit, &t);
	mlx_loop(t.mlx);
}
