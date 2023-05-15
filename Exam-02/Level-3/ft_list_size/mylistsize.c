/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylistsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:50:36 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/10 16:44:43 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
	int		i = 0;
	t_list	*temp;

	if (!begin_list)
		return (0);
	temp = begin_list;
	while(temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

// t_list	*newnd(void *data)
// {
// 	t_list	*newnode;

// 	newnode = malloc(sizeof(t_list));
// 	if (!newnode)
// 		return (0);
// 	newnode->data = data;
// 	newnode->next = NULL;
// 	return (newnode);
// }

// int main()
// {
// 	t_list	*one;
// 	t_list	*two;
// 	t_list	*tree;
// 	t_list	*four;
// 	t_list	*five;
// 	t_list	*six;

// 	one = newnd("GA");
// 	two = newnd("BRI");
// 	tree = newnd("E");
// 	four = newnd("LA");
// 	five = newnd("CA");
// 	six = newnd("LA");
// 	one->next = two;
// 	two->next = tree;
// 	tree->next = four;
// 	four->next = five;
// 	five->next = six;

// 	int	len = ft_list_size(one);
// 	printf("%d\n", len);
// 	return (0);
// }