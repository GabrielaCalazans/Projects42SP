/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:30:49 by gacalaza          #+#    #+#             */
/*   Updated: 2023/03/16 00:33:07 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_tests.h"


int main (int argc, char *argv[])
{
	t_data	*data;

	if (argc == 2)
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
		{
			printf("Oh Shit! mallocoff");
			return(0);
		}
		fdf_read(argv[1], data);
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
		data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, \
									&data->img.line_len, &data->img.endian);

		// print_values_loop(data);
		// print_values_loop(argv, data);
	
		// //	*******************	HOOKS	*********************

		mlx_loop_hook(data->mlx_ptr, render_fdf_draw, data);
		// mlx_loop_hook(data->mlx_ptr, print_values_loop, data);
		mlx_hook(data->win_ptr, 17, 0L, &close_win, data);
		mlx_hook(data->win_ptr, 2, 3, &key_events, data); // aqui eu lido com o momento de presskey, aqui é mais completo
		mlx_loop(data->mlx_ptr);
		// mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		// mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		// mlx_destroy_display(data->mlx_ptr);
		// free(data->mlx_ptr);
		// free(data->img.mlx_img);
	}
	else if (argc > 2)
		printf("too many arguments; bro!");
	else if (argc < 2)
		printf("too fill argument, help me, to help you ;)");

	return(0);
}
