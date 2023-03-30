/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 00:46:22 by gacalaza          #+#    #+#             */
/*   Updated: 2023/03/29 21:09:06 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	fdf->map.angle_x = cos(M_PI / 3);
	fdf->map.angle_y = fdf->map.angle_x * sin(M_PI / 6);
	fdf->map.zoom = zoom_change(fdf);
	fdf->color.red = 0x4F;
	fdf->color.green = 0x4F;
	fdf->color.blue = 0x4F;
}

// ** Assign a key code (macros defined in "includes/keys.h")
// ** to a specific task,
// ** like changing colors, moving the map, changing the view, zoom level, etc.
// ** There is an ugly code for changing the view (angle) of the map, because of
// ** norm... I guess? Everytime "map.isometric" isn't even, rotate the map.

int	key_events(int key, t_fdf *fdf)
{
	if (key == KEY_ESCAPE)
		close_win(fdf);
	return (0);
}
