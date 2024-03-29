/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letthefunbegin_utilsNOT.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:52:26 by gacalaza          #+#    #+#             */
/*   Updated: 2023/08/02 15:16:16 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	push_size_of_b_to_a(t_stack **a, t_stack **b, int size)
{
	while (size > 0)
	{
		ft_push_a(a, b, 97);
		size--;
	}
}

void	push_half_to_b(t_stack **a, t_stack **b, int size)
{
	while(size > 0)
	{
		ft_push_b(a, b, 98);
		size--;
	}
}

void	ft_sort_a(t_stack **a, int size)
{
	int	check;
	int	i;
	
	if (check_its_sorted_a(a))
	{
		printf("here sorted.");
		return ;
	}
	if (size > 2 && size < 5)
	{
		sort_three(a, 97);
		return ;
	}
	check = check_its_sorted_a_idx(a);
	while (check && check <= size / 2)
	{
		// printf("check: %d size:%d\n", check, size);
		// printf("Sort_a: \n");
		// printlist(*a); 
		while (check-- > 1)
			ft_rotate_ab(a, 97);
		if((*a)->index > (*a)->next->index)
			ft_swap_ab(a, 97);
		check = check_its_sorted_a_idx(a);
		if (check > size / 2)
			break ;
	}
	while (check && check > size / 2)
	{
		i = (size + 1) - check;
		// printf("check: %d size:%d i:%d\n", check, size, i);
		// printf("Sort_a: \n");
		// printlist(*a);
		while(i-- > 0)
			ft_rev_rotate_ab(a, 97);
		if((*a)->index > (*a)->next->index)
			ft_swap_ab(a, 97);
		// printf("i:%d\n", i);
		check = check_its_sorted_a_idx(a);
		// printf("i:%d\n", i);
		if (check <= size / 2)
			break ;
	}
	ft_sort_a(a, size);
}

void	ft_sort_b(t_stack **b, int size)
{
	int	check;
	int	i;
	
	if (check_its_sorted_b(b))
		return ;
	// if (size > 2 && size < 5)
	// {
	// 	sort_three(a, 97);
	// 	return ;
	// }
	check = check_its_sorted_b_idx(b);
	if (check && check <= size / 2)
	{
		while (check-- > 0)
			ft_rotate_ab(b, 98);

		if((*b)->index < (*b)->next->index)
			ft_swap_ab(b, 98);
		// printf("check: %d size:%d \n", check, size);
	}
	else if (check && check > size / 2)
	{
		i = (size + 1) - check;
		while(i-- > 0)
			ft_rev_rotate_ab(b, 98);
		if((*b)->index < (*b)->next->index)
			ft_swap_ab(b, 98);
	}
	ft_sort_b(b, size);
}

void	ft_sort_all(t_stack **a, t_stack **b)
{
	int	check_a;
	int	check_b;

	check_a = check_its_sorted_a_idx(a);
	check_b = check_its_sorted_b_idx(b);
	if (check_its_sorted_a(a) && check_its_sorted_b(b))
		return ;
}

void	sort_three_b(t_stack **b, int check)
{
	if (check_its_sorted_b(b) && check == 98)
		return ;
	if (ft_max(*b) == (*b)->index)
	{
		ft_swap_ab(b, check);
		ft_rotate_ab(b, check);
	}
	else if (ft_min(*b) == (*b)->index)
	{
		ft_rotate_ab(b, check);
		if (!check_its_sorted_b(b) && check == 97)
			ft_swap_ab(b, check);
	}
	else
	{
		ft_swap_ab(b, check);
		sort_three(b, check);
	}
}


void	sort_five_push_count(t_stack **a, t_stack **b, int size_a)
{
	int	pos;
	int	count;

	count = 0;
	if (check_its_sorted_a(a) && size_a == ft_size(*a))
	{
		// printf("Pos func sort a1: \n");
		// printlist(*a);
		return ;
	}
	pos = ft_int_pos(*a, ft_min(*a));
	if (pos == size_a)
		ft_rev_rotate_ab(a, 97);
	else if (ft_min(*a) == (*a)->index)
	{
		count++;
		ft_push_b(a, b, 98);
	}
	else if ((*a)->index  > (*a)->next->index && pos > size_a / 2)
		ft_swap_ab(a, 97);
	else if (pos <= size_a / 2)
		ft_rotate_ab(a, 97);
	else
		ft_rev_rotate_ab(a, 97);
	if (check_its_sorted_a(a))
	{
		push_size_of_b_to_a(a, b, count);
		// printf("Pos func sort a2: \n");
		// printlist(*a);
		return ;
	}
	else
		sort_five_push_count(a, b, size_a);
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

// void	sort_hundre_first(t_stack **a, t_stack **b, int size_init)
// {
// 	int	top;
// 	int	bottom;
// 	int	pos_top;
// 	int	pos_bottom;
// 	int	size_a;

// 	size_a = ft_size(*a);
// 	top = ft_min_size(*a, size_a / 2, 't');
// 	bottom = ft_min_size(*a, size_a / 2, 'b');
// 	pos_top = ft_int_pos(*a, top);
// 	pos_bottom = (size_a + 2) - ft_int_pos(*a, bottom);
// 	// printf("size_a:%d, top:%d, bottom:%d, pos_top:%d, pos_bottom:%d\n", size_a, top, bottom, pos_top, pos_bottom);
// 	if (size_a < 2)
// 	{
// 		sort_hundred_second(a, b, size_init);
// 		return ;
// 	}
// 	if (pos_top > pos_bottom)
// 	{
// 		while (pos_bottom-- > 0)
// 			ft_rev_rotate_ab(a, 97);
// 		ft_push_b(a, b, 98);
// 		// if (ft_size(*b) > 5 && !check_its_sorted_b(b))
// 		// 	ft_sort_b(b, ft_size(*b));
// 		sort_hundre_first(a, b, size_init);
// 	}
// 	if (pos_top <= pos_bottom)
// 	{
// 		while (pos_top-- > 0)
// 			ft_rotate_ab(a, 97);
// 		// if (ft_size(*b) > 5 && !check_its_sorted_b(b))
// 		// 	ft_sort_b(b, ft_size(*b));
// 		ft_push_b(a, b, 98);
// 		sort_hundre_first(a, b, size_init);
// 	}
// }

// void	sort_hundred_second(t_stack **a, t_stack **b, int size_init)
// {
// 	int	max;
// 	int	pos_max;
// 	int	size_b;
// 	int	count;

// 	size_b = ft_size(*b);
// 	max = ft_max(*b);
// 	pos_max = ft_int_pos(*b, max);
// 	if (size_b < 2 && (ft_size(*a) + 1) == size_init)
// 	{
// 		ft_push_a(a, b, 97);
// 		if (!check_its_sorted_a(a))
// 			ft_sort_a(a, ft_size(*a));
// 			// printf("here am i 0.");
// 		return ;
// 	}
// 	if (ft_size(*a) == 3)
// 		sort_three(a, 97);
// 	if (ft_size(*a) == 5)
// 		sort_five_push_count(a, b, ft_size(*a));
// 	if (pos_max > size_b / 2 && ft_size(*a) != size_init)
// 	{
// 		count = (size_b - pos_max) + 1;
// 		while (count-- > 0)
// 			ft_rev_rotate_ab(b, 98);
// 		if (ft_size(*a) > 5 && !check_its_sorted_a(a))
// 			ft_sort_a(a, ft_size(*a));
// 			// printf("here am i 1.");
// 		else if (max == (*b)->index)
// 			ft_push_a(a, b, 97);
// 		sort_hundred_second(a, b, size_init);
// 	}
// 	if (pos_max <= size_b / 2 && ft_size(*a) != size_init)
// 	{
// 		while (pos_max-- > 0)
// 			ft_rotate_ab(b, 98);
// 		// printf("pos_max:%d size_b:%d size_init:%d, size_a:%d\n", pos_max, size_b, size_init, ft_size(*a));
// 		if (ft_size(*a) > 5 && !check_its_sorted_a(a))
// 			ft_sort_a(a, ft_size(*a));
// 			// printf("here am i 2.");
// 		else if (max == (*b)->index)
// 			ft_push_a(a, b, 97);
// 		sort_hundred_second(a, b, size_init);
// 	}
// }


// void	ft_sort_b(t_stack **b)
// {
// 	if (*b == NULL)
// 		return ;
// 	if (check_its_sorted_b(b))
// 		return ;
// 	if ((*b)->nbr < (*b)->next->nbr)
// 		ft_swap_ab(b, 98);
// 	else if ((*b)->nbr < ft_last(*b)->nbr)
// 		ft_rotate_ab(b, 98);
// 	else if ((*b)->nbr < (*b)->next->nbr)
// 		ft_swap_ab(b, 98);
// }

// void	ft_sort_hundred_second(t_stack **a, t_stack **b, int size_init)
// {
// 	int	top;
// 	int	bottom;
// 	int	pos_top;
// 	int	pos_bottom;
// 	int	size_b;

// 	size_b = ft_size(*b);
// 	top = ft_min_size(*b, size_b / 2, 't');
// 	bottom = ft_min_size(*b, size_b / 2, 'b');
// 	pos_top = ft_int_pos(*b, top);
// 	pos_bottom = (size_b + 2) - ft_int_pos(*b, bottom);
// 	if (size_b < 2 && ft_size(*a) != size_init)
// 	{
// 		// printf("Sorting List a: \n");
// 		// printlist(*a);
// 		ft_push_a(a, b, 97);
// 			if (!check_its_sorted_a(a))
// 				ft_sort_a(a, ft_size(*a));
// 		return ;
// 	}
// 	if (ft_size(*a) == 3)
// 		sort_three(a, 97);
// 	if (ft_size(*a) == 5)
// 		sort_five_push_count(a, b, ft_size(*a));
// 	if (pos_top > pos_bottom && ft_size(*a) != size_init)
// 	{
// 		while ((size_b + 1) - pos_bottom-- > 0)
// 			ft_rev_rotate_ab(b, 98);
// 		if (ft_size(*a) > 5)
// 			ft_sort_a(a, ft_size(*a));
// 		ft_push_a(a, b, 97);
// 		ft_sort_hundred_second(a, b, size_init);
// 	}
// 	if (pos_top <= pos_bottom && ft_size(*a) != size_init)
// 	{
// 		while (pos_top-- > 0)
// 			ft_rotate_ab(a, 97);
// 		if (ft_size(*a) > 5)
// 			ft_sort_a(a, ft_size(*a));
// 		ft_push_a(a, b, 97);
// 		ft_sort_hundred_second(a, b, size_init);
// 	}
// }

// void	ft_sort_hundred(t_stack **a, t_stack **b, int size)
// {
// 	int			key;
// 	int			size_a;
// 	static int	count = 0;

// 	size_a = ft_size(*a);
// 	if (check_its_sorted_a(a) && size == size_a)
// 		return ;
// 	if (count == 1)
// 		key = size / 2;
// 	else if (count == 2)
// 		key = size - (size / 4);
// 	else
// 		key = size / 4;
// 	while (size_a > 0)
// 	{
// 		if ((*a)->index < key)
// 			ft_push_b(a, b, 98);
// 		if ((*a)->next->index < key)
// 		{
// 			ft_swap_ab(a, 97);
// 			ft_sort_b(b);
// 			ft_push_b(a, b, 98);
// 		}
// 		if (ft_last(*a)->index < key)
// 		{
// 			ft_rev_rotate_ab(a, 97);
// 			ft_sort_b(b);
// 			ft_push_b(a, b, 98);
// 		}
// 		else
// 			ft_rotate_ab(a, 97);
// 		size_a--;
// 		if (size_a == 0)
// 			count++;
// 	}
// 	if (ft_size(*b) == size - (size / 4))
// 		ft_checkandpush(a, b);
// 	ft_sort_a(a, ft_size(*a));
// 	if (!check_its_sorted_a(a) && size != size_a && count < 3)
// 		ft_sort_hundred(a, b, size);
// }

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
// 		if (check_its_sorted_a(a))
// 		{
// 			push_all_b_to_a(a, b);
// 			return ;
// 		}
// 		count++;
// 	}
// 	quick_sort(a, b, count - 1);
// 	quick_sort(b, a, size - count);
// 	if (check_its_sorted_a(a))
// 	{
// 		push_all_b_to_a(a, b);
// 		return ;
// 	}
// }

// void	ft_sort_hundred(t_stack **a, t_stack **b, int size)
// {
// 	int	first;
// 	int	second;
// 	int	pos_first;
// 	int	pos_second;
// 	int	size_a;

// 	size_a = ft_size(*a);
// 	first = ft_min_size(*a, size_a / 2, 't');
// 	second = ft_min_size(*a, size_a / 2, 'b');
// 	pos_first = ft_int_pos(*a, first);
// 	pos_second = ft_int_pos(*a, second);
// 	if (check_its_sorted_a(a) && size == size_a)
// 		return ;
// 	if (size_a < 2)
// 	{
// 		ft_checkandpush(a, b);
// 		// ft_sort_hundred(a, b, size);
// 		return ;
// 	}
// 	if (pos_first > (size_a + 1) - pos_second)
// 	{
// 		while ((size_a + 1) - pos_second-- > 0)
// 			ft_rev_rotate_ab(a, 97);
// 		ft_push_b(a, b, 98);
// 		ft_sort_b(b, ft_size(*b));
// 		ft_sort_hundred(a, b, size);
// 	}
// 	if (pos_first < (size_a + 1) - pos_second)
// 	{
// 		while (pos_first-- > 0)
// 			ft_rotate_ab(a, 97);
// 		ft_push_b(a, b, 98);
// 		ft_sort_b(b, ft_size(*b));
// 		ft_sort_hundred(a, b, size);
// 	}
// }

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
