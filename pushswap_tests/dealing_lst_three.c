/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_lst_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:29:03 by gacalaza          #+#    #+#             */
/*   Updated: 2023/06/09 20:15:28 by gacalaza         ###   ########.fr       */
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

// ** Func finds and returns the position of the smallest nbr int int the stack
int	ft_int_pos(t_stack *head, int min)
{
	int	pos;

	pos = 0;
	while (head)
	{
		if (head->nbr == min)
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
