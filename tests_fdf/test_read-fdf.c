/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read-fdf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:40:18 by gacalaza          #+#    #+#             */
/*   Updated: 2023/03/06 11:11:46 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h> // CLOSE READ WRITE
# include <fcntl.h> // OPEN
# include <stdio.h> // PERROR
# include <string.h> // STRERROR
# include <stdlib.h> // MALLOC FREE EXIT
# include "libft/libft.h"

static int	count_values(char *argv)
{
	int		len;
	int		i;
	char	*line;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		printf("Error opening file! :(");
	line = get_next_line(fd);
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

static int	count_lines(char *argv, int width)
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
		len = count_values(argv);
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
	if (!(width == cols))
		printf("Not a valid file! FOFF");
	return (rows);
}

void	read_lines(int fd, int height, int **values, int width)
{
	int		x;
	int		y;
	char	*line;
	int		i;
	char	**split;

	x = 0;
	y = 0;
	line = get_next_line(fd);
	while (line != NULL && y != height)
	{
		values[y] = (int *)malloc(sizeof(int) * width);
		if (!(values[y]))
			printf("Memory Allocation failed! Say Whaat?:O");
		split = ft_split(line, ' ');
		if (split)
		{
			i = 0;
			while (split[i] && (x != width))
			{
				values[y][x] = ft_atoi(split[i++]);
				x += 1;
			}
			free(split);
		}
		x = 0;
		y += 1;
		free(line);
		line = get_next_line(fd);
	}
}

int	main(int argc, char *argv[])
{
	int	**values;
	int	fd;
	int	height;
	int	width;

	if (argc == 2)
	{
		width = count_values(argv[1]);
		height = count_lines(argv[1], width);
		printf("width %d", width);
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			printf("Error opening file! Oh Gosh:(");
		values = (int **)malloc(sizeof(int *) * height);
		if (!(values))
			printf("Memory Allocation failed! :O");
		read_lines(fd, height, values, width);
		if (close(fd) < 0)
			printf("Error closing file! WTF?! :)");
	}
	else
		printf("Error: wrong number of arguments! HELP ME, TO HELP U!");
	return (0);
}

// int	print_values_loop(char **argv, t_data *data)
// {
// 	// int	yi;
// 	// int	xi;

// 	data->rect.height = count_lines(data, argv[1]);
// 	if (data->rect.height > 0)
// 		printf("height%i", data->rect.height);
// 	else
// 	// yi = 0;
// 	// xi = 0;
// 	// printf("VALUES in y:%i e x%i \n", data->rect.values[yi][xi], data->rect.values[yi][xi]);
// 	// while (data->rect.values[yi][xi] < data->rect.height)
// 	// {
// 	// 	while(data->rect.values[yi][xi] < data->rect.width)
// 	// 	{
// 	// 		printf("VALUES in y:%i e x%i \n", data->rect.values[yi][xi], data->rect.values[yi][xi]);
// 	// 		xi++;
// 	// 	}
// 	// }
// 	// 	yi++;
// 	// 	printf("\n");
// 	printf("THE END!\n");
// 	printf("height%i", data->rect.height);
// 	return (0);
// }
