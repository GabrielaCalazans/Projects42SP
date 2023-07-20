/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letthefunbegin_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:52:26 by gacalaza          #+#    #+#             */
/*   Updated: 2023/07/19 17:44:37 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

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
