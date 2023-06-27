/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:05:30 by gacalaza          #+#    #+#             */
/*   Updated: 2023/06/26 17:05:33 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	do_rot_a(t_stack **a, int rot_nbr, int size_a)
{
	int	i;

	if (rot_nbr && rot_nbr <= size_a / 2)
	{
		while (rot_nbr-- > 1)
			ft_rotate_ab(a, 97);
		if((*a)->index > (*a)->next->index)
			ft_swap_ab(a, 97);
		rot_nbr = check_its_sorted_a_idx(a);
		if (rot_nbr > size_a / 2)
			return ;
	}
	if (rot_nbr && rot_nbr > size_a / 2)
	{
		i = (size_a + 1) - rot_nbr;
		while(i-- > 0)
			ft_rev_rotate_ab(a, 97);
		if((*a)->index > (*a)->next->index)
			ft_swap_ab(a, 97);
		rot_nbr = check_its_sorted_a_idx(a);
		if (rot_nbr <= size_a / 2)
			return ;
	}
}

void	do_rot_b(t_stack **b, int rot_nbr, int size_b)
{
	int	i;

	if (rot_nbr && rot_nbr <= size_b / 2)
	{
		while (rot_nbr-- > 1)
			ft_rotate_ab(b, 98);
		if((*b)->index > (*b)->next->index)
			ft_swap_ab(b, 98);
		rot_nbr = check_its_sorted_b_idx(b);
		if (rot_nbr > size_b / 2)
			return ;
	}
	if (rot_nbr && rot_nbr > size_b / 2)
	{
		i = (size_b + 1) - rot_nbr;
		while(i-- > 0)
			ft_rev_rotate_ab(b, 98);
		if((*b)->index > (*b)->next->index)
			ft_swap_ab(b, 98);
		rot_nbr = check_its_sorted_a_idx(b);
		if (rot_nbr <= size_b / 2)
			return ;
	}
}

void	do_rot_ab(t_stack **a, t_stack **b, int rot_nbr, int size_a, int size_b)
{
	int	i;

	if (rot_nbr && rot_nbr <= size_b / 2 && rot_nbr <= size_a / 2)
	{
		while (rot_nbr-- > 1)
			ft_rotate_rr(a, b, 195);
		if((*a)->index > (*a)->next->index && (*b)->index < (*b)->next->index)
			ft_swap_ss(a, b, 195);
		if((*a)->index > (*a)->next->index)
			ft_swap_ab(a, 97);
		if((*b)->index < (*b)->next->index)
			ft_swap_ab(b, 98);
		rot_nbr = check_its_sorted_b_idx(b);
		if (rot_nbr > size_b / 2)
			return ;
	}
	if (rot_nbr && rot_nbr > size_b / 2)
	{
		i = (size_b + 1) - rot_nbr;
		while(i-- > 0)
			ft_rev_rotate_r(a, b, 195);
		if((*b)->index > (*b)->next->index)
			ft_swap_ab(b, 98);
		rot_nbr = check_its_sorted_a_idx(b);
		if (rot_nbr <= size_b / 2)
			return ;
	}
}
