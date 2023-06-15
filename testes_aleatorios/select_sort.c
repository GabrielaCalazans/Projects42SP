/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:30:15 by gacalaza          #+#    #+#             */
/*   Updated: 2023/06/15 18:56:34 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_test.h"

// C program for implementation of selection sort

void	swap_struct(struct s_node *x, struct s_node *y)
{
	int	temp;

	temp = x->data;
	x->data = y->data;
	y->data = temp;
	printf("sa\n");
}

void	selectionSort(t_node *head)
{
	t_node *i, *j, *min;

	// One by one move boundary of unsorted sub-list
	for (i = head; i != NULL && i->next != NULL; i = i->next)
	{
		// Find the minimum element in the unsorted list
		min = i;
		for (j = i->next; j != NULL; j = j->next)
		{
			if (j->data < min->data)
				min = j;
		}
		// Swap the found minimum element with the first element
		if (min != i)
			swap_struct(i, min);
	}
}

// Driver program to test above functions
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
	printf("size: %d\n", size);
	printf("Given list: ");
	printList(head);
	
	int	sort_len = check_its_sorted_a_len(&head);
	printf("sort_len:%d\n", sort_len);
	printf("max t: %d, max b: %d\n", ft_max_size(head, size / 2, 't'), ft_max_size(head, size / 2, 'b'));

	selectionSort(head);
	printf("Sorted List: \n");
	printList(head);
	return 0;
}
