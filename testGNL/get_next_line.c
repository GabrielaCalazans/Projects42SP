/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:17:45 by gacalaza          #+#    #+#             */
/*   Updated: 2022/10/27 22:39:37 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *static_var)
{
	ssize_t	n_bytes;
	char	*buff;

	n_bytes = 1;
	while (/*!(ft_strchr(static_var, '\n')) &&*/ n_bytes > 0)
	{
		buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		n_bytes = read(fd, buff, BUFFER_SIZE);
		if (n_bytes == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[n_bytes] = '\0';
		static_var = ft_strjoin(static_var, buff);
	}
	return (static_var);
}

static char	*get_line(char *static_var)
{
	char	*line;
	int		i;

	i = 0;
	if (!static_var)
		return (NULL);
	while (static_var[i] && static_var[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (static_var[i] && static_var[i] != '\n')
	{
		line[i] = static_var[i];
		i++;
	}
	if (static_var[i] == '\n')
	{
		line[i] = static_var[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*rest_static_var(char *static_var)
{
	int		i;
	int		j;
	char	*rest;

	if (!static_var)
		return (NULL);
	while (static_var[i] && static_var[i] != '\n')
		i++;
	rest = malloc(sizeof(char) * (ft_strlen(static_var) - i) + 1);
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (static_var[i])
	{
		rest[j++] = static_var[i++];
	}
	rest[j] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_var;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_var = read_line(fd, static_var);
	line = get_line(static_var);
	static_var = rest_static_var(static_var);
	return (line);
}
