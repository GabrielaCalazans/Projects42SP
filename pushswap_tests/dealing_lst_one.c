/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_lst_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:45:51 by gacalaza          #+#    #+#             */
/*   Updated: 2023/07/28 17:52:29 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Func to create a new node
t_stack	*createnode(int nbr, int index)
{
	t_stack	*newnode;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	if (!newnode)
		ft_puterror();
	newnode->nbr = nbr;
	newnode->index = index;
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

// Func to find almost last
t_stack	*ft_second(t_stack *lst)
{
	t_stack	*second;

	if (lst == NULL)
		return (0);
	second = lst->next;
	return (second);
}
