/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:57:06 by gacalaza          #+#    #+#             */
/*   Updated: 2023/06/08 19:06:30 by gacalaza         ###   ########.fr       */
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

// ** Method to perform swapping of data between 
// ** two positions in the linked list, divide and conquer
void	swap(t_node *node1, t_node *node2)
{
	int temp;
	
	temp = node1->data;
	node1->data = node2->data;
	node2->data = temp;
}


// void heapify(t_node *head, int size, int i)
// {
// 	int largest = i;
// 	int left = 2 * i + 1;
// 	int right = 2 * i + 2;

// 	t_node *largest_node = head;
// 	t_node *left_node = head;
// 	t_node *right_node = head;

// 	int j = 0;
// 	while (j < left)
// 	{
// 		left_node = left_node->next;
// 		j++;
// 	}
// 	if (left < size && left_node->data > largest_node->data)
// 		largest = left;

// 	j = 0;
// 	while (j < right)
// 	{
// 		right_node = right_node->next;
// 		j++;
// 	}
// 	if (right < size && right_node->data > largest_node->data)
// 		largest = right;

// 	if (largest != i)
// 	{
// 		j = 0;
// 		t_node *target = head;
// 		while (j < largest)
// 		{
// 			target = target->next;
// 			j++;
// 		}
// 		swap(largest_node, target);
// 		heapify(target, size, largest);
// 	}
// }

// void heapSort(t_node *head, int size)
// {
// 	for (int i = size / 2 - 1; i >= 0; i--)
// 	{
// 		t_node *current = head;
// 		int j = 0;
// 		while (j < i)
// 		{
// 			current = current->next;
// 			j++;
// 		}
// 		heapify(current, size, i);
// 	}
// 	for (int i = size - 1; i > 0; i--)
// 	{
// 		t_node *last = head;
// 		int j = 0;
// 		while (j < i)
// 		{
// 			last = last->next;
// 			j++;
// 		}
// 		swap(head, last);
// 		heapify(head, i, 0);
// 	}
// }
