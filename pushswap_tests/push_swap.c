/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:46:43 by gacalaza          #+#    #+#             */
/*   Updated: 2023/07/26 20:39:09 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Function to print the linked list
void	printlist(t_stack *head)
{
	t_stack	*temp;

	if (!head)
		printf("EMPTY");
	temp = head;
	while (temp != NULL)
	{
		printf("NBR: %d idx: %d\n", temp->nbr, temp->index);
		temp = temp->next;
	}
	printf("\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		len;

	a = NULL;
	b = NULL;
	if (check_args(argc, argv))
		a = starting(&a, argc, argv);
	// printf("Original List a: \n");
	// printlist(a);
	len = ft_size(a);
	if (len > 1 && !check_its_sorted_a(&a))
		sorting_it(&a, &b, len);
	// printf("Sorted List a: \n");
	// printlist(a);
	// printf("Sorted List b: \n");
	// printlist(b);
	ft_clear(&a);
	ft_clear(&b);
	return (0);
}

// 	ft_swap_ab(&a, 97);
// 	printf("Lista a pós sa: ");
// 	printlist(a);

// 	ft_push_b(&a, &b, 98);
// 	printf("Lista a pós pb1: ");
// 	printlist(a);
// 	printf("Lista b pós pb1: ");
// 	printlist(b);

// 	ft_push_b(&a, &b, 98);
// 	printf("Lista a pós pb2: ");
// 	printlist(a);
// 	printf("Lista b pós pb2: ");
// 	printlist(b);

// 	ft_swap_ab(&b, 98);
// 	printf("Lista a pós sb: ");
// 	printlist(a);
// 	printf("Lista b pós sb: ");
// 	printlist(b);

// 	ft_rotate_ab(&a, 97);
// 	printf("Lista a pós ra: ");
// 	printlist(a);
// 	printf("Lista b pós ra: ");
// 	printlist(b);

// 	ft_rotate_ab(&b, 98);
// 	printf("Lista a pós rb: ");
// 	printlist(a);
// 	printf("Lista b pós rb: ");
// 	printlist(b);

// 	ft_rev_rotate_ab(&a, 97);
// 	printf("Lista a pós rra: ");
// 	printlist(a);
// 	printf("Lista b pós rra: ");
// 	printlist(b);

// 	ft_rev_rotate_ab(&b, 98);
// 	printf("Lista a pós rrb: ");
// 	printlist(a);
// 	printf("Lista b pós rrb: ");
// 	printlist(b);

// 	ft_swap_ss(&a, &b, 195);
// 	printf("Lista a pós ss: ");
// 	printlist(a);
// 	printf("Lista b pós ss: ");
// 	printlist(b);

// 	ft_rotate_rr(&a, &b, 195);
// 	printf("Lista a pós rr: ");
// 	printlist(a);
// 	printf("Lista b pós rr: ");
// 	printlist(b);

// 	ft_rev_rotate_r(&a, &b, 195);
// 	printf("Lista a pós rrr: ");
// 	printlist(a);
// 	printf("Lista b pós rrr: ");
// 	printlist(b);

// 	ft_push_a(&a, &b, 97);
// 	printf("Lista a pós pa: ");
// 	printlist(a);
// 	printf("Lista b pós pa: ");
// 	printlist(b);

// 	ft_clear(&a);
// 	ft_clear(&b);
// 	return (0);
// }
