/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:13:17 by gacalaza          #+#    #+#             */
/*   Updated: 2023/03/11 19:39:34 by gacalaza         ###   ########.fr       */
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

static void	get_values(int x, int y, char *line, int **values, int **color_map)
{
	int		i, j;
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		printf("Not a valid file! >_<");
	i = 0;
	while (split[i] && (x != 11))
	{
		values[y][x] = ft_atoi(split[i]);
		j = 0;
		while (split[i][j] != ',' && split[i][j])
			j++;
		if (split[i][j++] == ',')
			color_map[y][x] = ft_atoh(&split[i][j]);
		else
			color_map[y][x] = ft_atoi("0");
		i++;
		x++;
	}
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int main(int argc, char *argv[])
{
	int	fd = open(argv[1], O_RDONLY);
	int		x;
	int		y;
	char	*line;
	int		**values;
	int		**color_map;

	x = 0;
	y = 0;

	values = (int **)malloc(sizeof(int *) * 19);
	color_map = (int **)malloc(sizeof(int *) * 19);

	line = get_next_line(fd);
	while (line != NULL && y != 19)
	{
		values[y] = (int *)malloc(sizeof(int) * 11);
		color_map[y] = (int *)malloc(sizeof(int) * 11);
		if (!(values[y]))
			printf("Memory Allocation failed! :O");
		get_values(x, y, line, values, color_map);
		y += 1;
		x = 0;
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) < 0)
		printf("Error closing file! WTF?! :)");
	int i, j;

	i = 0;
	printf("AQUI! 97");
	while (i < 11)
	{
		j = 0;
		printf(" VALUE[%d] i:%d \n", color_map[i][j], i);
		while (i < 11 && j < 19)
		{
			printf("values2[%d] j:%d ", color_map[i][j], j);
			j++;
		}
		i++;
	}
	return (0);
}