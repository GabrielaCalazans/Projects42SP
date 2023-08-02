/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacksNOT.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:26:25 by gacalaza          #+#    #+#             */
/*   Updated: 2023/08/02 15:12:17 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Func checks if the stack a is sorted.
int	check_its_sorted_a_len(t_stack **a)
{
	int		i;
	int		len;
	t_stack	*temp;

	temp = *a;
	i = temp->index;
	temp = temp->next;
	len = 0;
	while (temp)
	{
		len++;
		if (i > temp->index)
			return (len);
		i = temp->index;
		temp = temp->next;
	}
	return (0);
}

// Func checks if the stack a is sorted.
int	check_its_sorted_a_idx(t_stack **a)
{
	int		i;
	int		len;
	t_stack	*temp;

	temp = *a;
	i = temp->index;
	temp = temp->next;
	len = 0;
	while (temp)
	{
		len++;
		if (len > 2 && (i + 1) != temp->index)
			return (len);
		if ((len > 0 && len < 3) && i > temp->index)
			return (len);
		i = temp->index;
		temp = temp->next;
	}
	return (0);
}

// Func checks if the stack a is sorted.
int	check_its_sorted_b_idx(t_stack **b)
{
	int		i;
	int		len;
	t_stack	*temp;

	temp = *b;
	i = temp->index;
	temp = temp->next;
	len = 0;
	while (temp)
	{
		len++;
		if (len > 2 && (i - 1) != temp->index)
			return (len);
		if ((len > 0 && len < 3) && i < temp->index)
			return (len);
		i = temp->index;
		temp = temp->next;
	}
	return (0);
}

// Func checks if the stack a is sorted.
int	check_its_sorted_a_len2(t_stack **a)
{
	int		i;
	int		len;
	t_stack	*temp;

	temp = *a;
	i = temp->nbr;
	len = 0;
	while (temp)
	{
		len++;
		if (len == 1 && i > temp->nbr)
			return (len);
		if (len > 1 && (i > temp->nbr || i < temp->prev->nbr))
			return (len);
		i = temp->nbr;
		temp = temp->next;
	}
	return (0);
}

// Func checks if the stack is sorted.
int	check_its_sorted_b_len(t_stack **b)
{
	int		i;
	int		len;
	t_stack	*temp;

	temp = *b;
	i = temp->nbr;
	len = 1;
	while (temp)
	{
		if (i < temp->nbr)
			return (len);
		i = temp->nbr;
		temp = temp->next;
		len++;
	}
	return (0);
}

// Func checks if the stack is sorted.
int	check_its_sorted_b(t_stack **b)
{
	int		i;
	t_stack	*temp;

	temp = *b;
	i = temp->index;
	while (temp)
	{
		if (i < temp->index)
			return (0);
		i = temp->index;
		temp = temp->next;
	}
	return (1);
}

void	ft_checkandpush(t_stack **a, t_stack **b)
{
	int	size_b;
	int	size_a;

	size_a = ft_size(*a);
	size_b = ft_size(*b);
	while (size_b > 0)
	{
		ft_sort_a(a, size_a);
		ft_push_a(a, b, 97);
		if (size_b > 1)
			ft_sort_b(b, ft_size(*b));
		size_b = ft_size(*b);
		size_a = ft_size(*a);
	}
}

// int	check_pos_a(t_stack *a, int check)
// {
// 	t_stack	*temp;
// 	int		pos;
    
// 	temp = a;
// 	pos = 0;
// 	while (temp)
// 	{
// 		if (temp->index < check)
// 			pos++;
// 		temp = temp->next;
// 	}
// 	return (pos);
// }

// int	check_double_rot(t_stack **a, t_stack **b, int check_a, int check_b)
// {
// 	int	size_a;
// 	int	size_b;

// 	size_a = ft_size(*a);
// 	size_b = ft_size(*b);
// 	if (check_a && check_a > size_a / 2 && check_b && check_b > size_b / 2)
// 		return (1);
// 	if (check_a && check_a <= size_a / 2 && check_b && check_b <= size_b / 2)
// 		return (2);
// 	else
// 		return (0);
// }

// int	check_rot_a(t_stack **a, int check_a)
// {
// 	int	size_a;

// 	size_a = ft_size(*a);
// 	if (check_a && check_a > size_a / 2)
// 		return (1);
// 	if (check_a && check_a <= size_a / 2)
// 		return (2);
// 	else
// 		return (0);
// }

// int	check_rot_b(t_stack **b, int check_b)
// {
// 	int	size_b;

// 	size_b = ft_size(*b);
// 	if (check_b && check_b > size_b / 2)
// 		return (1);
// 	if (check_b && check_b <= size_b / 2)
// 		return (2);
// 	else
// 		return (0);
// }
