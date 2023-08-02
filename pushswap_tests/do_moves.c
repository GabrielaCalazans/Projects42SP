/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:05:30 by gacalaza          #+#    #+#             */
/*   Updated: 2023/08/02 15:24:27 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	do_rr(t_stack **a, t_stack **b, int check, int stack)
{
	if (stack == 97)
	{
		while (track_pos_b(*b, check) > 0 && (*a)->index != check)
			ft_rotate_rr(a, b, 195);
		while (track_pos_b(*b, check) > 0)
			ft_rotate_ab(b, 98);
		while (ft_int_pos(*a, check) > 0)
			ft_rotate_ab(a, 97);
		ft_push_b(a, b, 98);
	}
	if (stack == 98)
	{
		while (track_pos_a(*a, check) > 0 && (*b)->index != check)
			ft_rotate_rr(a, b, 195);
		while (track_pos_a(*a, check) > 0)
			ft_rotate_ab(a, 97);
		while (ft_int_pos(*b, check) > 0)
			ft_rotate_ab(b, 98);
		ft_push_a(a, b, 97);
	}
	return (-1);
}

int	do_rrr(t_stack **a, t_stack **b, int check, int stack)
{	
	if (stack == 97)
	{
		while (track_pos_b(*b, check) > 0 && (*a)->index != check)
			ft_rev_rotate_r(a, b, 195);
		while (track_pos_b(*b, check) > 0)
			ft_rev_rotate_ab(b, 98);
		while (ft_int_pos(*a, check) > 0)
			ft_rev_rotate_ab(a, 97);
		ft_push_b(a, b, 98);
	}
	if (stack == 98)
	{
		while (track_pos_a(*a, check) > 0 && (*b)->index != check)
			ft_rev_rotate_r(a, b, 195);
		while (track_pos_a(*a, check) > 0)
			ft_rev_rotate_ab(a, 97);
		while (ft_int_pos(*b, check) > 0)
			ft_rev_rotate_ab(b, 98);
		ft_push_a(a, b, 97);
	}
	return (-1);
}

int	do_ra_rrb(t_stack **a, t_stack **b, int check, int stack)
{
	if (stack == 97)
	{
		while (track_pos_b(*b, check) > 0)
			ft_rev_rotate_ab(b, 98);
		while (ft_int_pos(*a, check) > 0)
			ft_rotate_ab(a, 97);
		ft_push_b(a, b, 98);
	}
	if (stack == 98)
	{
		while (track_pos_a(*a, check) > 0)
			ft_rotate_ab(a, 97);
		while (ft_int_pos(*b, check) > 0)
			ft_rev_rotate_ab(b, 98);
		ft_push_a(a, b, 97);
	}
	return (-1);
}

int	do_rb_rra(t_stack **a, t_stack **b, int check, int stack)
{
	if (stack == 97)
	{
		while (track_pos_b(*b, check) > 0)
			ft_rotate_ab(b, 98);
		while (ft_int_pos(*a, check) > 0)
			ft_rev_rotate_ab(a, 97);
		ft_push_b(a, b, 98);
	}
	if (stack == 98)
	{
		while (track_pos_a(*a, check) > 0)
			ft_rev_rotate_ab(a, 97);
		while (ft_int_pos(*b, check) > 0)
			ft_rotate_ab(b, 98);
		ft_push_a(a, b, 97);
	}
	return (-1);
}
