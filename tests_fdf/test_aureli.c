/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_aureli.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:30:49 by gacalaza          #+#    #+#             */
/*   Updated: 2023/02/08 19:48:28 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_tests.h"
#include <X11/keysym.h> // PODEMOS USAR?

int main ()
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "RESPIRA E NÃO PIRA!");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	data.img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

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

	mlx_loop_hook(data.mlx_ptr, &render, &data);
    mlx_hook(data.win_ptr, 2, 1L<<0, &handle_keypress, &data);
	// mlx_hook(data.win_ptr, 2, 1L<<0, close, &data);
	mlx_hook(data.win_ptr, 17, 1L<<2, mouse_hook, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	free(data.img);
	
	return(0);
}
