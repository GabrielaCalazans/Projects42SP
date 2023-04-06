/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read-fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:40:18 by gacalaza          #+#    #+#             */
/*   Updated: 2023/03/18 17:15:44 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_tests.h"

int	ft_atoh(char *hex)
{
	int	len;
	int	base;
	int	dec;

	len = ft_strlen(hex) - 1;
	base = 1;
	dec = 0;
	while (len >= 0)
	{
		if (hex[len] >= '0' && hex[len] <= '9')
			dec += (hex[len] - 48) * base;
		if (hex[len] >= 'A' && hex[len] <= 'F')
			dec += (hex[len] - 55) * base;
		if (hex[len] >= 'a' && hex[len] <= 'f')
			dec += (hex[len] - 87) * base;
		base *= 16;
		len--;
	}
	return (dec);
}

// static int	count_values0(char *line) // still can't think in a solution to see only int and ignored hex n
// {
// 	int		len;
// 	int		i;

// 	len = 0;
// 	i = 0;
// 	while (line[i])
// 	{
// 		if (ft_isdigit(line[i]))
// 		{
// 			len += 1;
// 			while (ft_isdigit(line[i]))
// 				i += 1;
// 		}
// 		else if (line[i] != ' ' && line[i] != '-')
// 			printf("Invalid characters or read error...lel ???（ ^_^)");
// 		i += 1;
// 	}
// 	return (len);
// }

static int	count_values1(char *line)
{
	int		len;
	int		i;

	len = 1;
	i = 0;
	while (line[i])
	{
		
		if (ft_isdigit(line[i]) && (line[i + 1] == ' ' && line[i + 2] != '\n'))
		{
			len += 1;
			// while (ft_isdigit(line[i]))
			// 	i += 1;
		}
		i++;
	}
	return (len);
}

// static int	count_values(char *line)
// {
// 	// int		fd;
// 	char	**split;
// 	int		i;
// 	// int		j;
// 	// char	*new_line;

// 	// if (check == 1)
// 	// {
// 	// 	fd = open(line, O_RDONLY);
// 	// 	new_line = get_next_line(fd);
// 	// 	split = ft_split(new_line, ' ');
// 	// }
// 	// else
// 		split = ft_split(line, ' ');
// 	i = 0;
// 	while (split[i])
// 		i++;
// 	// j = 0;
// 	// while (split[j])
// 	// 	free(split[j++]);
// 	// free(split);
// 	// if (check == 1)
// 	// 	free(new_line);
// 	return (i);
// }

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
		len = count_values1(line);
		if (len > cols)
			cols = len;
		if (cols == len)
			rows += 1;
		else
			printf("Not a valid file! 3 >_<");
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) < 0)
		printf("Error closing file! WTF?! :)");
	data->rect.width = cols;
	if (!(data->rect.width == cols))
		printf("Not a valid file! 2 >_<");
	return (rows);
}

static void	get_values(t_data *data, int x, int y, char *line)
{
	int		i;
	int		j;
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		printf("Not a valid file! 1 0 >_<");
	i = 0;
	while (split[i] && (x != data->rect.width))
	{
		data->rect.values[y][x] = ft_atoi(split[i]);
		j = 0;
		while (split[i][j] != ',' && split[i][j])
			j++;
		if (split[i][j++] == ',')
			data->rect.color_map[y][x] = ft_atoh(&split[i][j]);
		else
			data->rect.color_map[y][x] = 0;
		i++;
		x++;
	}
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
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
		data->rect.color_map[y] = (int *)malloc(sizeof(int) * data->rect.width);
		if (!(data->rect.values[y]))
			printf("Memory Allocation failed! 2 :O");
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
	data->rect.color_map = (int **)malloc(sizeof(int *) * data->rect.height);
	if (!(data->rect.values || data->rect.color_map))
		printf("Memory Allocation failed! :O");
	read_lines(data, fd);
	if (close(fd) < 0)
		printf("Error closing file! WTF?! :)");
}
