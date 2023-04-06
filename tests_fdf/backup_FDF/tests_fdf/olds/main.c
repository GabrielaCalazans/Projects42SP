/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:21:47 by gacalaza          #+#    #+#             */
/*   Updated: 2023/02/08 17:18:58 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_tests.h"

int	main()
{
	// void	*mlx_ptr;
	// t_vars	vars;
	// t_data	img;

	// vars.mlx = mlx_init();
	// vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FDF");
	// mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	// mlx_hook(vars.win, 17, 1L<<2, mouse_hook, &vars);
	// //mlx_mouse_hook(vars.win, mouse_hook, &vars);

	// void	*mlx;
	// void	*mlx_win;
	// // int		x;
	// // int		y;
	// // int		ix;
	// // int		iy;
	// t_data	img;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 720, 576, "RESPIRA E NÃO PIRA!");
	// // img.img = mlx_new_image(mlx, 720, 576);
	
	// // mlx_win = mlx_new_window(mlx, 500, 500, "NAO, PIRA2!");
	// // img.img = mlx_new_image(mlx, 500, 500);

	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// printf("bits_per_pixel:[%s]", img.addr);

	// my_mlx_pixel_put(&img, 50, 400, 0x0000FFFF);
	// my_mlx_pixel_put(&img, 51, 400, 0x0000FFFF);
	// my_mlx_pixel_put(&img, 400, 50, 0x0000FFFF);

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
	// int	x0;
	// int	x1;
	// int	y0;
	// int	y1;

	// x0 = 50;
	// x1 = 670;
	// y0 = 50;
	// y1 = 500;

	// while (x0 < x1)
	// {
	// 	my_mlx_pixel_put(&img, x0, y0, 0x0000FFFF);
	// 	x0++;
	// }
	// 	while (y0 < y1)
	// {
	// 	my_mlx_pixel_put(&img, x0, y0, 0x0000FFFF);
	// 	y0++;
	// }
	// while (x0 > 50)
	// {
	// 	my_mlx_pixel_put(&img, x0, y1, 0x0000FFFF);
	// 	x0--;
	// }
	// 	while (y0 > 50)
	// {
	// 	my_mlx_pixel_put(&img, x0, y0, 0x0000FFFF);
	// 	y0--;
	// }
	// x0 = 50;
	// x1 = 670;
	// y0 = 50;
	// y1 = 500;
	// bresenham(x0, y0, x1, y1, img);
	// bresenham(x0, y0, x1, y1, img);
	
	// my_mlx_pixel_put(&img, 600, 50, 0x00FF0000);
	// my_mlx_pixel_put(&img, 500, 500, 0x003300FF);
	// my_mlx_pixel_put(&img, 50, 500, 0x003300FF);
	// my_mlx_pixel_put(&img, 150, 150, 0x0033FF00);
	// my_mlx_pixel_put(&img, 600, 150, 0x0033FF00);
	// mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);

	// //		*********************

	// int	x0;
	// int	x1;
	// int	y0;
	// int	y1;

	// x0 = 400;
	// x1 = 100;
	// y0 = 500;
	// y1 = 300;
	// reta_bresenham(x0, x1, y0, y1, 0x0000FFFF, img);
	// reta_bresenham(400, 100, 500, 300, 0x0000FFFF, img);
	// reta_bresenham(400, 100, 600, 300, 0x0000FFFF, img);
	// reta_bresenham(600, 100, 400, 100, 0x0000FFFF, img);

	// mlx_win = mlx_new_window(mlx, 720, 576, "VAMO, PORRA!");
	
	// bresenham3(50, 50, 670, 520, 0x0000FFFF, img); // diagonal up left to down right
	// // bresenham3(50, 520, 50, 670, 0x0000FFFF, img); // diagonal up right to down left
	// bresenham3(50, 50, 670, 50, 0x0000FFFF, img); // linha up
	// bresenham3(50, 520, 670, 50, 0x0000FFFF, img); // linha down
	// // bresenham3(50, 50, 50, 520, 0x0000FFFF, img); // linha vertical left
	// bresenham3(520, 520, 50, 520, 0x0000FFFF, img); // linha vertical right
	// bresenham4(100, 50, 300, 350, 0x0000FFFF, img); // diagonal up left to down right
	// bresenham4(400, 50, 50, 400, 0x0000FFFF, img); // diagonal up right to down left
	// bresenham4(400, 50, 400, 50, 0x0000FFFF, img); // diagonal up left to down right
	// bresenham4(250, 250, 400, 50, 0x0000FFFF, img); // deveria ser uma linha diagonal

	// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)

	// my_mlx_pixel_put(&img, 50, 400, 0x0000FFFF);
	// my_mlx_pixel_put(&img, 51, 400, 0x0000FFFF);
	// my_mlx_pixel_put(&img, 400, 50, 0x0000FFFF);

	// int mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
	// mlx_pixel_put(mlx, mlx_win, 50, 50, 0x0000FFFF);

	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	if (mlx == NULL)
		return (MLX_ERROR);
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "RESPIRA E NÃO PIRA!");
	if (mlx_win == NULL)
	{
		free(mlx_win);
		return (MLX_ERROR);
	}
	img.img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// *************** BRESENHAM4 INICIO **************************************************************8
	// bresenham4(50, 50, 50, 400, 0x0000FFFF, img); // linha vertical left
	// bresenham4(50, 50, 400, 50, 0x0000FFFF, img); // linha horizontal up
	// bresenham4(400, 400, 400, 50, 0x0000FFFF, img); // linha vertical right
	// bresenham4(400, 400, 50, 400, 0x0000FFFF, img); // linha horizontal down
	// bresenham4(400, 400, 50, 50, 0x0000FFFF, img); // diagonal up left to down right
	// bresenham4(400, 50, 50, 400, 0x0000FFFF, img); // diagonal down left to up right

	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// *************** BRESENHAM4 FIM **************************************************************8

	// //	*********	HOOKS	************
	// mlx_loop_hook(mlx, line_drow, &img));
	mlx_hook(mlx_win, 2, 1L<<0, close, &img);
	mlx_hook(mlx_win, 17, 1L<<2, mouse_hook, &img);
	mlx_loop(mlx);
	mlx_destroy_image(mlx, img.img);
	mlx_destroy_window(mlx, mlx_win);
	mlx_destroy_display(mlx);
	free(mlx);
	free(img.img);
	
	return(0);
}
