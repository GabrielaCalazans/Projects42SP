/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:04:39 by gacalaza          #+#    #+#             */
/*   Updated: 2023/06/08 19:53:36 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Heap Sort in C

#include "sort_test.h"

// Função para converter a lista encadeada em um array
int* convertToArray(t_node* head, int size)
{
	int* arr = (int*)malloc(sizeof(int) * size);
	t_node* temp = head;
	for (int i = 0; i < size; i++)
	{
		arr[i] = temp->data;
		temp = temp->next;
	}
	return (arr);
}

// Função para converter o array de volta para a lista encadeada
t_node* convertToList(int* arr, int size)
{
	t_node* head = NULL;
	for (int i = 0; i < size; i++)
	{
		t_node* newNode = createNode(arr[i]);
		addNode(&head, newNode);
	}
	return (head);
}

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
	// Find largest among root,
	// left child and right child
	// Initialize largest as root
void	heapify(t_node *head, int size, int i)
{
	int		largest = i;
	int		left = 2 * i + 1;
	int		right = 2 * i + 2;
	t_node	*largest_node = head;
	t_node	*left_node = head;
	t_node	*right_node = head;

	int j = 0;
	while (j < left)
	{
		left_node = left_node->next;
		j++;
	}
	// If left child is larger than root
	if (left < size && left_node->data > largest_node->data)
		largest = left;
	// If right child is larger than largest so far
	j = 0;
	while (j < right)
	{
		right_node = right_node->next;
		j++;
	}
	if (right < size && right_node->data > largest_node->data)
		largest = right;

	if (largest != i)
	{
		j = 0;
		t_node *target = head;
		while (j < largest)
		{
			target = target->next;
			j++;
		}
		swap(largest_node, target);
		heapify(target, size, largest);
	}
}

// Main function to do heap sort
void	heapSort(t_node *head, int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		t_node *current = head;
		int j = 0;
		while (j < i)
		{
			current = current->next;
			j++;
		}
		heapify(current, size, i);
	}
	for (int i = size - 1; i > 0; i--)
	{
		t_node *last = head;
		int j = 0;
		while (j < i)
		{
			last = last->next;
			j++;
		}
		swap(head, last);
		heapify(head, i, 0);
	}
}

// Driver's code
int main(int argc, char *argv[])
{
	t_node	*head;
	t_node	*newnode;
	int		i; 
	int		n;
	int		size;

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
	size = ft_size(head);
	printf("size:%d\n", size);
	// int arr[] = { 12, 11, 13, 5, 6, 7 };
	// printf("N: %d, sizeofarr[0]: %lu, sizeof(arr): %lu\n", N, sizeof(arr[0]), sizeof(arr) );

	// Function call
	printf("Given list: ");
	printList(head);

	heapSort(head, size);

	printf("Sorted list: ");
	printList(head);
	return (0);
}
