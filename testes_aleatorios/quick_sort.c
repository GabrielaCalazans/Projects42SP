/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:29:01 by gacalaza          #+#    #+#             */
/*   Updated: 2023/06/01 17:45:34 by gacalaza         ###   ########.fr       */
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
