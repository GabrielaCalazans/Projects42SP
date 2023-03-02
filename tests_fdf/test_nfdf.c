/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_nfdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:30:49 by gacalaza          #+#    #+#             */
/*   Updated: 2023/03/02 01:45:45 by gacalaza         ###   ########.fr       */
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

// static int	zoom_change(t_data *data)
// {
// 	int	result;

// 	if (data->rect.width > data->rect.height)
// 		result = (WINDOW_WIDTH / data->rect.width);
// 	else
// 		result = (WINDOW_HEIGHT / data->rect.height);
// 	return (result);
// }

static void	reset_map(t_data *data)
{
	data->rect.coordinate_y = 0;
	data->rect.coordinate_x = 0;
	data->rect.angle_x = cos(M_PI / 3); // 1/2 0,5
	data->rect.angle_y = data->rect.angle_x * sin(M_PI / 6); // 1/2 0,5
	data->rect.width = 600;
	data->rect.height = 300;
	data->rect.isometric = 1;
	// data->rect.zoom = zoom_change(data);
	data->color.red = 0x4F;
	data->color.green = 0x4F;
	data->color.blue = 0x4F;
}

static void	isometric_change(t_data *data)
{
	if (data->rect.isometric++ % 2)
		data->rect.angle_y *= 0.2;
	else
		data->rect.angle_y *= 5;
}

static int	fdf_keys(int keycode, t_data *data)
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
	// else if ((keycode == KEY_M) && (data->rect.z_value < MAX_X))
	// 	data->rect.z_value += 0.25;
	// else if ((keycode == KEY_N) && (data->rect.z_value > -MAX_X))
	// 	data->rect.z_value -= 0.25;
	else if (keycode == KEY_SPACE)
		isometric_change(data);
	return (0);
}

int main ()
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		printf("Oh Shit!");
		return(0);
	}
	reset_map(data);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "RESPIRA E NAO PIRA!");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (MLX_ERROR);
	}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);

	// //	*******************	HOOKS	*********************
	mlx_loop_hook(data->mlx_ptr, render_fdf_draw, data);
	mlx_hook(data->win_ptr, 2, 3, &fdf_keys, data); // aqui eu lido com o momento de presskey, aqui é mais completo
	mlx_hook(data->win_ptr, 17, 0L, &close_win, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->img.mlx_img);
	
	return(0);
}
