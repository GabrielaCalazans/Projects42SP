/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_read_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 01:20:40 by gacalaza          #+#    #+#             */
/*   Updated: 2023/03/20 20:10:50 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

// ** Gets the number values in each line from the fdf file.

int	count_values_mark(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] != '\n' && line[i] != '\0')
			len++;
		while (line[i] != ' ' && line[i] != '\n' && line[i] != '\0')
			i++;
	}
	return (len);
}

void	set_colors(t_fdf *fdf, int x, int y)
{
	fdf->color.red = (fdf->map.color_map[y][x] >> 16);
	fdf->color.green = (fdf->map.color_map[y][x] >> 8);
	fdf->color.blue = fdf->map.color_map[y][x];
}

// ** Put a pixel in a specific position defined by the draw_lines() function.
// ** If there's an area, make those colors lighter.

void	put_pixel(t_fdf *fdf, int x, int y, double uvector)
{
	int		pos;

	if ((x > 0 && y > 0) && (x < WIN_WIDTH && y < WIN_HEIGHT))
	{
		pos = (x * 4) + (y * WIN_WIDTH * 4);
		fdf->image.data[pos] = fdf->color.red + uvector;
		fdf->image.data[pos + 1] = fdf->color.green + uvector;
		fdf->image.data[pos + 2] = fdf->color.blue + uvector;
		fdf->image.data[pos + 3] = 0x7F;
	}
}
