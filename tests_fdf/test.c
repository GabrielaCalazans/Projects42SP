/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:21:47 by gacalaza          #+#    #+#             */
/*   Updated: 2023/01/21 18:44:59 by gacalaza         ###   ########.fr       */
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

int main(int argc, char *argv[])
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
	mlx_win = mlx_new_window(mlx, 720, 576, "Fdf!");
	img.img = mlx_new_image(mlx, 720, 576);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// printf("bits_per_pixel:[%p]", img.addr);

	y = 50;
	x = 670;
	ix = 50;
	iy = 500;
	while (ix < x)
	{
		my_mlx_pixel_put(&img, ix, y, 0x0000FFFF);
		ix++;
	}
		while (iy > y)
	{
		my_mlx_pixel_put(&img, x, iy, 0x0000FFFF);
		iy--;
	}
	while (ix > 50)
	{
		my_mlx_pixel_put(&img, ix, 500, 0x0000FFFF);
		ix--;
	}
		while (iy < 500)
	{
		my_mlx_pixel_put(&img, 50, iy, 0x0000FFFF);
		iy++;
	}
		while (iy > y && ix < x)
	{
		my_mlx_pixel_put(&img, x, y, 0x0000FFFF);
		y++;
		x--;
		// if (iy == y || iy > y)
		// {
		// 	x--;
		// 	y = 499;
		// }
		printf(" x:%d y:%d", x, y);
	}
		while (iy > 50 && ix < 670)
	{
		my_mlx_pixel_put(&img, ix, iy, 0x0000FFFF);
		iy--;
		ix++;
		// printf(" %d ", x);
		// printf(" %d ", y);
	}
	// my_mlx_pixel_put(&img, 600, 50, 0x00FF0000);
	// my_mlx_pixel_put(&img, 500, 500, 0x003300FF);
	// my_mlx_pixel_put(&img, 50, 500, 0x003300FF);
	// my_mlx_pixel_put(&img, 150, 150, 0x0033FF00);
	// my_mlx_pixel_put(&img, 600, 150, 0x0033FF00);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	
	// mlx_loop_hook(mlx, line_drow, &img));

	mlx_hook(mlx_win, 2, 1L<<0, close, &img);
	mlx_hook(mlx_win, 17, 1L<<2, mouse_hook, &img);
	mlx_loop(mlx);
	
	return(0);
}

