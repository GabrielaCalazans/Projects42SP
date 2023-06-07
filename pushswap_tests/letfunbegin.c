/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letfunbegin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:36:31 by gacalaza          #+#    #+#             */
/*   Updated: 2023/06/07 01:37:22 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	sorting_it(t_stack **a, t_stack **b, int len)
{
	if (len == 2)
		sort_three(a);
	if (len >= 3 && len <= 4)
		sort_three(a);
	if (len == 5)
		sort_five(a, b, len);
	if (len > 5)
		sort_big(a, b, len);
}

void	sort_three(t_stack **a)
{
	if (checksorted(a))
		return ;
	if (ft_min(*a) == (*a)->nbr)
	{
		ft_swap_ab(a, 97);
		ft_rotate_ab(a, 97);
	}
	else if (ft_max(*a) == (*a)->nbr)
	{
		ft_rotate_ab(a, 97);
		if (!checksorted(a))
			ft_swap_ab(a, 97);
	}
	else
	{
		ft_swap_ab(a, 97);
		sort_three(a);
	}
}

void	push_all_b_to_a(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_size(*b);
	while (len > 0)
	{
		ft_push_a(a, b, 97);
		len--;
	}
}

void	sort_five(t_stack **a, t_stack **b, int size)
{
	int	pos;

	if (checksorted(a) && size == ft_size(*a))
		return ;
	pos = ft_min_pos(*a, ft_min(*a));
	if (pos == size)
		ft_rev_rotate_ab(a, 97);
	else if (ft_min(*a) == (*a)->nbr)
		ft_push_b(a, b, 98);
	else if ((*a)->nbr > (*a)->next->nbr && pos > size / 2)
		ft_swap_ab(a, 97);
	else if (pos < size / 2)
		ft_rotate_ab(a, 97);
	else
		ft_rev_rotate_ab(a, 97);
	if (checksorted(a))
	{
		push_all_b_to_a(a, b);
		return ;
	}
	else
		sort_five(a, b, size);
}

void	sort_big(t_stack **a, t_stack **b, int size)
{
	int	pos;

	if (checksorted(a) && size == ft_size(*a))
		return ;
	pos = ft_min_pos(*a, ft_min(*a));
	if (pos == size)
		ft_rev_rotate_ab(a, 97);
	else if (ft_min(*a) == (*a)->nbr)
		ft_push_b(a, b, 98);
	else if ((*a)->nbr > (*a)->next->nbr && pos > size / 2)
		ft_swap_ab(a, 97);
	else if (pos < size / 2)
		ft_rotate_ab(a, 97);
	else
		ft_rev_rotate_ab(a, 97);
	if (checksorted(a))
	{
		push_all_b_to_a(a, b);
		return ;
	}
	else
		sort_big(a, b, size);
}

// void	quick_sort(t_stack **a, t_stack **b, int size)
// {
// 	int	pivot = (*a)->nbr;
// 	int	count = 0;
// 	while (count < size)
// 	{
// 		if ((*a)->nbr < pivot)
// 		{
// 			ft_rotate_ab(a, 97);
// 		}
// 		else
// 			ft_push_b(a, b, 98);
// 		if (checksorted(a))
// 		{
// 			push_all_b_to_a(a, b);
// 			return ;
// 		}
// 		count++;
// 	}
// 	quick_sort(a, b, count - 1);
// 	quick_sort(b, a, size - count);
// 	if (checksorted(a))
// 	{
// 		push_all_b_to_a(a, b);
// 		return ;
// 	}
// }
