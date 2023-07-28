/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rate_moves_btoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:32:49 by gacalaza          #+#    #+#             */
/*   Updated: 2023/07/28 17:33:02 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	rate_rr_btoa(t_stack *a, t_stack *b, int check)
{
	int	result;

	result = track_pos_a(a, check);
	if (result < ft_int_pos(b, check))
		result = ft_int_pos(b, check);
	return (result);
}

int	rate_rrr_btoa(t_stack *a, t_stack *b, int check)
{
	int	result;

	result = 0;
	if (track_pos_a(a, check))
		result = ft_size(a) - track_pos_a(a, check);
	if (result < (ft_size(b) - ft_int_pos(b, check)) && ft_int_pos(b, check))
		result = ft_size(b) - ft_int_pos(b, check);
	return (result);
}

int	rate_ra_rrb_btoa(t_stack *a, t_stack *b, int check)
{
	int	result;

	result = 0;
	if (track_pos_a(a, check))
		result = ft_size(a) - track_pos_a(a, check);
	result += ft_int_pos(b, check);
	return (result);
}

int	rate_rb_rra_btoa(t_stack *a, t_stack *b, int check)
{
	int	result;

	result = 0;
	if (ft_int_pos(b, check))
		result = ft_size(b) - ft_int_pos(b, check);
	result += track_pos_a(a, check);
	return (result);
}
