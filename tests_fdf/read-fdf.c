/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read-fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:40:18 by gacalaza          #+#    #+#             */
/*   Updated: 2023/03/06 16:38:00 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_tests.h"

static int	count_values(char *line)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			len += 1;
			while (ft_isdigit(line[i]))
				i += 1;
		}
		else if (line[i] != ' ' && line[i] != '-')
			printf("Invalid characters or read error. ^_^)");
		i += 1;
	}
	return (len);
}

static int	count_lines(t_data *data, char *argv)
{
	int		fd;
	int		len;
	int		rows;
	int		cols;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		printf("Error opening file! :(");
	rows = 0;
	cols = 0;
	line = get_next_line(fd);
	if (line == NULL)
		printf("Oh shit GNL broke");
	while (line != NULL)
	{
		if (*line == '\0')
			break ;
		len = count_values(line);
		if (len > cols)
			cols = len;
		if (cols == len) 
			rows += 1;
		else
			printf("Not a valid file! >_<");
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) < 0)
		printf("Error closing file! WTF?! :)");
	data->rect.width = cols;
	if (!(data->rect.width == cols))
		printf("Not a valid file! >_<");
	return (rows);
}

static void	get_values(t_data *data, int x, int y, char *line)
{
	int		i;
	char	**split;

	split = ft_split(line, ' ');
	if (split)
	{
		i = 0;
		while (split[i] && (x != data->rect.width))
		{
			data->rect.values[y][x] = ft_atoi(split[i++]);
			x += 1;
		}
		free(split);
	}
}

void	read_lines(t_data *data, int fd)
{
	int		x;
	int		y;
	char	*line;

	x = 0;
	y = 0;
	line = get_next_line(fd);
	while (line != NULL && y != data->rect.height)
	{
		data->rect.values[y] = (int *)malloc(sizeof(int) * data->rect.width);
		if (!(data->rect.values[y]))
			printf("Memory Allocation failed! :O");
		get_values(data, x, y, line);
		x = 0;
		y += 1;
		free(line);
		line = get_next_line(fd);
	}
}

void	fdf_read(char *argv, t_data *data)
{
	int	fd;

	data->rect.height = count_lines(data, argv);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		printf("Error opening file! :(");
	data->rect.values = (int **)malloc(sizeof(int *) * data->rect.height);
	if (!(data->rect.values))
		printf("Memory Allocation failed! :O");
	read_lines(data, fd);
	if (close(fd) < 0)
		printf("Error closing file! WTF?! :)");
}
