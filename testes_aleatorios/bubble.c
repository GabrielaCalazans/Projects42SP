/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:21:04 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/18 16:48:55 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// Função Bubble Sort para lista encadeada
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

// Função principal
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
