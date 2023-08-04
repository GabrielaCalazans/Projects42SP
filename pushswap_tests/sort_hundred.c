/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:22:06 by gacalaza          #+#    #+#             */
/*   Updated: 2023/08/04 14:25:10 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	sort_hundred_a_to_b(t_stack **a, t_stack **b)
{
	if (!check_its_sorted_a(a) && ft_size(*a) > 3)
		ft_push_b(a, b, 98);
	if (!check_its_sorted_a(a) && ft_size(*a) > 3)
		ft_push_b(a, b, 98);
	// if (!check_its_sorted_a(a) && ft_size(*a) > 3)
	// 	ft_push_b(a, b, 98);
	if (!check_its_sorted_a(a) && ft_size(*a) > 3)
		check_and_push_to_b(a, b);
	if (!check_its_sorted_a(a) && ft_size(*a) == 3)
		sort_three(a, 97);
}

void	check_and_push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		i;

	while (ft_size(*a) > 3 && !check_its_sorted_a(a))
	{
		temp = *a;
		i = check_op_a_to_b(*a, *b);
		while (i >= 0)
		{
			if (i == rate_rr_atob(*a, *b, temp->index))
				i = do_rr(a, b, temp->index, 97);
			else if (i == rate_rrr_atob(*a, *b, temp->index))
				i = do_rrr(a, b, temp->index, 97);
			else if (i == rate_ra_rrb_atob(*a, *b, temp->index))
				i = do_ra_rrb(a, b, temp->index, 97);
			else if (i == rate_rb_rra_atob(*a, *b, temp->index))
				i = do_rb_rra(a, b, temp->index, 97);
			else
				temp = temp->next;
		}
	}
}

void	check_and_push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		i;

	temp = *b;
	while (temp && ft_size(*b) > 0)
	{
		temp = *b;
		i = check_op_b_to_a(*a, *b);
		while (i >= 0)
		{
			if (i == rate_rr_btoa(*a, *b, temp->index))
				i = do_rr(a, b, temp->index, 98);
			else if (i == rate_rrr_btoa(*a, *b, temp->index))
				i = do_rrr(a, b, temp->index, 98);
			else if (i == rate_ra_rrb_btoa(*a, *b, temp->index))
				i = do_ra_rrb(a, b, temp->index, 98);
			else if (i == rate_rb_rra_btoa(*a, *b, temp->index))
				i = do_rb_rra(a, b, temp->index, 98);
			else
				temp = temp->next;
		}
	}
}

void	sort_final(t_stack **a, int len)
{
	int	pos_min;
	int	size;
	int	pos_final;

	size = len / 2;
	pos_min = ft_int_pos(*a, ft_min(*a));
	pos_final = len - pos_min;
	// printf("size:%d	pos_min:%d	pos_final%d\n", size, pos_min, pos_final);
	if (pos_min < size)
	{
		// printf("HEre post_min\n");
		while (pos_min-- > 0)
			ft_rotate_ab(a, 97);
	}
	else if (pos_min >= size)
	{
		// printf("HEre post_min\n");
		while (pos_final-- > 0)
			ft_rev_rotate_ab(a, 97);
	}
}
