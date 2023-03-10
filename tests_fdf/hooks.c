/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:38:10 by gacalaza          #+#    #+#             */
/*   Updated: 2023/03/09 01:32:11 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_tests.h"

int	close_win(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int	esc_close(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

static int	zoom_change(t_data *data)
{
	int	result;

	if (data->rect.width > data->rect.height)
		result = (WINDOW_WIDTH / data->rect.width);
	else
		result = (WINDOW_HEIGHT / data->rect.height);
	return (result);
}

void	reset_map(t_data *data)
{
	data->rect.coordinate_y = 0;
	data->rect.coordinate_x = 0;
	data->rect.z_value = 1.00;
	data->rect.angle_x = cos(M_PI / 3); // 1/2 0,5
	data->rect.angle_y = data->rect.angle_x * sin(M_PI / 6); // 0,25 ==
	// data->rect.width = 600;
	// data->rect.height = 300;
	data->rect.isometric = 1;
	data->rect.zoom = zoom_change(data);
	data->rect.color = 0x00CC0000;
	// data->color.green = 0x4F;
	// data->color.blue = 0x4F;
}

void	isometric_change(t_data *data)
{
	if (data->rect.isometric++ % 2)
		data->rect.angle_y *= 0.2;
	else
		data->rect.angle_y *= 5;
}


int	fdf_keys(int keycode, t_data *data)
{
	if (keycode == KEY_ESCAPE)
		esc_close(data);
	else if (keycode == KEY_R)
		reset_map(data);
//	else if (keycode == KEY_C)
//		wishing_a_random_color_func(data);
	else if (keycode == KEY_W || keycode == KEY_UPARROW)
		data->rect.coordinate_y -= 1;
	else if (keycode == KEY_S || keycode == KEY_DOWNARROW)
		data->rect.coordinate_y += 1;
	else if (keycode == KEY_D || keycode == KEY_RIGHTARROW)
		data->rect.coordinate_x -= 1;
	else if (keycode == KEY_A || keycode == KEY_LEFTARROW)
		data->rect.coordinate_x += 1;
	else if (keycode == KEY_Z)
		data->rect.zoom += 1;
	else if ((keycode == KEY_X) && (data->rect.zoom > MAX_ZOOM))
		data->rect.zoom -= 1;
	else if ((keycode == KEY_M) && (data->rect.z_value < MAX_X))
		data->rect.z_value += 0.25;
	else if ((keycode == KEY_N) && (data->rect.z_value > -MAX_X))
		data->rect.z_value -= 0.25;
	else if (keycode == KEY_SPACE)
		isometric_change(data);
	return (0);
}

int	key_events(int key, t_data *data)
{
	fdf_keys(key, data);
	mlx_clear_window((data)->mlx_ptr, (data)->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	data->img.mlx_img  = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	render_fdf_draw((data));
	mlx_put_image_to_window((data)->mlx_ptr, data->win_ptr, \
							(data)->img.mlx_img, 0, 0);
	return (0);
}

// int	close(int keycode, t_vars *vars)
// {
	
// 	if (keycode == 65307)
// 	{
// 		mlx_destroy_window(vars->mlx, vars->win);
// 		exit (0);
// 	}
// 	else
// 		printf("%i\n", keycode);
	
// 	return (0);
// }

// int	mouse_hook(t_vars *vars)
// {
// 	// if (keycode == 1)
// 	// {
// 		mlx_destroy_window(vars->mlx, vars->win);
// 		exit (0);
// 	// }
// 	// else
// 	// 	printf("keycode: %i\n", keycode);
// 	return (0);
// }

// int	handle_keypress(int keysym, t_data *data)
// {
// 	if (keysym == XK_Escape)
// 	{
// 		printf("Keypress: %c %i %X\n", keysym, keysym, keysym);
// 		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 		data->win_ptr = NULL;
// 		exit (0);
// 	}
// 	else
// 		printf("Keypress: char:%c int:%i HEX:%X\n", keysym, keysym, keysym);
// 	return (0);
// }
