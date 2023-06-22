/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:57:06 by gacalaza          #+#    #+#             */
/*   Updated: 2023/06/21 17:24:57 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_test.h"

// t_node *createnode(int data)
// {
// 	t_node *newnode = (t_node *)malloc(sizeof(t_node));
// 	if (newnode == NULL)
// 	{
// 		printf("Failed to allocate memory for new node.\n");
// 		return NULL;
// 	}
// 	newnode->data = data;
// 	newnode->next = NULL;
// 	newnode->prev = NULL;
// 	return (newnode);
// }


// Func to create a new node
t_node	*createnode(int nbr, int index)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
	{
		printf("Failed to allocate memory for new node.\n");
		return NULL;
	}
	newnode->data = nbr;
	newnode->index = index;
	newnode->next = NULL;
	return (newnode);
}

// Function to find the last position
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

// Function to add a node at the last position
void ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node *temp;

	if (*lst)
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
	else
		*lst = new;
}

// // Function to print the linked list
// void	printList(t_node *head)
// {
// 	t_node	*temp;

// 	temp = head;
// 	while (temp != NULL)
// 	{
// 		printf("%d ", temp->data);
// 		temp = temp->next;
// 	}
// 	printf("\n");
// }

// Função para imprimir a lista encadeada
void	printList(t_node *head)
{
	t_node	*temp;

	if (!head)
		printf("EMPTY");
	temp = head;
	while (temp != NULL)
	{
		printf("NBR: %d idx: %d\n", temp->data, temp->index);
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

// Func to find the size of the lst
int	ft_size(t_node *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

// ** Method to perform swapping of data between 
// ** two positions in the linked list, divide and conquer
void	swap(t_node *node1, t_node *node2)
{
	int temp;
	
	temp = node1->data;
	node1->data = node2->data;
	node2->data = temp;
}

// ** Func finds and returns the smallest nbr int int the stack
int	ft_min(t_node *head)
{
	int		min;

	min = head->data;
	while (head)
	{
		if (head->data < min)
			min = head->data;
		head = head->next;
	}
	return (min);
}

// ** Func finds and returns the position of the smallest nbr int int the stack
int	ft_min_pos(t_node *head, int min)
{
	int	pos;

	pos = 0;
	while (head)
	{
		if (head->data == min)
			return (pos);
		head = head->next;
		pos++;
	}
	return (pos);
}

// Func to find the last node
t_node	*ft_last(t_node *lst)
{
	if (lst == NULL)
		return NULL;
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

// ** Func finds and returns the second smallest nbr int int the stack
int	ft_sec_min(t_node *head)
{
	int		sec_min;
	int		min;
	
	min = ft_min(head);
	sec_min = head->data;
	while (head)
	{
		if (head->data < sec_min && head->data > min)
			sec_min = head->data;
		head = head->next;
	}
	return (sec_min);
}

// ** Func finds and returns the smallest nbr int int the stack until size
int	ft_min_size(t_node *head, int size, char check)
{
	int		min;
	t_node	*last;

	last = ft_last(head);
	if (check == 't')
	{
		min = head->data;
		while (size > 0)
		{
			if (head->data < min)
				min = head->data;
			head = head->next;
			size--;
		}
	}
	if (check == 'b' && last)
	{
		min = last->data;
		while (size > 0)
		{
			if (last->data < min)
				min = last->data;
			last = last->prev;
			size--;
		}
	}
	return (min);
}

// ** Func finds and returns the biggest nbr int int the stack until size
int	ft_max_size(t_node *head, int size, char check)
{
	int		max;
	t_node	*last;
	t_node	*beg;

	last = ft_last(head);
	beg = head;
	if (check == 't')
	{
		max = beg->data;
		while (size > 0)
		{
			if (beg->data > max)
				max = beg->data;
			beg = beg->next;
			size--;
		}
	}
	if (check == 'b' && last)
	{
		max = last->data;
		while (size > 0)
		{
			if (last->data > max)
				max = last->data;
			last = last->prev;
			size--;
		}
	}
	return (max);
}

// Func checks if the stack a is sorted.
int	check_its_sorted_a_len(t_node **a)
{
	int		i;
	int		len;
	t_node	*temp;

	temp = *a;
	i = temp->data;
	len = 0;
	while (temp)
	{
		len++;
		if (i > temp->data)
			return (len);
		i = temp->data;
		temp = temp->next;
	}
	return (0);
}

// Func checks if the stack a is sorted.
int	check_its_sorted_a_len2(t_node **a)
{
	int		i;
	int		len;
	t_node	*temp;

	temp = *a;
	i = temp->data;
	len = 0;
	while (temp)
	{
		len++;
		if (len == 1 && i > temp->data)
			return (len);
		if (len > 1 && (i > temp->data || i < temp->prev->data))
			return (len);
		i = temp->data;
		temp = temp->next;
	}
	return (0);
}

// Func checks if the stack a is sorted.
int	check_its_sorted_a_idx(t_node **a)
{
	int		i;
	int		len;
	t_node	*temp;

	temp = *a;
	i = temp->index;
	temp = temp->next;
	len = 0;
	while (temp)
	{
		len++;
		if (len > 2 && (i + 1) != temp->index)
			return (len);
		if ((len > 0 && len < 3) && i > temp->index)
			return (len);
		i = temp->index;
		temp = temp->next;
	}
	return (0);
}

int	find_index(char **str, int nbr, int j)
{
	int	index;
	int	comp;
	int	i;

	index = 0;
	i = j;
	if (!str)
		return (0);
	while (str[i] != NULL)
	{
		comp = atoi(str[i]);
		if (comp < nbr)
			index++;
		i++;
	}
	return (index);
}


// void heapify(t_node *head, int size, int i)
// {
// 	int largest = i;
// 	int left = 2 * i + 1;
// 	int right = 2 * i + 2;

// 	t_node *largest_node = head;
// 	t_node *left_node = head;
// 	t_node *right_node = head;

// 	int j = 0;
// 	while (j < left)
// 	{
// 		left_node = left_node->next;
// 		j++;
// 	}
// 	if (left < size && left_node->data > largest_node->data)
// 		largest = left;

// 	j = 0;
// 	while (j < right)
// 	{
// 		right_node = right_node->next;
// 		j++;
// 	}
// 	if (right < size && right_node->data > largest_node->data)
// 		largest = right;

// 	if (largest != i)
// 	{
// 		j = 0;
// 		t_node *target = head;
// 		while (j < largest)
// 		{
// 			target = target->next;
// 			j++;
// 		}
// 		swap(largest_node, target);
// 		heapify(target, size, largest);
// 	}
// }

// void heapSort(t_node *head, int size)
// {
// 	for (int i = size / 2 - 1; i >= 0; i--)
// 	{
// 		t_node *current = head;
// 		int j = 0;
// 		while (j < i)
// 		{
// 			current = current->next;
// 			j++;
// 		}
// 		heapify(current, size, i);
// 	}
// 	for (int i = size - 1; i > 0; i--)
// 	{
// 		t_node *last = head;
// 		int j = 0;
// 		while (j < i)
// 		{
// 			last = last->next;
// 			j++;
// 		}
// 		swap(head, last);
// 		heapify(head, i, 0);
// 	}
// }
