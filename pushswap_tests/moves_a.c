/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:19:16 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/20 20:12:49 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// (swap): Swap the first 2 elements at the top of stack.
// Do nothing if there is only one or no elements.

void	ft_swap(t_stack *head, int check)
{
	t_stack	*ptr;
	int		temp;
	int		len;
	t_stack	*last;

	last = NULL;
	len = ft_lstsize(head);
	if (head == NULL || len < 2)
		return ;
	ptr = head;
	temp = ptr->nbr;
	ptr->nbr = ptr->next->nbr;
	ptr->next->nbr = temp;
	if (check == 1)
		ft_putstr_fd("sa\n", 1);
	if (check == 2)
		ft_putstr_fd("sb\n", 1);
}

// (push): Take the first element at the top of one 
// stack and put it at the top of another.
// Do nothing if is empty.

void	ft_push(t_stack *a_head, t_stack *b_head, int check)
{
	t_stack	*ptr;
	int		temp;
	t_stack	*last;

	last = NULL;
	if (check == 1)
	{
		if (b_head == NULL)
			return ;
		ptr = b_head;
		temp = ptr->nbr;
		ft_lstadd_front(&a_head, newnode(temp));
		b_head = ptr->next;
		ft_putstr_fd("pa\n", 1);
	}
	if (check == 2)
	{
		if (a_head == NULL)
			return ;
		ptr = a_head;
		temp = ptr->nbr;
		ft_lstadd_front(&b_head, newnode(temp));
		a_head = ptr->next;
		ft_putstr_fd("pb\n", 1);
	}
}

// (rotate): Shift up all elements of stack by 1.
// The first element becomes the last on

void	ft_rotate(t_stack *head, int check)
{
	t_stack	*ptr;
	int		temp;
	t_stack	*last;

	last = NULL;
	if (head == NULL)
		return ;
	ptr = head;
	temp = ptr->nbr;
	ft_lstadd_back(&head, newnode(temp));
	head = ptr->next;
	if (check == 1)
		ft_putstr_fd("ra\n", 1);
	if (check == 2)
		ft_putstr_fd("rb\n", 1);
}

// (reverse rotate): Shift down all elements of stack by 1.
// The last element becomes the first one.

void	ft_rev_rotate(t_stack *head, int check)
{
	t_stack	*ptr;
	int		temp;
	t_stack	*last;
	t_stack	*prev;

	last = NULL;
	if (head == NULL)
		return ;
	ptr = head;
	temp = ptr->nbr;
	ft_lstadd_front(&head, ft_lstlast(head));
	prev = ft_prevlast(head);
	while (head)
	{
		if (head == prev)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	if (check == 1)
		ft_putstr_fd("ra\n", 1);
	if (check == 2)
		ft_putstr_fd("rb\n", 1);
}