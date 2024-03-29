/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 00:46:22 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/01 11:51:45 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	zoom_change(t_fdf *fdf)
{
	int	result;

	if (fdf->map.width > fdf->map.height)
		result = (WIN_WIDTH / fdf->map.width) + MAGIC_ZOOM;
	else
		result = (WIN_HEIGHT / fdf->map.height) + MAGIC_ZOOM;
	return (result);
}

// ** Reset the map to the initial values.

void	reset_map(t_fdf *fdf)
{
	fdf->map.coordinate_y = 0;
	fdf->map.coordinate_x = 0;
	fdf->map.z_value = 1.00;
	fdf->map.angle_x = cos(M_PI / 3); 
	fdf->map.angle_y = fdf->map.angle_x * sin(M_PI / 6);
	fdf->map.isometric = 1;
	fdf->map.zoom = zoom_change(fdf);
	fdf->color.red = 0x4F;
	fdf->color.green = 0x4F;
	fdf->color.blue = 0x4F;
}

static void	isometric_change(t_fdf *fdf)
{
	if (fdf->map.isometric++ % 2)
		fdf->map.angle_y *= 0.2;
	else
		fdf->map.angle_y *= 5;
}

// ** Assign a key code (macros defined in "includes/keys.h")
// ** to a specific task,
// ** like changing colors, moving the map, changing the view, zoom level, etc.
// ** There is an ugly code for changing the view (angle) of the map, because of
// ** norm... I guess? Everytime "map.isometric" isn't even, rotate the map.

static int	fdf_keys(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESCAPE)
		close_win(fdf);
	else if (keycode == KEY_R)
		reset_map(fdf);
	else if (keycode == KEY_W || keycode == KEY_UPARROW)
		fdf->map.coordinate_y -= 1;
	else if (keycode == KEY_S || keycode == KEY_DOWNARROW)
		fdf->map.coordinate_y += 1;
	else if (keycode == KEY_D || keycode == KEY_RIGHTARROW)
		fdf->map.coordinate_x -= 1;
	else if (keycode == KEY_A || keycode == KEY_LEFTARROW)
		fdf->map.coordinate_x += 1;
	else if (keycode == KEY_Z)
		fdf->map.zoom += 1;
	else if ((keycode == KEY_X) && (fdf->map.zoom > MAX_ZOOM))
		fdf->map.zoom -= 1;
	else if ((keycode == KEY_N) && (fdf->map.z_value < MAX_X))
		fdf->map.z_value += 0.25;
	else if ((keycode == KEY_M) && (fdf->map.z_value > -MAX_X))
		fdf->map.z_value -= 0.25;
	else if (keycode == KEY_SPACE)
		isometric_change(fdf);
	return (0);
}

int	key_events(int key, t_fdf *fdf)
{
	fdf_keys(key, fdf);
	mlx_clear_window(fdf->mlx.init, fdf->mlx.win);
	mlx_destroy_image(fdf->mlx.init, fdf->mlx.img);
	fdf->mlx.img = mlx_new_image(fdf->mlx.init, WIN_WIDTH, WIN_HEIGHT);
	render_fdf_draw((fdf));
	mlx_put_image_to_window(fdf->mlx.init, fdf->mlx.win, fdf->mlx.img, 0, 0);
	return (0);
}
