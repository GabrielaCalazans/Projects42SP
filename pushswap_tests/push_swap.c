/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:46:43 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/19 23:21:26 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

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

int	main(int argc, char *argv[])
{
	t_stack *a;

	t_stack	*newnode;
	int		i;
	int		n;

	if (argc < 3)
	{
		printf ("Número insuficiente de argumentos para ordenar!\n");
		printf ("\tInsira mais de 4 argumentos, ex.: ./a.out 42 66 1\n");
		return (1);
	}
	i = 1;
	a = NULL;
	n = atoi(argv[i]);
	a = newnode(n);

	while (argv[++i] != NULL)
	{
		n = atoi(argv[i]);
		newnode = createnode(n);
		if (!newnode)
			break ;
		ft_lstadd_back(&a, newnode);
	}
	
	printf("Lista original: ");
	printList(a);

	bubblesort(a);

	printf("Lista ordenada: ");
	printList(a);

	ft_lstclear(&a);

	
	return (0);
}
