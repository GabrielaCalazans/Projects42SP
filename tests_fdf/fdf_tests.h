/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_tests.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:21:01 by gacalaza          #+#    #+#             */
/*   Updated: 2023/02/16 22:30:14 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TESTS_H
# define FDF_TESTS_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <X11/keysym.h> // PODEMOS USAR? header in order to get the values of all the available symbol
# include <X11/X.h> // PODEMOS USAR? macros releated to the event names/masks

# define WINDOW_WIDTH 720 // LARGURA
# define WINDOW_HEIGHT 570 // ALTURA
# define MLX_ERROR 1

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len; //amount of bytes taken by one row of our image. It is equivalent to image_width * (bpp / 8)
	int		endian;
}				t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img; // was void *img;
	char	*addr;
	int		bits_per_pixel; // for main.c
	int		line_length; // for main.c
	int		endian; // for main.c
}				t_data;

typedef struct s_next
{
	int	x;
	int	y;
	int	prev;
}				t_next;

typedef struct s_dw_line
{
	int	decision_x;
	int	decision_y;
	int	fork;
	int	p;
	int	validate_negative;
}				t_dw_line;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

void	reta_bresenham(int x0, int x1, int y0, int y1, int cor, t_data img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	my_put_pixel(t_data *data, int x, int y, int color);
void	bresenham3(int x0, int x1, int y0, int y1, int cor, t_data img);
void	bresenham(int x0, int y0, int x1, int y1, t_data img);
void	bresenham4(int x0, int y0, int x1, int y1, int cor, t_data img);
int		mouse_hook(t_vars *vars);
int		close(int keycode, t_vars *vars);
int		handle_keypress(int keysym, t_data *data);
int		render(t_data *data);
int		render_rect(t_img *data, t_rect rect);
void	render_background(t_img *data, int color);
void	img_pix_put(t_img *img, int x, int y, int color);
void	bresenham5(t_img *img, t_rect rect);
int		render_bresenham5(t_data *data);
int		render_bresenham6(t_data *data);
void	bresenham6(t_img *img, t_rect rect);

#endif