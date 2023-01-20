/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:35:47 by gacalaza          #+#    #+#             */
/*   Updated: 2023/01/14 18:42:40 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

DrawLine(int x1, int x2, int y1, int y2)
{
	int	x = x1;
	int	y = y1;
	int	dx = x2 − x1;
	int	dy = y2 − y1;
	int	d = 2 * dy − dx; // discriminator

	// Euclidean distance of point (x,y) from line (signed)
	int	D = 0;

	// Euclidean distance between points (x1, y1) and (x2, y2)
	int	length = sqrt(dx * dx + dy * dy);

	int	sin = dx / length;
	int	cos = dy / length;
	while (x <= x1)
	{
		// The IntensifyPixel(x,y,r) function takes a radial line transformation and sets the intensity of the pixel (x,y)
		// with the value of a cubic polynomial that depends on the pixel's distance r from the line.
		IntensifyPixels(x, y − 1, D + cos);
		IntensifyPixels(x, y, D);
		IntensifyPixels(x, y + 1, D − cos);
		x = x + 1
		if (d <= 0)
		{
			D = D + sin;
			d = d + 2 * dy;
		}
		else
		{
			D = D + sin − cos;
			d = d + 2 * (dy − dx);
			y = y + 1;
		}
	}
}
