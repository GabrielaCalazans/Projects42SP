/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:35:49 by gacalaza          #+#    #+#             */
/*   Updated: 2023/02/08 14:46:47 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_tests.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	//int offset = (y * line_length + x * (bits_per_pixel / 8));
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;
	//int offset = (y * line_length + x * (bits_per_pixel / 8));
	dst = data->addr + (x * data->line_length + y * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// static unsigned char	img_stc[W * H * 3];

// void	setpixel(int x, int y)
// {
// 	unsigned char* p = img_stc + (y * W + x) * 3;
// 	p[0] = p[1] = p[2] = 0;
// }
// void	bresenham(int x0, int y0, int x1, int y1)
// {
// 	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
// 	int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
// 	int err = (dx > dy ? dx : -dy) / 2;

// 	while (setpixel(x0, y0), x0 != x1 || y0 != y1)
// 	{
// 		int e2 = err;
// 		if (e2 > -dx) { err -= dy; x0 += sx; }
// 		if (e2 <  dy) { err += dx; y0 += sy; }
// 	}
// }