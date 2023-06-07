/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:29:01 by gacalaza          #+#    #+#             */
/*   Updated: 2023/06/07 01:37:17 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_test.h"

#include <stdio.h>
#include <stdlib.h>

// ** Method to perform swapping of data between 
// ** two positions in the linked list, divide and conquer
void	swap(t_node *node1, t_node *node2)
{
	int temp = node1->data;
	node1->data = node2->data;
	node2->data = temp;
}

// ** Method to perform partitioning, the core of the 
// ** Quicksort algorithm, divide and conquer
t_node	*partition(t_node *start, t_node *end)
{
	int		pivot = end->data;
	t_node	*i = start->prev;

	t_node *j = start;
	while (j != end)
	{
		if (j->data <= pivot)
		{
			if (i == NULL)
				i = start;
			else
				i = i->next;
			swap(i, j);
		}
		j = j->next;
	}
	if (i == NULL)
		i = start;
	else
		i = i->next;
	swap(i, end);
	return (i);
}

// Method to perform Quicksort recursively
void quicksort(t_node *start, t_node *end)
{
	if (start == NULL || end == NULL || start == end || end->next == start)
		return;
	t_node	*pivot = partition(start, end);
	quicksort(start, pivot->prev);
	quicksort(pivot->next, end);
}

int	main(int argc, char *argv[])
{
	t_node	*head;
	t_node	*newnode;
	int		i; 
	int		n;

	if (argc < 2)
	{
		printf ("Insufficient number of arguments to sort!\n");
		printf ("\tPlease provide more than 4 arguments, e.g., ./a.out 42 66 1.\n");
		return (1);
	}
	i = 1;
	head = NULL;
	n = atoi(argv[i]);
	head = createnode(n);
	while (argv[++i] != NULL)
	{
		n = atoi(argv[i]);
		newnode = createnode(n);
		if (!newnode)
			break ;
		ft_lstadd_back(&head, newnode);
	}
	printf("Given list: ");
	printList(head);

	quicksort(head, newnode);

	printf("Sorted list: ");
	printList(head);
	return 0;
}


// static int	partition(int *array, int left, int right)
// {
// 	int	i;
// 	int	j;
// 	int	pivot;
// 	int	temp;

// 	pivot = array[left];
// 	i = left;
// 	j = left + 1;
// 	while (j <= right)
// 	{
// 		if (array[j] < pivot)
// 		{
// 			i++;
// 			temp = array[j];
// 			array[j] = array[i];
// 			array[i] = temp;
// 		}
// 		j++;
// 	}
// 	temp = array[left];
// 	array[left] = array[i];
// 	array[i] = temp;
// 	return (i);
// }

// void	quick_sort(int *array, int left, int right)
// {
// 	int	index_pivot;

// 	if (left < right)
// 	{
// 		index_pivot = partition(array, left, right);
// 		quick_sort(array, left, index_pivot - 1);
// 		quick_sort(array, index_pivot + 1, right);
// 	}
// }

// t_stack	*get_stack_node(t_stack *head, int index)
// {
// 	t_stack	*current;

// 	current = head;
// 	while (current != NULL)
// 	{
// 		if (current->index == index)
// 			return (current);
// 		current = current->next;
// 	}
// 	return (NULL);
// }

// static t_stack	*partition(t_stack *head, int left, int right)
// {
// 	int			pivot_index = left;
// 	t_stack		*pivot_node = get_stack_node(head, pivot_index);
// 	t_stack		*smaller = NULL;
// 	t_stack		*greater = NULL;
// 	t_stack		*current = head;

// 	while (current != NULL)
// 	{
// 		t_stack *next = current->next;

// 		if (current->index != pivot_index)
// 		{
// 			if (current->index < pivot_index)
// 				ft_push(&smaller, current);
// 			else
// 				ft_push(&greater, current);
// 		}
// 		current = next;
// 	}
// 	// Recursively sort the smaller and greater partitions
// 	smaller = quick_sort(smaller);
// 	greater = quick_sort(greater);
// 	// Concatenate the smaller partition, pivot node, and greater partition
// 	head = concatenate(smaller, pivot_node, greater);
// 	return (head);
// }

// t_stack	*quick_sort(t_stack *head)
// {
// 	// Base case: If the list is empty or has only one node, return it
// 	if (head == NULL || head->next == NULL)
// 		return (head);
// 	// Choose the rightmost node as the pivot
// 	t_stack *tail = ft_last(head);
// 	int right = tail->index;
// 	// Call the partition function to partition the list
// 	head = partition(head, 0, right);
// 	return (head);
// }
