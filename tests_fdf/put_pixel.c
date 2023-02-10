/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:35:49 by gacalaza          #+#    #+#             */
/*   Updated: 2023/02/09 20:59:00 by gacalaza         ###   ########.fr       */
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

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	render(t_data *data)
{
	// /* if window has been destroyed, we don't want to put the pixel ! */
	// if (data->win_ptr != NULL)
	// 	mlx_pixel_put(data->mlx_ptr, data->win_ptr, 
	// 		WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0x0000FFFF);
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, 0x00FFFFFF);
	render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100,
				100, 100, 0x003300FF}); // DOWN RIGHT SQUARE
	render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, 0, 100, 100,
				0x0099FF33}); // UP RIGHT SQUARE
	render_rect(&data->img, (t_rect){0, 0, 100, 100, 0x0000FFFF}); // UP LEFT SQUARE
	render_rect(&data->img, (t_rect){0, WINDOW_HEIGHT - 100, 100, 100, 0x009933FF}); // DOWN LEFT SQUARE
	render_rect(&data->img, (t_rect){WINDOW_WIDTH / 2 - 50, WINDOW_HEIGHT / 2 - 50, 100, 100, 0x00CC33FF}); // CENTER SQUARE
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

/* The x and y coordinates of the rect corresponds to its upper left corner. */

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
	{
			img_pix_put(img, j++, i, color);
	}
		++i;
	}
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

