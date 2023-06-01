/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:57:06 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/31 17:42:19 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_test.h"

t_node *createnode(int data)
{
	t_node *newnode = (t_node *)malloc(sizeof(t_node));
	if (newnode == NULL)
	{
		printf("Failed to allocate memory for new node.\n");
		return NULL;
	}
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;
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
void ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node *temp;

	if (*lst)
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
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