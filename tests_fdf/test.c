/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:21:47 by gacalaza          #+#    #+#             */
/*   Updated: 2023/01/20 14:54:29 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int main(int argc, char *argv[])
{
	// void	*mlx_ptr;
	// t_vars	vars;
	// t_data	img;

	//int offset = (y * line_length + x * (bits_per_pixel / 8));
	// vars.mlx = mlx_init();
	// vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FDF");
	// mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	// mlx_hook(vars.win, 17, 1L<<2, mouse_hook, &vars);
	// //mlx_mouse_hook(vars.win, mouse_hook, &vars);

	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 720, 576, "Fdf!");
	img.img = mlx_new_image(mlx, 720, 576);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 50, 50, 0x00FF0000);
	my_mlx_pixel_put(&img, 600, 50, 0x00FF0000);
	my_mlx_pixel_put(&img, 500, 500, 0x003300FF);
	my_mlx_pixel_put(&img, 50, 500, 0x003300FF);
	my_mlx_pixel_put(&img, 150, 150, 0x0033FF00);
	my_mlx_pixel_put(&img, 600, 150, 0x0033FF00);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_hook(mlx_win, 2, 1L<<0, close, &img);
	mlx_hook(mlx_win, 17, 1L<<2, mouse_hook, &img);
	mlx_loop(mlx);
	
	return(0);
}

