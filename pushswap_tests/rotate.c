/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:46:02 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/23 13:41:53 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// (rotate): Shift up all elements of stack by 1.
// The first element becomes the last on

void	ft_rotate_ab(t_stack **head, int check)
{
	t_stack	*ptr;
	t_stack	*newnode;
	int		nbr;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	ptr = *head;
	nbr = ptr->nbr;
	newnode = createnode(nbr);
	if (!newnode)
		return ;
	ft_add_back(&*head,newnode);
	*head = ptr->next;
	if (check == 97)
		ft_putstr_fd("ra\n", 1);
	if (check == 98)
		ft_putstr_fd("rb\n", 1);
}

// rr : ra and rb at the same time.

void	ft_rotate_rr(t_stack **a_head, t_stack **b_head, int check)
{
	t_stack	*ptr;
	t_stack	*newnode;
	int		nbr;

	if (*a_head == NULL || (*a_head)->next == NULL \
		|| *b_head == NULL || (*b_head)->next == NULL)
		return ;
	ptr = *a_head;
	nbr = ptr->nbr;
	newnode = createnode(nbr);
	if (!newnode)
		return ;
	ft_add_back(&*a_head,newnode);
	*a_head = ptr->next;
	ptr = *b_head;
	nbr = ptr->nbr;
	newnode = createnode(nbr);
	if (!newnode)
		return ;
	ft_add_back(&*b_head,newnode);
	*b_head = ptr->next;
	if (check == 195)
		ft_putstr_fd("rr\n", 1);
}
