/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btest_algor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:32:24 by gacalaza          #+#    #+#             */
/*   Updated: 2023/02/09 15:56:20 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_tests.h"

// https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm

void	bresenham(int x0, int y0, int x1, int y1, t_data img)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x1 - x0);
	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	dy = abs(y1 - y0);
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
	int	m;
	int	p;
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	temp;
	int	var1;
	int	var2;

	var1 = abs(y1-y0); //350
	var2 = abs(x1-x0); //-350
	if ((x1-x0) == 0)
		m = var1; // TO FIND THE SLOP
	else
		m = var1/var2; // TO FIND THE SLOP -- = -1
	if (m < 1) //sim
	{
		if (x0 > x1)//sim
		{
			temp = x0;
			x0 = x1;
			x1 = temp;

			temp = y0;
			y0 = y1;
			y1 = temp;
		}
		dx = abs(x1-x0); //350
		dy = abs(y1-y0); //-350
		p = 2*dy-dx; // first parameter -- 1050
		x= x0; // 50
		y= y0; // 400
		while (x <= x1) //sim
		{
			my_mlx_pixel_put(&img, x, y, cor);
			x += 1;
			if (p >= 0)
			{
				if (m < 1)
					y += 1;
				else
					y -= 1;
				p += 2*dy-2*dx;
			}
			else
				//y = y;
				p += 2*dy;
		}
	}
	if (m >= 1) //sim
	{
		if (y0 > y1)//não
		{
			temp = x0;
			x0 = x1;
			x1 = temp;

			temp = y0;
			y0 = y1;
			y1 = temp;
		}
		dx = abs(x1-x0);
		dy = abs(y1-y0);
		p = 2*dx-dy; // first parameter
		x= x0;
		y= y0;
		while (y <= y1)
		{
			my_mlx_pixel_put(&img, x, y, cor);
			y += 1;
			if (p >= 0)
			{
				if (m >= 1)
					x += 1;
				else
					x -= 1;
				p += 2*dx-2*dy;
			}
			else
				//x = x;
				p += 2*dx;
		}
	}
}
