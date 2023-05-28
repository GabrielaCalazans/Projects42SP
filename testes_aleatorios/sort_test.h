#ifndef SORT_TEST_H
# define SORT_TEST_H

#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure for the linked list
typedef struct s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

t_node	*createnode(int data);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	printList(t_node *head);
void	ft_lstclear(t_node **lst);
void	bubblesort(t_node *head);
int 	ft_size(t_node *lst);
void	selectionSort(t_node *head);

#endif