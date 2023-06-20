/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_lst_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:29:03 by gacalaza          #+#    #+#             */
/*   Updated: 2023/06/19 16:16:29 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// ** Func finds and returns the smallest nbr int int the stack
int	ft_min(t_stack *head)
{
	int		min;

	min = head->nbr;
	while (head)
	{
		if (head->nbr < min)
			min = head->nbr;
		head = head->next;
	}
	return (min);
}

// ** Func finds and returns the smallest nbr int int the stack until size
int	ft_min_size(t_stack *head, int size, char check)
{
	int		min;
	t_stack	*last;

	last = ft_last(head);
	if (check == 't')
	{
		min = head->nbr;
		while (size > 0)
		{
			if (head->nbr < min)
				min = head->nbr;
			head = head->next;
			size--;
		}
	}
	if (check == 'b' && last)
	{
		min = last->nbr;
		while (size > 0)
		{
			if (last->nbr < min)
				min = last->nbr;
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
		max = beg->nbr;
		while (size > 0)
		{
			if (beg->nbr > max)
				max = beg->nbr;
			beg = beg->next;
			size--;
		}
	}
	if (check == 'b' && last)
	{
		max = last->nbr;
		while (size > 0)
		{
			if (last->nbr > max)
				max = last->nbr;
			last = last->prev;
			size--;
		}
	}
	return (max);
}

// ** Func finds and returns the position of the smallest nbr int int the stack
int	ft_int_pos(t_stack *head, int find)
{
	int	pos;

	pos = 0;
	while (head)
	{
		if (head->nbr == find)
			return (pos);
		head = head->next;
		pos++;
	}
	return (pos);
}

// ** Func finds and returns the second smallest nbr int int the stack
int	ft_sec_min(t_stack *head)
{
	int		sec_min;
	int		min;
	
	min = ft_min(head);
	sec_min = head->nbr;
	while (head)
	{
		if (head->nbr < sec_min && head->nbr > min)
			sec_min = head->nbr;
		head = head->next;
	}
	return (sec_min);
}

// ** Func finds and returns the biggest nbr int in the stack
int	ft_max(t_stack *head)
{
	int		max;

	max = head->nbr;
	while (head)
	{
		if (head->nbr > max)
			max = head->nbr;
		head = head->next;
	}
	return (max);
}
