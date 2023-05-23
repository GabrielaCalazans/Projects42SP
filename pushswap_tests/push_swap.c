/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:46:43 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/22 23:56:49 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Função para imprimir a lista encadeada
void	printlist(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->nbr);
		temp = temp->next;
	}
	printf("\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*newnode;
	int		i;
	int		n;

	if (argc < 2)
	{
		printf ("Burro! Dá ZERO pra ele.\n");
		printf ("Número insuficiente de argumentos para ordenar!\n");
		printf ("\tInsira mais de 4 argumentos, ex.: ./a.out 42 66 1\n");
		return (1);
	}
	i = 1;
	a = NULL;
	b = NULL;
	n = atoi(argv[i]);
	a = createnode(n);
	while (argv[++i] != NULL)
	{
		n = atoi(argv[i]);
		newnode = createnode(n);
		if (!newnode)
			break ;
		ft_add_back(&a, newnode);
	}
	printf("Lista original: ");
	printlist(a);

	ft_swap(&a, &b, 97);
	printf("Lista a pós sa: ");
	printlist(a);

	ft_push(&a, &b, 98);
	printf("Lista a pós pb1: ");
	printlist(a);
	printf("Lista b pós pb1: ");
	printlist(b);

	ft_push(&a, &b, 98);
	printf("Lista a pós pb2: ");
	printlist(a);
	printf("Lista b pós pb2: ");
	printlist(b);
	
	ft_swap(&a, &b, 98);
	printf("Lista a pós sb: ");
	printlist(a);
	printf("Lista b pós sb: ");
	printlist(b);

	ft_rotate(&a, 97);
	printf("Lista a pós ra: ");
	printlist(a);
	printf("Lista b pós ra: ");
	printlist(b);

	ft_rotate(&b, 98);
	printf("Lista a pós rb: ");
	printlist(a);
	printf("Lista b pós rb: ");
	printlist(b);

	ft_rev_rotate(&a, 97);
	printf("Lista a pós rra: ");
	printlist(a);
	printf("Lista b pós rra: ");
	printlist(b);

	ft_rev_rotate(&b, 98);
	printf("Lista a pós rrb: ");
	printlist(a);
	printf("Lista b pós rrb: ");
	printlist(b);

	ft_swap(&a, &b, 195);
	printf("Lista a pós ss: ");
	printlist(a);
	printf("Lista b pós ss: ");
	printlist(b);

	ft_push(&a, &b, 97);
	printf("Lista a pós pa: ");
	printlist(a);
	printf("Lista b pós pa: ");
	printlist(b);



	ft_clear(&a);
	ft_clear(&b);
	return (0);
}
