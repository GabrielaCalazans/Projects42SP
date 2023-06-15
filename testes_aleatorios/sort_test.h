#ifndef SORT_TEST_H
# define SORT_TEST_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

// Definition of the node structure for the linked list
typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

// Class Quicksort
typedef struct s_quicksort
{
	t_node	*elements;
	int		size;
}			t_quicksort;

t_node	*createnode(int data);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	printList(t_node *head);
void	ft_lstclear(t_node **lst);
void	bubblesort(t_node *head);
int 	ft_size(t_node *lst);
void	selectionSort(t_node *head);
void	insertionSort(t_node *head);
void	swap(t_node *node1, t_node *node2);
int		ft_min(t_node *head);
int		ft_min_size(t_node *head, int size, char check);
int		ft_min_pos(t_node *head, int min);
int		ft_sec_min(t_node *head);
int		ft_max_size(t_node *head, int size, char check);
int		check_its_sorted_a_len(t_node **a);

#endif