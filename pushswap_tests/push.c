/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:45:27 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/23 13:21:09 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// (push): Take the first element at the top of one 
// stack and put it at the top of another.
// Do nothing if is empty.

void	ft_push(t_stack **a_head, t_stack **b_head, int check)
{
	t_stack	*ptr;
	t_stack	*newnode;
	int		nbr;

	if (check == 97)
	{
		if (*b_head == NULL || (*b_head)->next == NULL)
			return ;
		ptr = *b_head;
		nbr = ptr->nbr;
		newnode = createnode(nbr);
		if (!newnode)
			return ;
		ft_add_front(&*a_head, newnode);
		*b_head = ptr->next;
		ft_putstr_fd("pa\n", 1);
	}
	if (check == 98)
	{
		if (*a_head == NULL || (*a_head)->next == NULL)
			return ;
		ptr = *a_head;
		nbr = ptr->nbr;
		newnode = createnode(nbr);
		if (!newnode)
			return ;
		ft_add_front(&*b_head, newnode);
		*a_head = ptr->next;
		ft_putstr_fd("pb\n", 1);
	}
}
