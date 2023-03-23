/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw-fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:38:26 by gacalaza          #+#    #+#             */
/*   Updated: 2023/03/22 16:20:48 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_tests.h"

void	set_colors(t_data *data, int x, int y)
{
	data->color.red = (data->rect.color_map[y][x] >> 16) & 0xFF;
	data->color.green = (data->rect.color_map[y][x] >> 8) & 0xFF;
	data->color.blue = data->rect.color_map[y][x] & 0xFF;
}

static void	put_pixel(t_data *data, int x, int y, double uvector)
{
	int		pos;

	if ((x > 0 && y > 0) && (x < WINDOW_WIDTH && y < WINDOW_HEIGHT))
	{
		pos = (x * 4) + (y * WINDOW_WIDTH * 4);
		data->img.addr[pos] = data->color.red + uvector;
		data->img.addr[pos + 1] = data->color.blue + uvector;
		data->img.addr[pos + 2] = data->color.green + uvector;
		data->img.addr[pos + 3] = 0x7F + uvector;
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

// ** Draw the map, depending on the angles, the zoom level,
// ** the position (defined)
// ** by the average value of the window size, and if the
// ** user has moved the map,
// ** and the x value (isometric).
// ** Will draw horizontal lines (x axis).

static void	draw_horizontal(t_fdf *fdf, int x, int y)
{
	int	xt;
	int	yt;
	// Define as coordenadas x e y do pixel em relação ao centro
	xt = x - fdf->map.width / 2;
	yt = y - fdf->map.height / 2;
	// Calculo das coordenadas x e y do ponto inicial da linha
	fdf->map.x0 = fdf->map.angle_x * (xt - yt) * fdf->map.zoom;
	fdf->map.y0 = fdf->map.angle_y * (xt + yt) * fdf->map.zoom;
	// Calcula a altura do ponto inicial da linha em relação ao eixo z
	fdf->map.y0 -= fdf->map.values[y][x] * fdf->map.z_value;
	// Calcula as coordenadas x e y do ponto final da linha
	fdf->map.x1 = fdf->map.angle_x * ((xt + 1) - yt) * fdf->map.zoom;
	fdf->map.y1 = fdf->map.angle_y * ((xt + 1) + yt) * fdf->map.zoom;
	// Calcula a altura do ponto final da linha em relação ao eixo z
	fdf->map.y1 -= fdf->map.values[y][x + 1] * fdf->map.z_value;
	// Adiciona as coordenadas x e y do ponto inicial da linha ao centro da tela e ao deslocamento x
	fdf->map.x0 += (WIN_WIDTH / 2) + fdf->map.coordinate_x;
	// Adiciona as coordenadas x e y do ponto final da linha ao centro da tela e ao deslocamento x
	fdf->map.x1 += (WIN_WIDTH / 2) + fdf->map.coordinate_x;
	// Adiciona as coordenadas y do ponto inicial da linha ao centro da tela e ao deslocamento y
	fdf->map.y0 += (WIN_HEIGHT / 2) + fdf->map.coordinate_y;
	// Adiciona as coordenadas y do ponto final da linha ao centro da tela e ao deslocamento y
	fdf->map.y1 += (WIN_HEIGHT / 2) + fdf->map.coordinate_y;
	draw_lines(fdf);
}

// ** Draw the map, depending on the angles, the zoom level, 
// ** the position (defined)
// ** by the average value of the window size, and if the user 
// ** has moved the map,
// ** and the x value (isometric).
// ** Will draw vertical lines (y axis).

static void	draw_vertical(t_fdf *fdf, int x, int y)
{
	int	xt;
	int	yt;

	// Define as coordenadas x e y do pixel em relação ao centro
	xt = x - fdf->map.width / 2;
	yt = y - fdf->map.height / 2;
	// Calculo coordenadas x e y do ponto inicial da linha c/base na posição em relacão ao centro da tela e angulo de rotação horizontal/vertical anglex/y, no zoom e width
	fdf->map.x0 = fdf->map.angle_x * (xt - yt) * fdf->map.zoom;
	fdf->map.y0 = fdf->map.angle_y * (xt + yt) * fdf->map.zoom;
	// Calculo altura y do ponto inicial da linha em relação a altura eixo z
	fdf->map.y0 -= fdf->map.values[y][x] * fdf->map.z_value;
	// Calcula as coordenadas x e y do ponto final da linha com base na posição do ponto abaixo do atual
	fdf->map.x1 = fdf->map.angle_x * (xt - (yt + 1)) * fdf->map.zoom;
	fdf->map.y1 = fdf->map.angle_y * (xt + (yt + 1)) * fdf->map.zoom;
	// Calcula a altura do ponto final da linha em relação ao eixo z
	//  subtração é feita porque, no sistema de coordenadas de um computador, a coordenada y cresce de 
	// cima para baixo. Então, para desenhar uma linha vertical que vá do ponto (x, y) para o ponto (x, y+1), 
	// a coordenada y do ponto final precisa ser maior do que a coordenada y do ponto inicial. No entanto, os valores de altitude da matriz fdf->map.values[y+1][x] 
	// representam a altura do ponto mais alto, então subtraímos esse valor para descer a linha na tela.
	fdf->map.y1 -= fdf->map.values[y + 1][x] * fdf->map.z_value;
	// Adiciona as coordenadas x e y do ponto inicial da linha ao centro da tela e ao deslocamento x
	fdf->map.x0 += (WIN_WIDTH / 2) + fdf->map.coordinate_x;
	// Adiciona as coordenadas x e y do ponto final da linha ao centro da tela e ao deslocamento x
	fdf->map.x1 += (WIN_WIDTH / 2) + fdf->map.coordinate_x;
	// Adiciona as coordenadas y do ponto inicial da linha ao centro da tela e ao deslocamento y
	fdf->map.y0 += (WIN_HEIGHT / 2) + fdf->map.coordinate_y;
	// Adiciona as coordenadas y do ponto final da linha ao centro da tela e ao deslocamento y
	fdf->map.y1 += (WIN_HEIGHT / 2) + fdf->map.coordinate_y;
	draw_lines(fdf);
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
			// data->rect.color = data->rect.color_map[y][x];
			// printf("color_map[y:%d][x:%d] color: [%d] ", y, x, data->rect.color);
			set_colors(data, x, y);
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
