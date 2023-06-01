/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:52:15 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/31 22:15:24 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_test.h"

void	insertionSort(t_node *head)
{
	t_node	*i, *j;
	int		key;

	if (head == NULL || head->next == NULL)
		return;
	for (i = head->next; i != NULL; i = i->next)
	{
		key = i->data;
		j = i->prev;
		while (j != NULL && j->data > key)
		{
			j->next->data = j->data;
			j = j->prev;
		}
		if (j == NULL)
			head->data = key;
		else
			j->next->data = key;
	}
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


	insertionSort(head);
	printf("Sorted List:");
	printList(head);
	return 0;
}