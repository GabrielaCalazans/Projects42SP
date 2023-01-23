/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:21:01 by gacalaza          #+#    #+#             */
/*   Updated: 2023/01/23 19:01:32 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
# define ABS(Value) ((Value < 0) ? (Value * -1) : (Value));

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_next
{
	int	x;
	int	y;
	int	prev;
}				t_next;

typedef struct	s_dw_line
{
	int	decision_x;
	int	decision_y;
	int	fork;
	int	p;
	int	validate_negative;
}				t_dw_line;
