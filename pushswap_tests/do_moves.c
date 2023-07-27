/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:05:30 by gacalaza          #+#    #+#             */
/*   Updated: 2023/07/26 20:46:22 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// void	do_rot_a(t_stack **a, int rot_nbr, int check_rot)
// {
// 	int	i;
// 	int	size_a;

// 	size_a = ft_size(*a);
// 	if (check_rot == 2)
// 	{
// 		while (rot_nbr-- > 1)
// 			ft_rotate_ab(a, 97);
// 		if((*a)->index > (*a)->next->index)
// 			ft_swap_ab(a, 97);
// 	}
// 	if (check_rot == 1)
// 	{
// 		i = (size_a + 1) - rot_nbr;
// 		while(i-- > 0)
// 			ft_rev_rotate_ab(a, 97);
// 		if((*a)->index > (*a)->next->index)
// 			ft_swap_ab(a, 97);
// 	}
// }

// void	do_rot_b(t_stack **b, int rot_nbr, int check_rot)
// {
// 	int	i;
// 	int	size_b;

// 	size_b = ft_size(*b);
// 	if (check_rot == 2)
// 	{
// 		while (rot_nbr-- > 1)
// 			ft_rotate_ab(b, 98);
// 		if((*b)->index > (*b)->next->index)
// 			ft_swap_ab(b, 98);
// 	}
// 	if (check_rot == 1)
// 	{
// 		i = (size_b + 1) - rot_nbr;
// 		while(i-- > 0)
// 			ft_rev_rotate_ab(b, 98);
// 		if((*b)->index > (*b)->next->index)
// 			ft_swap_ab(b, 98);
// 	}
// }

// void	do_rot_ab(t_stack **a, t_stack **b, int rot_nbr, int check_rot)
// {
// 	int	i;
// 	int size_b;

// 	size_b = ft_size(*b);
// 	if (check_rot == 2)
// 	{
// 		while (rot_nbr-- > 1)
// 			ft_rotate_rr(a, b, 195);
// 		if((*a)->index > (*a)->next->index && (*b)->index < (*b)->next->index)
// 			ft_swap_ss(a, b, 195);
// 		else if((*a)->index > (*a)->next->index)
// 			ft_swap_ab(a, 97);
// 		else if((*b)->index < (*b)->next->index)
// 			ft_swap_ab(b, 98);
// 	}
// 	if (check_rot == 1)
// 	{
// 		i = (size_b + 1) - rot_nbr;
// 		while(i-- > 0)
// 			ft_rev_rotate_r(a, b, 195);
// 		if((*a)->index > (*a)->next->index && (*b)->index < (*b)->next->index)
// 			ft_swap_ss(a, b, 195);
// 		else if((*a)->index > (*a)->next->index)
// 			ft_swap_ab(a, 97);
// 		else if((*b)->index < (*b)->next->index)
// 			ft_swap_ab(b, 98);
// 	}
// }

int	do_single_rot_atob(t_stack **a, t_stack **b, int check, int stack)
{
	if (stack == 97)
	{
		while (check_pos_b(*b, check) > 0 && (*a)->index != check)
			ft_rotate_rr(a, b, 195);
		while (check_pos_b(*b, check) > 0)
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

int	do_double_revrot_atob(t_stack **a, t_stack **b, int check, int stack)
{	
	if (stack == 97)
	{
		while (check_pos_b(*b, check) > 0 && (*a)->index != check)
			ft_rev_rotate_r(a, b, 195);
		while (check_pos_b(*b, check) > 0)
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

int	do_rota_revrotb(t_stack **a, t_stack **b, int check, int stack)
{
	if (stack == 97)
	{
		while (check_pos_b(*b, check) > 0)
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

int	do_rotb_revrota(t_stack **a, t_stack **b, int check, int stack)
{
	if (stack == 97)
	{
		while (check_pos_b(*b, check) > 0)
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
