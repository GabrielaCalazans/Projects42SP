/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:45:51 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/24 16:40:28 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Func to create a new node
t_stack	*createnode(int nbr)
{
	t_stack	*newnode;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	newnode->nbr = nbr;
	newnode->next = NULL;
	return (newnode);
}

// Func to find the last node
t_stack	*ft_last(t_stack *lst)
{
	if (lst == NULL)
		return (0);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

// Func to find almost last
t_stack	*ft_prevlast(t_stack *lst)
{
	t_stack	*last;

	last = ft_last(lst);
	if (lst == NULL)
		return (0);
	while (lst)
	{
		if (lst->next == last)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

// Func to add node at the beging of the lst
void	ft_add_front(t_stack **lst, t_stack *new)
{
	if (*lst)
	{
		new->next = *lst;
		*lst = new;
	}
	else
		*lst = new;
}
