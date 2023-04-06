/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_aureli.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:30:49 by gacalaza          #+#    #+#             */
/*   Updated: 2023/03/01 23:56:58 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_tests.h"

int main ()
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "RESPIRA E NAO PIRA!");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);

	// //	*******************	HOOKS	*********************
	// mlx_loop_hook(mlx, line_drow, &img));

	mlx_loop_hook(data.mlx_ptr, &render_bresenham6, &data);
	// mlx_loop_hook(data.mlx_ptr, &render, &data);
	// img_pix_put(&data.img, 100, 100, 0x0099FF66);
	// img_pix_put(&data.img, 400, 400, 0x0099FF66);
	// img_pix_put(&data.img, 100, 400, 0x0099FF66);
	// img_pix_put(&data.img, 400, 100, 0x0099FF66);
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 0, 0);
	//mlx_key_hook(data.win_ptr, &handle_keypress, &data); // aqui eu lido com o momento de soltar a tecla
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data); // aqui eu lido com o momento de presskey, aqui é mais completo
	mlx_hook(data.win_ptr, 17, KeyPressMask, mouse_hook, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	free(data.img.mlx_img);
	
	return(0);
}
