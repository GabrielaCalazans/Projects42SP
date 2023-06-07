/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letfunbegin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:36:31 by gacalaza          #+#    #+#             */
/*   Updated: 2023/06/07 18:24:52 by gacalaza         ###   ########.fr       */
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

void	push_half_to_b(t_stack **a, t_stack **b, int size, int check)
{
	while(size > 0)
	{
		ft_push_b(a, b, 98);
		size--;
	}
}

void	sort_big_a(t_stack **a, t_stack **b, int size, int check)
{
	int	pos_a;
	int	pos_b;

	if (checksorted(a) && size == ft_size(*a))
		return ;
	push_half_to_b(a, b, size/2, check);
	pos_a = ft_min_pos(*a, ft_min(*a));
	pos_b = ft_min_pos(*b, ft_min(*b));
	if (pos_a == size/2 && pos_b == size/2)
		ft_rev_rotate_rr(a, b, 195);
	if (pos_a == size/2 && !(pos_b == size/2))
		ft_rev_rotate_ab(a, 97);
	if (pos_b == size/2 && !(pos_a == size/2))
		ft_rev_rotate_ab(b, 98);
	else if ((*a)->nbr > (*a)->next->nbr && pos_a > size / 2)
		ft_swap_ab(a, 97);
	else if (pos_a < size / 4)
		ft_rotate_ab(a, 97);
	else
		ft_rev_rotate_ab(a, 97);
	if (checksorted(a))
	{
		push_all_b_to_a(a, b);
		return ;
	}
	else
		sort_big_a(a, b, size);
}

void	sort_big_b(t_stack **a, t_stack **b, int size)
{
	int	pos;

	if (check_its_sorted_b(b) && size == ft_size(*b))
		return ;
	pos = ft_min_pos(*b, ft_min(*b));
	if (pos == size/2)
		ft_rev_rotate_ab(b, 98);
	else if ((*b)->nbr > (*b)->next->nbr && pos > size / 2)
		ft_swap_ab(b, 98);
	else if (pos < size / 4)
		ft_rotate_ab(b, 98);
	else
		ft_rev_rotate_ab(b, 98);
	if (check_its_sorted_b(b))
	{
		push_all_b_to_a(a, b);
		return ;
	}
	else
		sort_big_b(a, b, size);
}

void	quick_sort(t_stack **a, t_stack **b, int size)
{
	int	pivot = (*a)->nbr;
	int	count = 0;
	while (count < size)
	{
		if ((*a)->nbr < pivot)
		{
			ft_rotate_ab(a, 97);
		}
		else
			ft_push_b(a, b, 98);
		if (checksorted(a))
		{
			push_all_b_to_a(a, b);
			return ;
		}
		count++;
	}
	quick_sort(a, b, count - 1);
	quick_sort(b, a, size - count);
	if (checksorted(a))
	{
		push_all_b_to_a(a, b);
		return ;
	}
}

// static t_stack	*partition(t_stack **a, t_stack **b, t_stack *end)
// {
// 	int			pivot;
// 	t_stack		*i;
// 	t_stack		*j;
// 	t_stack		*next;
	
// 	pivot = end->index;
// 	i = (*a)->prev;
// 	j = (*a);
// 	while (j != NULL)
// 	{
// 		next = j->next;
// 		if (j->index != pivot)
// 		{
// 			if (j->index < pivot)
// 				ft_push_a(&smaller, current);
// 			else
// 				ft_push(&greater, current);
// 		}
// 		j = next;
// 	}
// 	// Recursively sort the smaller and greater partitions
// 	smaller = quick_sort(smaller);
// 	greater = quick_sort(greater);
// 	// Concatenate the smaller partition, pivot node, and greater partition
// 	head = concatenate(smaller, pivot_node, greater);
// 	return (head);
// }

// t_stack	*quick_sort(t_stack *head)
// {
// 	t_stack	*end;
// 	int		end_idx;

// 	// Base case: If the list is empty or has only one node, return it
// 	if (head == NULL || head->next == NULL)
// 		return (head);
// 	// Choose the rightmost node as the pivot
// 	end = ft_last(head);
// 	end_idx = end->index;
// 	// Call the partition function to partition the list
// 	head = partition(head, 0, end_idx);
// 	return (head);
// }
