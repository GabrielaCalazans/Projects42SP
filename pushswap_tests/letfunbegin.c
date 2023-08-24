/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letfunbegin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:36:31 by gacalaza          #+#    #+#             */
/*   Updated: 2023/08/05 13:10:38 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	sorting_it(t_stack **a, t_stack **b, int len)
{
	if (len >= 2 && len <= 3)
		sort_three(a, 97);
	if (len > 3 && len < 9)
		sort_five(a, b, len);
	if (len > 8)
		sort_hundred(a, b, len);
}

void	sort_three(t_stack **a, int check)
{
	if (check_its_sorted_a(a) && check == 97)
		return ;
	if (ft_min(*a) == (*a)->index)
	{
		ft_swap_ab(a, check);
		ft_rotate_ab(a, check);
	}
	else if (ft_max(*a) == (*a)->index)
	{
		ft_rotate_ab(a, check);
		if (!check_its_sorted_a(a) && check == 97)
			ft_swap_ab(a, check);
	}
	else if (ft_min(*a) == ft_last(*a)->index)
	{
		ft_rev_rotate_ab(a, check);
	}
	else
	{
		ft_swap_ab(a, check);
		sort_three(a, check);
	}
}

void	sort_five(t_stack **a, t_stack **b, int size)
{
	int	pos;

	if (check_its_sorted_a(a) && size == ft_size(*a))
		return ;
	pos = ft_int_pos(*a, ft_min(*a));
	if (pos == size)
		ft_rev_rotate_ab(a, 97);
	else if (ft_min(*a) == (*a)->index)
		ft_push_b(a, b, 98);
	else if ((*a)->index > (*a)->next->index && pos > size / 2)
		ft_swap_ab(a, 97);
	else if (pos <= size / 2)
		ft_rotate_ab(a, 97);
	else
		ft_rev_rotate_ab(a, 97);
	if (check_its_sorted_a(a))
	{
		push_all_b_to_a(a, b);
		return ;
	}
	else
		sort_five(a, b, size);
}

void	sort_hundred(t_stack **a, t_stack **b, int len)
{
	if (!check_its_sorted_a(a) && ft_size(*a) > 3)
		sort_hundred_a_to_b(a, b);
	if (!check_its_sorted_a(a) && ft_size(*a) == 3)
		sort_three(a, 97);
	if (ft_size(*b) > 3)
		check_and_push_to_a(a, b);
	if (!check_its_sorted_a(a) && ft_size(*b) < 1)
	{
		// printf("GETING HERE");
		sort_final(a, len);
	}
}
