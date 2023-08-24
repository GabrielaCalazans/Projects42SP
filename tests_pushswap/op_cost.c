/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:30:27 by gacalaza          #+#    #+#             */
/*   Updated: 2023/08/02 16:56:55 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	track_pos_b(t_stack *b, int check)
{
	t_stack	*temp;
	int		pos;

	pos = 1;
	if (check > b->index && check < ft_last(b)->index)
		pos = 0;
	else if (check > ft_max(b) || check < ft_min(b))
		pos = ft_int_pos(b, ft_max(b));
	else
	{
		temp = b->next;
		while (temp)
		{
			if (check > b->index || check < temp->index)
				pos++;
			else
				break ;
			temp = temp->next;
			b = b->next;
		}
	}
	return (pos);
}

int	check_op_a_to_b(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*temp;

	temp = a;
	i = rate_rrr_atob(a, b, a->index);
	while (temp)
	{
		if (i > rate_rr_atob(a, b, temp->index))
			i = rate_rr_atob(a, b, temp->index);
		if (i > rate_rrr_atob(a, b, temp->index))
			i = rate_rrr_atob(a, b, temp->index);
		if (i > rate_ra_rrb_atob(a, b, temp->index))
			i = rate_ra_rrb_atob(a, b, temp->index);
		if (i > rate_rb_rra_atob(a, b, temp->index))
			i = rate_rb_rra_atob(a, b, temp->index);
		temp = temp->next;
	}
	return (i);
}

int	track_pos_a(t_stack *a, int check)
{
	t_stack	*temp;
	int		pos;

	pos = 1;
	if (check < a->index && check > ft_last(a)->index)
		pos = 0;
	else if (check > ft_max(a) || check < ft_min(a))
		pos = ft_int_pos(a, ft_min(a));
	else
	{
		temp = a->next;
		while (temp)
		{
			if (check < a->index || check > temp->index)
				pos++;
			else
				break ;
			temp = temp->next;
			a = a->next;
		}
	}
	return (pos);
}

int	check_op_b_to_a(t_stack *a, t_stack *b)
{
	int		opto_a;
	t_stack	*temp;

	temp = b;
	opto_a = rate_rrr_btoa(a, b, b->index);
	while (temp)
	{
		if (opto_a > rate_rr_btoa(a, b, temp->index))
			opto_a = rate_rr_btoa(a, b, temp->index);
		if (opto_a > rate_rrr_btoa(a, b, temp->index))
			opto_a = rate_rrr_btoa(a, b, temp->index);
		if (opto_a > rate_ra_rrb_btoa(a, b, temp->index))
			opto_a = rate_ra_rrb_btoa(a, b, temp->index);
		if (opto_a > rate_rb_rra_btoa(a, b, temp->index))
			opto_a = rate_rb_rra_btoa(a, b, temp->index);
		temp = temp->next;
	}
	return (opto_a);
}
