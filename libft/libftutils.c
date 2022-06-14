/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:24:22 by ajafy             #+#    #+#             */
/*   Updated: 2022/05/23 16:57:56 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

char	*ft_alloueri(char *p, int n, int i)
{
	if (n <= 0)
		p = (char *)malloc(i + 2);
	else
		p = (char *)malloc(i + 1);
	return (p);
}

int	ft_count( long x)
{
	int	i;

	i = 0;
	if (x < 0)
		x *= (-1);
	while (x > 0)
	{
		x /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		i;
	long	x;

	p = NULL;
	x = n;
	i = ft_count(x);
	p = ft_alloueri(p, n, i);
	if (x < 0)
	{
		p[0] = '-';
		x *= (-1);
		i++;
	}
	if (n == 0)
		p[i++] = 0 + 48;
	p[i] = '\0';
	while (x > 0)
	{
		p[--i] = (x % 10) + 48;
		x /= 10;
	}
	return (p);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (!s1)
		return (1);
	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] != '\0' || s2[i] != '\0') && (i < n))
	{
		if ((unsigned char) s1[i] == (unsigned char) s2[i])
			i++;
		else if ((unsigned char) s1[i] > (unsigned char) s2[i])
			return (1);
		else
			return (-1);
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if (s[i] == (unsigned char) c)
		{
			return ((char *) s + i);
		}
		i--;
	}
	return (NULL);
}
