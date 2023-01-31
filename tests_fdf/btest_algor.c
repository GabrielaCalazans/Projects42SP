/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btest_algor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:32:24 by gacalaza          #+#    #+#             */
/*   Updated: 2023/01/31 20:16:05 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	bresenham(int x0, int y0, int x1, int y1, t_data img)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = ABS(x1 - x0);
	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	dy = ABS(y1 - y0);
	if (x0 < x1)
		sy = 1;
	else
		sy = -1;
	if (dx > dy)
		err = dx / 2;
	else
		err = -dy / 2;
	while (x0 != x1 || y0 != y1)
	{
		e2 = err;
		my_mlx_pixel_put(&img, x0, y0, 0x0000FFFF);
		if (e2 > -dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	reta_bresenham(int x0, int x1, int y0, int y1, int cor, t_data img)
{
	int	dx;
	int	dy;
	int	d;
	int	inc_e; // acima do ponto medio
	int	inc_ne; // abaixo do ponto medio
	int	x;
	int	y;

	dx = x1 - x0;
	dy = y1 - y0;
	d = 2 * dy - dx; // Valor inicial de d
	inc_e = 2 * dy; // Incremento pra mover E
	inc_ne = 2 * (dy-dx); // Incremento para mover NE
	x = x0;
	y = x1;

	//my_mlx_pixel_put(&img, x, y, cor);
	while (x < x1)
	{
		if (d <= 0)
		{
			d +=inc_e;
			x++;
		}
		else
		{
			d += inc_ne;
			x++;
			y++;
		}
		my_mlx_pixel_put(&img, x, y, cor);
	}

}

void	bresenham3(int x0, int x1, int y0, int y1, int cor, t_data img)
{
	int	dy;
	int	dx;
	int	x;
	int	y;
	int	e;

	dy = y1 - x1;
	dx = y0 - x0;
	x = x0;
	y = x1;
	e = 0;
	while (x <= y0)
	{
		my_mlx_pixel_put(&img, x, y, cor);
		if (!(x0 == y0))
			x += 1;
		e += 2 * dy;
		if (e >= dx)
		{
			y += 1;
			e -= 2 * dx;
		}
	}
}

void	bresenham4(int x0, int y0, int x1, int y1, int cor, t_data img)
{
	int	dy;
	int	dx;
	int	x;
	int	y;
	int	p;

	dx = x1 - x0;
	dy = y1 - y0;
	x = x0;
	y = y0;
	p = 2*dx-dy;
	if ((dy/dx) > 0)
	{
		while (y <= y1)
		{
			my_mlx_pixel_put(&img, x, y, cor);
			y++;
			if (p < 0)
			{
				p += 2 * dy;
				x++;
			}
			else
				p = 2 * (dy - dx);
		}
	}
	else
	{
			while (x <= x1)
			{
				my_mlx_pixel_put(&img, x, y, cor);
				x++;
				if (p < 0)
				{
					p += 2 * dy;
				}
				else
				{
					p = 2 * (dy-dx);
					y++;
				}
			}
	}
}
