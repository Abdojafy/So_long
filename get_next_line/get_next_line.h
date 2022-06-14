/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:53:27 by ajafy             #+#    #+#             */
/*   Updated: 2022/05/23 17:10:12 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
int		check(char *tab);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strleng(char *str);
char	*ft_strdup(char *s);

#endif
