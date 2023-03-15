/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_tests.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:21:01 by gacalaza          #+#    #+#             */
/*   Updated: 2023/03/15 16:59:12 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TESTS_H
# define FDF_TESTS_H

# include <mlx.h>
# include <unistd.h> // CLOSE READ WRITE
# include <fcntl.h> // OPEN
# include <stdio.h> // PERROR
# include <string.h> // STRERROR
# include <stdlib.h> // MALLOC FREE EXIT
# include <math.h>

// **** WARNING! DO NOT USE IN THIS PROJECT ***********
# include <X11/keysym.h> // BETTER NOT TO USE: header in order to get the values of all the available symbol
# include <X11/X.h> // BETTER NOT TO USE: macros releated to the event names/masks

// *** MY ****
# include "keys.h"
# include "libft/libft.h"

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define MAX_X			(10)
# define MAX_ZOOM		(5)
# define MAGIC_ZOOM		(2)
# define MLX_ERROR 1

// typedef struct s_vars
// {
// 	void	*mlx;
// 	void	*win;
// }			t_vars;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len; //amount of bytes taken by one row of our image. It is equivalent to image_width * (bpp / 8)
	int		endian;
}			t_img;

typedef struct	s_color
{
	int		red;
	int		green;
	int		blue;
}			t_color;

typedef struct s_rect
{
	int		**values;
	int		**color_map;
	int		color;
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	int		zoom;
	int		width;
	int		height;
	double	z_value;
	double	angle_x;
	double	angle_y;
	
	int		coordinate_x;
	int		coordinate_y;
	int		isometric;
}			t_rect;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img; // was void *img;
	t_rect	rect;
	// char	*addr;
	// int		bits_per_pixel; // for main.c
	// int		line_length; // for main.c
	// int		endian; // for main.c

	t_color	color;
}			t_data;

// typedef struct s_next
// {
// 	int		x;
// 	int		y;
// 	int		prev;
// }		t_next;

// typedef struct s_dw_line
// {
// 	int	decision_x;
// 	int	decision_y;
// 	int	fork;
// 	int	p;
// 	int	validate_negative;
// }	t_dw_line;


// void	reta_bresenham(int x0, int x1, int y0, int y1, int cor, t_data img);
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
// void	my_put_pixel(t_data *data, int x, int y, int color);
// void	bresenham3(int x0, int x1, int y0, int y1, int cor, t_data img);
// void	bresenham(int x0, int y0, int x1, int y1, t_data img);
// void	bresenham4(int x0, int y0, int x1, int y1, int cor, t_data img);
// int		mouse_hook(t_vars *vars);
// // int		close(int keycode, t_vars *vars);
// int		handle_keypress(int keysym, t_data *data);
// int		render(t_data *data);
// int		render_rect(t_img *data, t_rect rect);
void	render_background(t_img *data, int color);
// void	img_pix_put(t_img *img, int x, int y, int color);
// void	bresenham5(t_img *img, t_rect rect);
// int		render_bresenham5(t_data *data);
// int		render_bresenham6(t_data *data);
// void	bresenham6(t_img *img, t_rect rect);
int		render_fdf_draw(t_data *data);
int		close_win(t_data *data);
int		esc_close(t_data *data);
void	fdf_read(char *argv, t_data *data);
// int		print_values_loop(char **argv, t_data *data);
int		key_events(int key, t_data *data);
void	reset_map(t_data *data);
int		ft_atoh(char *hex);

#endif