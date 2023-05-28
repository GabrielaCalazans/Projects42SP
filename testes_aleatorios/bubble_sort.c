/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:21:04 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/27 14:47:02 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_test.h"

// Bubble Sort function for linked list
void	bubblesort(t_node *head)
{
	int		swapped;
	int		temp;
	t_node	*ptr;
	t_node	*lptr;

	lptr = NULL;
	if (head == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		ptr = head;

		while (ptr->next != lptr)
		{
			if (ptr->data > ptr->next->data)
			{
				temp = ptr->data;
				ptr->data = ptr->next->data;
				ptr->next->data = temp;
				swapped = 1;
			}
			ptr = ptr->next;
		}
		lptr = ptr;
	}
}

// Função principal
int main(int argc, char *argv[])
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
	
	printf("Lista original: ");
	printList(head);

	bubblesort(head);

	printf("Lista ordenada: ");
	printList(head);

	ft_lstclear(&head);

	return (0);
}
