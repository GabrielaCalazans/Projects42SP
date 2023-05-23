/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:45:51 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/22 17:52:01 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Função para criar um novo nó
t_stack	*createnode(int nbr)
{
	t_stack	*newnode;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	newnode->nbr = nbr;
	newnode->next = NULL;
	return (newnode);
}

// Função pra achar a ultima posição
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

// Função pra achar a penutima posição
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

// Função pra adicionar node na ultima posição
void	ft_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (*lst)
	{
		temp = ft_last(*lst);
		temp->next = new;
	}
	else
		*lst = new;
}

// Função para saber o tamanho da lista
int	ft_size(t_stack *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

void	ft_clear(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*next;

	temp = *lst;
	while (temp != NULL)
	{
		next = temp->next;
		free (temp);
		temp = next;
	}
	*lst = NULL;
}
