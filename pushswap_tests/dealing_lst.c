/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:45:51 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/18 23:46:12 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Função para criar um novo nó
t_stack	*newnode(int data)
{
	t_stack *newnode;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	newnode->data = data;
	newnode->next = NULL;
	return (newnode);
}

// Função pra achar a ultima posição
t_stack	*ft_lstlast(t_stack *lst)
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

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (*lst)
	{
		new->next = *lst;
		*lst = new;
	}
	else
		*lst = new;
}

// Função pra adicionar node na ultima posição
void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (*lst)
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
	else
		*lst = new;
}
