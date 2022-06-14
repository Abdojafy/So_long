/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:54:58 by ajafy             #+#    #+#             */
/*   Updated: 2022/01/07 10:55:08 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

char	*boucle(char *tab, char *buffer, int i, int fd)
{
	while (!check(tab))
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (i == 0)
		{
			free(buffer);
			break ;
		}
		else
		{
			buffer[i] = 0;
			tab = ft_strjoin(tab, buffer);
			free(buffer);
		}
	}
	return (tab);
}

static char	*lire_fichier(char *tab, int fd)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = NULL;
	if (!tab)
	{
		tab = ft_strdup("");
		if (!tab)
			return (NULL);
	}
	return (boucle(tab, buffer, i, fd));
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
	str = (char *)malloc((ft_strlen(tab) - i) + 1);
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
	static char	*tab[10240];
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tab[fd] = lire_fichier(tab[fd], fd);
	line = laligne(tab[fd]);
	tab[fd] = filtre(tab[fd]);
	return (line);
}
