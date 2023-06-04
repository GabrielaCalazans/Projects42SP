/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:46:18 by gacalaza          #+#    #+#             */
/*   Updated: 2023/06/03 18:34:23 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// (reverse rotate): Shift down all elements of stack by 1.
// The last element becomes the first one.

void	ft_rev_rotate_ab(t_stack **head, int check)
{
	t_stack	*last;
	t_stack	*prev;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	last = *head;
	prev = NULL;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *head;
	last->prev = NULL;
	*head = last;
	if (check == 97)
		ft_putstr_fd("rra\n", 1);
	if (check == 98)
		ft_putstr_fd("rrb\n", 1);
}

// rrr : rra and rrb at the same time.

void	ft_rev_rotate_r(t_stack **a_head, t_stack **b_head, int check)
{
	t_stack	*last;
	t_stack	*prev;

	if (*a_head == NULL || (*a_head)->next == NULL \
		|| *b_head == NULL || (*b_head)->next == NULL)
		return ;
	last = ft_last(*a_head);
	prev = ft_prevlast(*a_head);
	prev->next = NULL;
	last->prev = NULL;
	last->next = *a_head;
	*a_head = last;
	last = ft_last(*b_head);
	prev = ft_prevlast(*b_head);
	prev->next = NULL;
	last->prev = NULL;
	last->next = *b_head;
	*b_head = last;
	if (check == 195)
		ft_putstr_fd("rrr\n", 1);
}
