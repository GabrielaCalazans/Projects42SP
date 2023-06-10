/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letfunbegin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:36:31 by gacalaza          #+#    #+#             */
/*   Updated: 2023/06/10 20:22:38 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	sorting_it(t_stack **a, t_stack **b, int len)
{
	if (len == 2)
		sort_three(a, 97);
	if (len >= 3 && len <= 4)
		sort_three(a, 97);
	if (len == 5)
		sort_five(a, b, len);
	if (len > 5)
		ft_sort_hundred(a, b, len);
}

void	sort_three(t_stack **head, int check)
{
	if (check_its_sorted_a(head) && check == 97)
		return ;
	if (ft_min(*head) == (*head)->nbr)
	{
		ft_swap_ab(head, check);
		ft_rotate_ab(head, check);
	}
	else if (ft_max(*head) == (*head)->nbr)
	{
		ft_rotate_ab(head, check);
		if (!check_its_sorted_a(head) && check == 97)
			ft_swap_ab(head, check);
	}
	else
	{
		ft_swap_ab(head, check);
		sort_three(head, check);
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
	else if (ft_min(*a) == (*a)->nbr)
		ft_push_b(a, b, 98);
	else if ((*a)->nbr > (*a)->next->nbr && pos > size / 2)
		ft_swap_ab(a, 97);
	else if (pos < size / 2)
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

void	sort_five2(t_stack **a, t_stack **b, int size)
{
	if (check_its_sorted_a(a) && size == ft_size(*a))
		return ;
	ft_push_b(a, b, 98);
	ft_push_b(a, b, 98);
	if (!check_its_sorted_b(b))
		ft_swap_ab(b, 98);
	sort_three(a, 97);
	ft_push_a(a, b, 97);
	if (!check_its_sorted_a(a))
	{
		if ((*a)->index == 4)
			ft_rotate_ab(a, 97);
		if ((*a)->index == 3 && !(ft_last(*a)->index == 4))
			ft_rotate_ab(a, 97);
		if ((*a)->index == 3 && ft_last(*a)->index == 4)
		{
			ft_rev_rotate_ab(a, 97);
			ft_swap_ab(a, 97);
			ft_rotate_ab(a, 97);
			ft_rotate_ab(a, 97);
		}
		if ((*a)->index > (*a)->next->index)
			ft_swap_ab(a, 97);
	}
	ft_push_a(a, b, 97);
	if (!check_its_sorted_a(a))
	{
		if ((*a)->index == 4)
			ft_rotate_ab(a, 97);
		if ((*a)->index == 3 && ft_last(*a)->index == 4)
		{
			ft_rev_rotate_ab(a, 97);
			ft_swap_ab(a, 97);
			ft_rotate_ab(a, 97);
			ft_rotate_ab(a, 97);
		}
		if ((*a)->index == 2)
		{
			ft_swap_ab(a, 97);
			ft_rotate_ab(a, 97);
			ft_swap_ab(a, 97);
			ft_rev_rotate_ab(a, 97);
		}
		if ((*a)->index > (*a)->next->index)
			ft_swap_ab(a, 97);
	}
}

void	ft_checkandpush(t_stack **a, t_stack **b)
{
	int	size_b;
	int	size_a;

	size_a = ft_size(*a);
	size_b = ft_size(*b);
	while (size_b > 0)
	{
		ft_push_a(a, b, 97);
		if (size_a == 3)
			sort_three(a, 97);
		if (size_b > 1)
			ft_sort_b(b, size_b);
		ft_sort_a(a, size_a);
		size_b = ft_size(*b);
		size_a = ft_size(*a);
	}
}

void	ft_sort_a(t_stack **a, int size)
{
	int			pos;
	
	if (check_its_sorted_a(a))
		return ;
	pos = ft_int_pos(*a, ft_min(*a));
	if (pos == size)
		ft_rev_rotate_ab(a, 97);
	else if ((*a)->nbr > (*a)->next->nbr)
		ft_swap_ab(a, 97);
	else if (pos < size / 2)
		ft_rotate_ab(a, 97);
	else
	{
		if (!check_its_sorted_a(a))
			ft_rev_rotate_ab(a, 97);
	}
}


void	ft_sort_b(t_stack **b, int size)
{
	int			pos;
	
	if (check_its_sorted_b(b))
		return ;
	pos = ft_int_pos(*b, ft_max(*b));
	if (pos == size)
		ft_rev_rotate_ab(b, 98);
	else if ((*b)->nbr < (*b)->next->nbr)
		ft_swap_ab(b, 98);
	else if (pos < size / 2)
		ft_rotate_ab(b, 98);
	else
	{
		if (!check_its_sorted_b(b))
			ft_rev_rotate_ab(b, 98);
	}
}

void	ft_sort_hundred(t_stack **a, t_stack **b, int size)
{
	int	first;
	int	second;
	int	pos_first;
	int	pos_second;
	int	size_a;

	size_a = ft_size(*a);
	first = ft_min_size(*a, size_a / 2, 't');
	second = ft_min_size(*a, size_a / 2, 'b');
	pos_first = ft_int_pos(*a, first);
	pos_second = ft_int_pos(*a, second);
	if (check_its_sorted_a(a) && size == size_a)
		return ;
	if (size_a < 2)
	{
		ft_checkandpush(a, b);
		// ft_sort_hundred(a, b, size);
		return ;
	}
	if (pos_first > (size_a + 1) - pos_second)
	{
		while ((size_a + 1) - pos_second-- > 0)
			ft_rev_rotate_ab(a, 97);
		ft_push_b(a, b, 98);
		ft_sort_b(b, ft_size(*b));
		ft_sort_hundred(a, b, size);
	}
	if (pos_first < (size_a + 1) - pos_second)
	{
		while (pos_first-- > 0)
			ft_rotate_ab(a, 97);
		ft_push_b(a, b, 98);
		ft_sort_b(b, ft_size(*b));
		ft_sort_hundred(a, b, size);
	}
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
		if (check_its_sorted_a(a))
		{
			push_all_b_to_a(a, b);
			return ;
		}
		count++;
	}
	quick_sort(a, b, count - 1);
	quick_sort(b, a, size - count);
	if (check_its_sorted_a(a))
	{
		push_all_b_to_a(a, b);
		return ;
	}
}


// void	sort_big_a(t_stack **a, t_stack **b, int size)
// {
// 	int	pos_a;
// 	int	pos_b;

// 	if (check_its_sorted_a(a) && size == ft_size(*a))
// 		return ;
// 	push_half_to_b(a, b, size/2);
// 	pos_a = ft_int_pos(*a, ft_min(*a));
// 	pos_b = ft_int_pos(*b, ft_min(*b));
// 	if (pos_a == size/2 && pos_b == size/2)
// 		ft_rev_rotate_r(a, b, 195);
// 	if (pos_a == size/2 && !(pos_b == size/2))
// 		ft_rev_rotate_ab(a, 97);
// 	if (pos_b == size/2 && !(pos_a == size/2))
// 		ft_rev_rotate_ab(b, 98);
// 	else if ((*a)->nbr > (*a)->next->nbr && pos_a > size / 2)
// 		ft_swap_ab(a, 97);
// 	else if (pos_a < size / 4)
// 		ft_rotate_ab(a, 97);
// 	else
// 		ft_rev_rotate_ab(a, 97);
// 	if (check_its_sorted_a(a)) 
// 	{
// 		push_all_b_to_a(a, b);
// 		return ;
// 	}
// 	else
// 		sort_big_a(a, b, size);
// }

// void	sort_big_b(t_stack **a, t_stack **b, int size)
// {
// 	int	pos;

// 	if (check_its_sorted_b(b) && size == ft_size(*b))
// 		return ;
// 	pos = ft_int_pos(*b, ft_min(*b));
// 	if (pos == size/2)
// 		ft_rev_rotate_ab(b, 98);
// 	else if ((*b)->nbr > (*b)->next->nbr && pos > size / 2)
// 		ft_swap_ab(b, 98);
// 	else if (pos < size / 4)
// 		ft_rotate_ab(b, 98);
// 	else
// 		ft_rev_rotate_ab(b, 98);
// 	if (check_its_sorted_b(b))
// 	{
// 		push_all_b_to_a(a, b);
// 		return ;
// 	}
// 	else
// 		sort_big_b(a, b, size);
// }


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