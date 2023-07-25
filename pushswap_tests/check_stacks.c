/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:26:25 by gacalaza          #+#    #+#             */
/*   Updated: 2023/07/25 17:50:18 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Func checks if the stack is sorted.
int	check_its_sorted_a(t_stack **head)
{
	int		i;
	t_stack	*temp;

	temp = *head;
	i = temp->index;
	while (temp)
	{
		if (i > temp->index)
			return (0);
		i = temp->index;
		temp = temp->next;
	}
	return (1);
}

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

int	check_single_rot_atob(t_stack *a, t_stack *b, int check)
{
	int	result;

	result = check_pos_b(b, check);
	if (result < ft_int_pos(a, check))
		result = ft_int_pos(a, check);
	return (result);
}

int	check_double_revrot_atob(t_stack *a, t_stack *b, int check)
{
	int	result;

	result = 0;
	if (check_pos_b(b, check))
		result = ft_size(b) - check_pos_b(b, check);
	if (result < (ft_size(a) - ft_int_pos(a, check)) && ft_int_pos(a, check))
		result = ft_size(a) - ft_int_pos(a, check);
	return (result);
}

int	check_rota_revrotb_atob(t_stack *a, t_stack *b, int check)
{
	int	result;

	result = 0;
	if (check_pos_b(b, check))
		result = ft_size(b) - check_pos_b(b, check);
	result += ft_int_pos(a, check);
	return (result);
}

int	check_rotb_revrota_atob(t_stack *a, t_stack *b, int check)
{
	int	result;

	result = 0;
	if (ft_int_pos(a, check))
		result = ft_size(a) - ft_int_pos(a, check);
	result += check_pos_b(b, check);
	return (result);
}

int	rate_rarb_btoa(t_stack *a, t_stack *b, int check)
{
	int	result;

	result = track_pos_a(a, check);
	if (result < ft_int_pos(a, check))
		result = ft_int_pos(a, check);
	return (result);
}

int	rate_rrr_btoa(t_stack *a, t_stack *b, int check)
{
	int	result;

	result = 0;
	if (track_pos_a(b, check))
		result = ft_size(a) - track_pos_a(a, check);
	if (result < (ft_size(b) - ft_int_pos(b, check)) && ft_int_pos(b, check))
		result = ft_size(b) - ft_int_pos(b, check);
	return (result);
}

int	rate_ra_rrb_btoa(t_stack *a, t_stack *b, int check)
{
	int	result;

	result = 0;
	if (track_pos_a(a, check))
		result = ft_size(a) - track_pos_a(a, check);
	result += ft_int_pos(b, check);
	return (result);
}

int	rate_rb_rra_btoa(t_stack *a, t_stack *b, int check)
{
	int	result;

	result = 0;
	if (ft_int_pos(b, check))
		result = ft_size(b) - ft_int_pos(b, check);
	result += track_pos_a(a, check);
	return (result);
}

int	track_pos_a(t_stack *a, int check)
{
	t_stack	*temp;
	int		pos;
    
	temp = a;
	pos = 0;
	while (temp)
	{
		if (temp->index < check)
			pos++;
		temp = temp->next;
	}
	return (pos);
}

int	check_pos_b(t_stack *b, int check)
{
	t_stack	*temp;
	int		pos;

	pos = 1;
	if (check > b->index && check < ft_last(b)->index)
		pos = 0;
	else if (check > ft_max(b) || check < ft_min(b))
		pos = ft_int_pos(b, ft_max(b));
	else
	{
		temp = b->next;
		while (temp)
		{
			if (check > b->index || check < temp->index)
				pos++;
			else
				break ;
			temp = temp->next;
			b = b->next;
		}
	}
	return (pos);
}

int	check_pos_a(t_stack *a, int check)
{
	t_stack	*temp;
	int		pos;

	pos = 1;
	if (check > a->index && check < ft_last(a)->index)
		pos = 0;
	else if (check > ft_max(a) || check < ft_min(a))
		pos = ft_int_pos(a, ft_max(a)); //ft_min??
	else
	{
		temp = a->next;
		while (temp)
		{
			if (check > a->index || check < temp->index)
				pos++;
			else
				break ;
			temp = temp->next;
			a = a->next;
		}
	}
	return (pos);
}


int	check_op_a_to_b(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*temp;

	temp = a;
	i = check_double_revrot_atob(a, b, a->index);
	while (temp)
	{
		if (i > check_single_rot_atob(a, b, temp->index))
			i = check_single_rot_atob(a, b, temp->index);
		if (i > check_double_revrot_atob(a, b, temp->index))
			i = check_double_revrot_atob(a, b, temp->index);
		if (i > check_rota_revrotb(a, b, temp->index))
			i = check_rota_revrotb(a, b, temp->index);
		if (i > check_rotb_revrota(a, b, temp->index))
			i = check_rotb_revrota(a, b, temp->index);
		temp = temp->next;
	}
	return (i);	
}

int	check_op_b_to_a(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*temp;

	temp = a;
	i = check_double_revrot_atob(a, b, a->index);
	while (temp)
	{
		if (i > check_single_rot_atob(a, b, temp->index))
			i = check_single_rot_atob(a, b, temp->index);
		if (i > check_double_revrot_atob(a, b, temp->index))
			i = check_double_revrot_atob(a, b, temp->index);
		if (i > check_rota_revrotb(a, b, temp->index))
			i = check_rota_revrotb(a, b, temp->index);
		if (i > check_rotb_revrota(a, b, temp->index))
			i = check_rotb_revrota(a, b, temp->index);
		temp = temp->next;
	}
	return (i);	
}
