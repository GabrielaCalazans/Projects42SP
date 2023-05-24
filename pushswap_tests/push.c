/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:45:27 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/23 17:29:56 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// (push): Take the first element at the top of one 
// stack and put it at the top of another.
// Do nothing if is empty.

void	ft_push_a(t_stack **a_head, t_stack **b_head, int check)
{
	t_stack	*ptr;

	if (*b_head == NULL || (*b_head)->next == NULL)
		return ;
	ptr = *b_head;
	*b_head = ptr->next;
	ptr->next = NULL;
	ft_add_front(&*a_head, ptr);
	if (check == 97)
		ft_putstr_fd("pa\n", 1);
}

void	ft_push_b(t_stack **a_head, t_stack **b_head, int check)
{
	t_stack	*ptr;

	if (*a_head == NULL || (*a_head)->next == NULL)
		return ;
	ptr = *a_head;
	*a_head = ptr->next;
	ptr->next = NULL;
	ft_add_front(&*b_head, ptr);
	if (check == 98)
		ft_putstr_fd("pb\n", 1);
}
