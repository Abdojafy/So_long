/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:52:40 by ajafy             #+#    #+#             */
/*   Updated: 2022/05/20 22:38:36 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*boucle(char *tab, char *str, int i, int fd)
{
	while (!check(tab))
	{
		str = (char *)malloc(BUFFER_SIZE + 1);
		if (!str)
			return (NULL);
		i = read(fd, str, BUFFER_SIZE);
		if (i < 0)
		{
			free(str);
			return (NULL);
		}
		if (i == 0)
		{
			free(str);
			break ;
		}
		else
		{
			str[i] = '\0';
			tab = ft_strjoin(tab, str);
			free(str);
		}
	}
	return (tab);
}

static char	*lire_fichier(char *tab, int fd)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	if (!tab)
	{
		tab = ft_strdup("");
		if (!tab)
			return (NULL);
	}
	return (boucle(tab, str, i, fd));
}

static char	*laligne(char *tab)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!tab[i])
		return (NULL);
	while (tab[i] != '\n' && tab[i])
		i++;
	i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i && tab[j])
	{
		line[j] = tab[j];
		j++;
	}
	line[j] = 0;
	return (line);
}

static char	*filtre(char *tab)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i] != '\n' && tab[i])
		i++;
	if (!tab[i])
	{
		free(tab);
		return (NULL);
	}
	i++;
	str = (char *)malloc((ft_strleng(tab) - i) + 1);
	if (!str)
		return (NULL);
	while (tab[i])
		str[j++] = tab[i++];
	str[j] = '\0';
	free (tab);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*tab;
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tab = lire_fichier(tab, fd);
	line = laligne(tab);
	tab = filtre(tab);
	return (line);
}
