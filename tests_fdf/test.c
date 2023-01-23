/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:21:47 by gacalaza          #+#    #+#             */
/*   Updated: 2023/01/23 22:49:40 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	close(int keycode, t_vars *vars)
{
	
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	else
		printf("%i\n", keycode);
	
	return (0);
}

int	mouse_hook(int keycode, t_vars *vars)
{
	// if (keycode == 1)
	// {
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	// }
	// else
	// 	printf("%i\n", keycode);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	//int offset = (y * line_length + x * (bits_per_pixel / 8));
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// int	line_drow(t_data *data, int x, int y, void *img)
// {
// 		char	*dest;

		// dest = data->addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//		while ()
// }

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

void	bresenham(int x0, int y0, int x1, int y1, t_data img)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	x02;
	int	y02;
	int	err2;

	x02 = x0;
	y02 = y0;
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
	if (dx > dy )
		err = dx / 2;
	else
		err = -dy / 2;
	err2 = err;
	while (x0 != x1 || y0 != y1)
	{
		int e2;

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
		while (x02 != x1 || y02 != y1)
	{
		int e2;

		e2 = err2;
		my_mlx_pixel_put(&img, x02, y02, 0x0000FFFF);
		if (e2 < -dx)
		{
			err += dy;
			x02 += sx;
		}
		if (e2 < dy)
		{
			err2 += dx;
			y02 += sy;
		}
	}
}

int	main(int argc, char *argv[])
{
	// void	*mlx_ptr;
	// t_vars	vars;
	// t_data	img;

	// vars.mlx = mlx_init();
	// vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FDF");
	// mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	// mlx_hook(vars.win, 17, 1L<<2, mouse_hook, &vars);
	// //mlx_mouse_hook(vars.win, mouse_hook, &vars);

	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	int		ix;
	int		iy;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 720, 576, "VAMO, PORRA!");
	img.img = mlx_new_image(mlx, 720, 576);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// printf("bits_per_pixel:[%p]", img.addr);

		//	******************########************************
	// y = 50;
	// x = 670;
	// ix = 50;
	// iy = 500;
	// while (ix < x)
	// {
	// 	my_mlx_pixel_put(&img, ix, y, 0x0000FFFF);
	// 	ix++;
	// }
	// 	while (iy > y)
	// {
	// 	my_mlx_pixel_put(&img, x, iy, 0x0000FFFF);
	// 	iy--;
	// }
	// while (ix > 50)
	// {
	// 	my_mlx_pixel_put(&img, ix, 500, 0x0000FFFF);
	// 	ix--;
	// }
	// 	while (iy < 500)
	// {
	// 	my_mlx_pixel_put(&img, 50, iy, 0x0000FFFF);
	// 	iy++;
	// }
	// 	while (iy > y && ix < x || 500 > y && 50 < x )
	// {
	// 	my_mlx_pixel_put(&img, x, y, 0x0000FFFF);
	// 	y++;
	// 	x = x -2;
	// 	// if (iy == y || iy > y)
	// 	// {
	// 	// 	x--;
	// 	// 	y = 499;
	// 	// }
	// 	printf(" x:%d y:%d", x, y);
	// 	printf("iy:[%d] ix[%d]", iy, ix);
	// }
	// 	while (iy > 50 && ix < 670)
	// {
	// 	my_mlx_pixel_put(&img, ix, iy, 0x0000FFFF);
	// 	iy--;
	// 	ix++;
	// 	// printf(" %d ", x);
	// 	// printf(" %d ", y);
	// }

		//	******************########************************
	int	x0;
	int	x1;
	int	y0;
	int	y1;

	x0 = 50;
	x1 = 670;
	y0 = 50;
	y1 = 500;

	while (x0 < x1)
	{
		my_mlx_pixel_put(&img, x0, y0, 0x0000FFFF);
		x0++;
	}
		while (y0 < y1)
	{
		my_mlx_pixel_put(&img, x0, y0, 0x0000FFFF);
		y0++;
	}
	while (x0 > 50)
	{
		my_mlx_pixel_put(&img, x0, y1, 0x0000FFFF);
		x0--;
	}
		while (y0 > 50)
	{
		my_mlx_pixel_put(&img, x0, y0, 0x0000FFFF);
		y0--;
	}
	x0 = 50;
	x1 = 670;
	y0 = 50;
	y1 = 500;
	bresenham(x0, y0, x1, y1, img);

	
	// my_mlx_pixel_put(&img, 600, 50, 0x00FF0000);
	// my_mlx_pixel_put(&img, 500, 500, 0x003300FF);
	// my_mlx_pixel_put(&img, 50, 500, 0x003300FF);
	// my_mlx_pixel_put(&img, 150, 150, 0x0033FF00);
	// my_mlx_pixel_put(&img, 600, 150, 0x0033FF00);
	// mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	
	// mlx_loop_hook(mlx, line_drow, &img));

	mlx_hook(mlx_win, 2, 1L<<0, close, &img);
	mlx_hook(mlx_win, 17, 1L<<2, mouse_hook, &img);
	mlx_loop(mlx);
	mlx_destroy_image(mlx, img.img);
	
	return(0);
}

