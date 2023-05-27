/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:30:15 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/26 23:47:46 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// C program for implementation of selection sort
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
typedef struct s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

// Função para criar um novo nó
t_node	*createnode(int data)
{
	t_node *newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	newnode->data = data;
	newnode->next = NULL;
	return (newnode);
}

// Função pra achar a ultima posição
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

// Função pra adicionar node na ultima posição
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

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n-1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;

		// Swap the found minimum element with the first element
		if(min_idx != i)
			swap(&arr[min_idx], &arr[i]);
	}
}

// Função para imprimir a lista encadeada
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

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
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

// Driver program to test above functions
int main(int argc, char *argv[])
{
	t_node	*head;
	t_node	*newnode;
	int		i;
	int		n;
	
	if (argc < 2)
	{
		printf ("Número insuficiente de argumentos para ordenar!\n");
		printf ("\tInsira mais de 4 argumentos, ex.: ./a.out 42 66 1\n");
		return (1);
	}
	i = 1;
	head = NULL;
	n = atoi(argv[i]);
	head = createnode(n);

	printf("Lista original: ");
	printList(head);

	int arr[] = {64, 25, 12, 22, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}
