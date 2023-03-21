/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:13:37 by gacalaza          #+#    #+#             */
/*   Updated: 2023/03/21 17:18:14 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_destroy_image(fdf->mlx.init, fdf->mlx.img);
	mlx_destroy_window(fdf->mlx.init, fdf->mlx.win);
	mlx_destroy_display(fdf->mlx.init);
	free(fdf->mlx.init);
	while (i < fdf->map.height)
	{
		free (fdf->map.values[i]);
		i++;
	}
	i = 0;
	while (i < fdf->map.height)
	{
		free (fdf->map.color_map[i]);
		i++;
	}
	free (fdf->map.color_map);
	free (fdf->map.values);
	free (fdf);
	exit(0);
}

// int	esc_close(t_fdf *fdf)
// {
// 	int	i;

// 	mlx_destroy_image(fdf->mlx.init, fdf->mlx.img);
// 	mlx_destroy_window(fdf->mlx.init, fdf->mlx.win);
// 	mlx_destroy_display(fdf->mlx.init);
// 	free (fdf->map.values);
// 	free(fdf->mlx.init);
// 	exit(0);
// 	return (0);
// }

// ** Outputs the string msg to the standard output followed by an exit of the
// ** program with a custom return value (defined by ret).

void	ft_puterror(char *msg, int ret)
{
	ft_putendl_fd(msg, 1);
	exit(ret);
}

// ** Display a usage message on how to run and use fdf.

static void	fdf_usage(char *argv0)
{
	(void) argv0;
	ft_putstr_fd("FDF Usage:\n\t", 1);
	ft_putstr_fd("FDF Select one Map at maps/test_map/...:\n\t", 1);
	ft_putstr_fd("Controls:\n", 1);
	ft_putstr_fd("\t[Esc]   -> Exit the program.\n", 1);
	ft_putstr_fd("\t[R]     -> Reset the map.\n", 1);
	ft_putstr_fd("\t[Z][X]  -> Zoom in and zoom out.\n", 1);
	ft_putstr_fd("\t[N][M]  -> Spiky time!\n", 1);
	ft_putstr_fd("\t[Space] -> Change the camera (isometric <-> plain).\n", 1);
	ft_putstr_fd("\t[Arrow Key] or [W][A][S][D] -> Move the map.\n", 1);
}

// ** Main function, creates the fdf structure and a network connection between
// ** the program and the x-server, making it possible to draw on the screen,
// ** and getting the keyboard inputs.
// ** Didn't used mlx_key_hook, because I wanted to press and hold the keys :D

int	main(int argc, char *argv[])
{
	t_fdf	*fdf;

	if (argc == 2)
	{
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
		if (!fdf)
			ft_puterror("Memory Allocation failed! :O", 3);
		fdf_read(argv[1], fdf);
		reset_map(fdf);
		fdf->mlx.init = mlx_init();
		fdf->mlx.win = mlx_new_window(fdf->mlx.init, WIN_WIDTH, \
								WIN_HEIGHT, "FDF");
		fdf->mlx.img = mlx_new_image(fdf->mlx.init, WIN_WIDTH, WIN_HEIGHT);
		fdf->image.data = mlx_get_data_addr(fdf->mlx.img, &fdf->image.bpp, \
								&fdf->image.size, &fdf->image.endian);
		mlx_loop_hook(fdf->mlx.init, render_fdf_draw, fdf);
		mlx_hook(fdf->mlx.win, 2, 3, &key_events, fdf);
		mlx_hook(fdf->mlx.win, 17, 0L, &close_win, fdf);
		mlx_loop(fdf->mlx.init);
		free(fdf->mlx.init);
	}
	else
		fdf_usage(argv[0]);
	return (0);
}
