/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:46:43 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/20 19:21:39 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Função para imprimir a lista encadeada
void	printlist(t_node *head)
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
	t_stack	*a;
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
	a = nodenew(n);
	while (argv[++i] != NULL)
	{
		n = atoi(argv[i]);
		newnode = nodenew(n);
		if (!newnode)
			break ;
		ft_lstadd_back(&a, newnode);
	}
	printf("Lista original: ");
	printlist(a);
	bubblesort(a);
	printf("Lista ordenada: ");
	printlist(a);
	ft_lstclear(&a);
	return (0);
}
