/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rate_moves_atob.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:36:47 by gacalaza          #+#    #+#             */
/*   Updated: 2023/07/28 17:35:39 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	rate_rr_atob(t_stack *a, t_stack *b, int check)
{
	int	result;

	result = check_pos_b(b, check);
	if (result < ft_int_pos(a, check))
		result = ft_int_pos(a, check);
	return (result);
}

int	rate_rrr_atob(t_stack *a, t_stack *b, int check)
{
	int	result;

	result = 0;
	if (check_pos_b(b, check))
		result = ft_size(b) - check_pos_b(b, check);
	if (result < (ft_size(a) - ft_int_pos(a, check)) && ft_int_pos(a, check))
		result = ft_size(a) - ft_int_pos(a, check);
	return (result);
}

int	rate_ra_rrb_atob(t_stack *a, t_stack *b, int check)
{
	int	result;

	result = 0;
	if (check_pos_b(b, check))
		result = ft_size(b) - check_pos_b(b, check);
	result += ft_int_pos(a, check);
	return (result);
}

int	rate_rb_rra_atob(t_stack *a, t_stack *b, int check)
{
	int	result;

	result = 0;
	if (ft_int_pos(a, check))
		result = ft_size(a) - ft_int_pos(a, check);
	result += check_pos_b(b, check);
	return (result);
}
