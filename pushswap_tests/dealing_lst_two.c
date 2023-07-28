/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing_lst_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:35:50 by gacalaza          #+#    #+#             */
/*   Updated: 2023/07/28 17:59:36 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// Func to add node at the beging of the lst
void	ft_add_front(t_stack **lst, t_stack *new)
{
	if (*lst)
	{
		new->next = *lst;
		new->prev = NULL;
		*lst = new;
	}
	else
		*lst = new;
}

// Func to add node at the end of the lst
void	ft_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (*lst)
	{
		temp = ft_last(*lst);
		temp->next = new;
		new->prev = temp;
	}
	else
		if (*lst)
			*lst = new;
}

// Func to find the size of the lst
int	ft_size(t_stack *lst)
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

// Func to free the the lst
void	ft_clear(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*next;

	temp = *lst;
	while (temp != NULL)
	{
		next = temp->next;
		free (temp);
		temp = next;
	}
	*lst = NULL;
}
