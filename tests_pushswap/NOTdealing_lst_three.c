/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_lst_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:42:27 by gacalaza          #+#    #+#             */
/*   Updated: 2023/07/28 17:56:11 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// ** Func finds and returns the smallest nbr int int the stack until size
int	ft_min_size(t_stack *head, int size, char check)
{
	int		min;
	t_stack	*last;

	last = ft_last(head);
	if (check == 't')
	{
		min = head->index;
		while (size > 0)
		{
			if (head->index < min)
				min = head->index;
			head = head->next;
			size--;
		}
	}
	if (check == 'b' && last)
	{
		min = last->index;
		while (size > 0)
		{
			if (last->index < min)
				min = last->index;
			last = last->prev;
			size--;
		}
	}
	return (min);
}

// ** Func finds and returns the biggest nbr int int the stack until size
int	ft_max_size(t_stack *head, int size, char check)
{
	int		max;
	t_stack	*last;
	t_stack	*beg;

	last = ft_last(head);
	beg = head;
	if (check == 't')
	{
		max = beg->index;
		while (size > 0)
		{
			if (beg->index > max)
				max = beg->index;
			beg = beg->next;
			size--;
		}
	}
	if (check == 'b' && last)
	{
		max = last->index;
		while (size > 0)
		{
			if (last->index > max)
				max = last->index;
			last = last->prev;
			size--;
		}
	}
	return (max);
}

// ** Func finds and returns the second smallest nbr int int the stack
int	ft_sec_min(t_stack *head)
{
	int		sec_min;
	int		min;

	min = ft_min(head);
	sec_min = head->index;
	while (head)
	{
		if (head->index < sec_min && head->index > min)
			sec_min = head->index;
		head = head->next;
	}
	return (sec_min);
}
