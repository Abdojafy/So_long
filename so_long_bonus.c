/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:54:18 by ajafy             #+#    #+#             */
/*   Updated: 2022/05/23 17:07:22 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	ft_allouer(int fd, t_map *t);
int		ft_checker(t_map *t);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_keyprint(int c, t_map *t);
int		ft_exit(t_map *t);
void	ft_checker1(t_map *t);
char	*ft_itoa(int n);
int		ft_animation(t_map *t);
void	ft_counter(t_map *t, int h, int w);
void	ft_mlx(t_map *t);
void	ft_utils(t_map *t, char *c, int fd);

int	ft_size(char *av)
{
	int		fd;
	char	*s;
	int		x;

	fd = open(av, O_RDONLY);
	x = 0;
	s = get_next_line(fd);
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
	t->imgcoin2 = mlx_xpm_file_to_image (t->mlx, COIN2, &h, &w);
	t->imgcoin3 = mlx_xpm_file_to_image (t->mlx, COIN3, &h, &w);
	t->imgcoin4 = mlx_xpm_file_to_image (t->mlx, COIN4, &h, &w);
	t->imgcoin5 = mlx_xpm_file_to_image (t->mlx, COIN5, &h, &w);
	t->imgplayer = mlx_xpm_file_to_image (t->mlx, PLAYER, &h, &w);
	t->imgpll = mlx_xpm_file_to_image (t->mlx, PLAYERLEFT, &h, &w);
	t->imgexitc = mlx_xpm_file_to_image (t->mlx, EXITCLOSE, &h, &w);
	t->imgexito = mlx_xpm_file_to_image (t->mlx, EXITOPEN, &h, &w);
	t->imgwall = mlx_xpm_file_to_image (t->mlx, WALL, &h, &w);
	t->imgfire1 = mlx_xpm_file_to_image (t->mlx, FIRE1, &h, &w);
	t->imgfire2 = mlx_xpm_file_to_image (t->mlx, FIRE2, &h, &w);
	t->imgfire3 = mlx_xpm_file_to_image (t->mlx, FIRE3, &h, &w);
	t->imgfire4 = mlx_xpm_file_to_image (t->mlx, FIRE4, &h, &w);
	t->imggo1 = mlx_xpm_file_to_image (t->mlx, GAMEOVER1, &h, &w);
	t->imggo2 = mlx_xpm_file_to_image (t->mlx, GAMEOVER2, &h, &w);
	t->imggo3 = mlx_xpm_file_to_image (t->mlx, GAMEOVER3, &h, &w);
}

void	ft_drow(t_map *t, int i, int j)
{
	int		w;
	int		h;

	w = i * 50;
	h = j * 50;
	if (i == 0 && j == 0)
	{
		ft_counter(t, h, w);
		j++;
		h += 50;
	}
	if (t->map[i][j] == '1')
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imgwall, h, w);
	if (t->map[i][j] == '0')
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imgbg, h, w);
	if (t->map[i][j] == 'P' && t->pp == 0)
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imgplayer, h, w);
	if (t->map[i][j] == 'P' && t->pp == 1)
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imgpll, h, w);
	if (t->map[i][j] == 'E' && t->c != 0)
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imgexitc, h, w);
	if (t->map[i][j] == 'E' && t->c == 0)
		mlx_put_image_to_window (t->mlx, t->mlx_win, t->imgexito, h, w);
}

void	ft_drow_map(t_map *t)
{
	int	i;
	int	j;
	int	w;
	int	h;

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
	t.inccoin = 0;
	if (ac != 2)
		exit(0);
	if ((ft_strlen(ft_strrchr(av[1], '.')) != 4)
		|| (ft_strncmp(ft_strrchr(av[1], '.'), ".ber", 4) != 0))
		exit(0);
	ft_utils(&t, av[1], fd);
	ft_checker1(&t);
	t.mlx = mlx_init();
	t.mlx_win = mlx_new_window(t.mlx, t.y * 50, t.x * 50, "so_long");
	ft_drow_map(&t);
	mlx_hook(t.mlx_win, 17, 0, ft_exit, &t);
	mlx_hook(t.mlx_win, 02, 0, ft_keyprint, &t);
	mlx_loop_hook(t.mlx, &ft_animation, &t);
	mlx_loop(t.mlx);
}
