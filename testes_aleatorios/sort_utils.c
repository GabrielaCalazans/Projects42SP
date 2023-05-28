/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:57:06 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/27 14:49:54 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_test.h"

// Function to create a new node
t_node	*createnode(int data)
{
	t_node *newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	newnode->data = data;
	newnode->next = NULL;
	return (newnode);
}

// Function to find the last position
t_node	*ft_lstlast(t_node *lst)
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

// Function to add a node at the last position
void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*temp;

	if (*lst)
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
	else
		*lst = new;
}

// Function to print the linked list
void	printList(t_node *head)
{
	t_node	*temp;

	temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void	ft_lstclear(t_node **lst)
{
	t_node	*temp;
	t_node	*next;

	temp = *lst;
	while (temp != NULL)
	{
		next = temp->next;
		free (temp);
		temp = next;
	}
	*lst = NULL;
}

// Func to find the size of the lst
int	ft_size(t_node *lst)
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