/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:38:10 by gacalaza          #+#    #+#             */
/*   Updated: 2023/03/03 17:19:28 by gacalaza         ###   ########.fr       */
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
