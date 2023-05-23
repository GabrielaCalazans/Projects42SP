/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:19:16 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/23 00:40:51 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// (swap): Swap the first 2 elements at the top of stack.
// Do nothing if there is only one or no elements.

void	ft_swap(t_stack **a_head, t_stack **b_head, int check)
{
	t_stack	*ptr;
	int		nbr;
	int		len_a;
	int		len_b;

	len_a = ft_size(*a_head);
	len_b = ft_size(*b_head);
	if (check == 97 && len_a > 1)
	{
		if (*a_head == NULL || (*a_head)->next == NULL)
			return ;
		ptr = *a_head;
		(void)b_head;
		ft_putstr_fd("sa\n", 1);
	}
	if (check == 98 && len_b > 1)
	{
		if (*b_head == NULL || (*b_head)->next == NULL)
			return ;
		ptr = *b_head;
		(void)a_head;
		ft_putstr_fd("sb\n", 1);
	}
	if (check == 195 && (len_a > 1 && len_b > 1))
	{
		ft_swap(a_head, b_head, 97);
		ft_swap(a_head, b_head, 98);
		ft_putstr_fd("ss\n", 1);
		return ;
	}
	nbr = ptr->nbr;
	ptr->nbr = ptr->next->nbr;
	ptr->next->nbr = nbr;
}

// ss : sa and sb at the same time.



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

// (rotate): Shift up all elements of stack by 1.
// The first element becomes the last on

void	ft_rotate(t_stack **head, int check)
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



// (reverse rotate): Shift down all elements of stack by 1.
// The last element becomes the first one.

void ft_rev_rotate(t_stack **head, int check)
{
	t_stack *last;
	t_stack *prev;

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
	*head = last;
	if (check == 97)
		ft_putstr_fd("rra\n", 1);
	if (check == 98)
		ft_putstr_fd("rrb\n", 1);
}

// rrr : rra and rrb at the same time.
