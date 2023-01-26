/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btest_algor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:32:24 by gacalaza          #+#    #+#             */
/*   Updated: 2023/01/26 19:50:59 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

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
	x = 0;
	y = 0;

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


