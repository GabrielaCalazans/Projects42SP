/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw-fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:38:26 by gacalaza          #+#    #+#             */
/*   Updated: 2023/03/13 16:15:49 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_tests.h"


static void	put_pixel(t_data *data, int x, int y, double uvector)
{
	int		pos;
	// char		*dest;

	if ((x > 0 && y > 0) && (x < WINDOW_WIDTH && y < WINDOW_HEIGHT))
	{
		pos = (x * 4) + (y * WINDOW_WIDTH * 4);
		
		// dest = &data->img.addr[pos];
		// *(int*)dest = data->rect.color;
		
		data->img.addr[pos] = data->color.red + uvector;
		data->img.addr[pos + 1] = data->color.blue + uvector;
		data->img.addr[pos + 2] = data->color.green + uvector;
		data->img.addr[pos + 3] = 0x7F;
	}
}

static void	draw_lines(t_data *data)
{
	double	x;
	double	y;
	double	delta_x;
	double	delta_y;
	double	uvector;

	x = data->rect.x0;
	y = data->rect.y0;
	delta_x = data->rect.x1 - data->rect.x0;
	delta_y = data->rect.y1 - data->rect.y0;
	uvector = sqrt((pow(delta_x, 2)) + (pow(delta_y, 2)));
	delta_x /= uvector;
	delta_y /= uvector;
	while (uvector > 0)
	{
		put_pixel(data, x, y, uvector);
		x += delta_x;
		y += delta_y;
		uvector -= 1;
	}
}

static void	draw_horizontal(t_data *data, int x, int y)
{
	int		xt;
	int		yt;

	xt = x - data->rect.width / 2;
	yt = y - data->rect.height / 2;
	data->rect.x0 = data->rect.angle_x * (xt - yt) * data->rect.zoom;
	data->rect.y0 = data->rect.angle_y * (xt + yt) * data->rect.zoom;
	data->rect.y0 -= data->rect.values[y][x] * data->rect.z_value;
	data->rect.x1 = data->rect.angle_x * ((xt + 1) - yt) * data->rect.zoom;
	data->rect.y1 = data->rect.angle_y * ((xt + 1) + yt) * data->rect.zoom;
	data->rect.y1 -= data->rect.values[y][x + 1] * data->rect.z_value;
	data->rect.x0 += (WINDOW_WIDTH / 2) + data->rect.coordinate_x;
	data->rect.x1 += (WINDOW_WIDTH / 2) + data->rect.coordinate_x;
	data->rect.y0 += (WINDOW_HEIGHT / 2) + data->rect.coordinate_y;
	data->rect.y1 += (WINDOW_HEIGHT / 2) + data->rect.coordinate_y;
	draw_lines(data);
}

static void	draw_vertical(t_data *data, int x, int y)
{
	int	xt;
	int	yt;

	xt = x - data->rect.width / 2;
	yt = y - data->rect.height / 2;
	data->rect.x0 = data->rect.angle_x * (xt - yt) * data->rect.zoom;
	data->rect.y0 = data->rect.angle_y * (xt + yt) * data->rect.zoom;
	data->rect.y0 -= data->rect.values[y][x] * data->rect.z_value;
	data->rect.x1 = data->rect.angle_x * (xt - (yt + 1)) * data->rect.zoom;
	data->rect.y1 = data->rect.angle_y * (xt + (yt + 1)) * data->rect.zoom;
	data->rect.y1 -= data->rect.values[y + 1][x] * data->rect.z_value;
	data->rect.x0 += (WINDOW_WIDTH / 2) + data->rect.coordinate_x;
	data->rect.x1 += (WINDOW_WIDTH / 2) + data->rect.coordinate_x;
	data->rect.y0 += (WINDOW_HEIGHT / 2) + data->rect.coordinate_y;
	data->rect.y1 += (WINDOW_HEIGHT / 2) + data->rect.coordinate_y;
	draw_lines(data);
}

int	fdf_draw(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->rect.height > y)
	{
		x = 0;
		while (data->rect.width > x)
		{
			data->rect.x0 = x;
			data->rect.y0 = y;
			data->rect.color = data->rect.color_map[y][x];
			if (data->rect.width > x + 1)
				draw_horizontal(data, x, y);
			if (data->rect.height > y + 1)
				draw_vertical(data, x, y);
			x += 1;
		}
		y += 1;
	}
	return (0);
}

int	render_fdf_draw(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	fdf_draw(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
							data->img.mlx_img, 0, 0);
	return (0);
}
