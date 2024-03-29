/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:12:33 by gacalaza          #+#    #+#             */
/*   Updated: 2023/11/28 20:18:39 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Func to create a new node
t_token	*createnode(char *token, int type)
{
	t_token	*newnode;

	newnode = (t_token *)malloc(sizeof(t_token));
	if (!newnode)
	{
		perror("malloc");
		return (NULL);
	}
	newnode->token = ft_strdup(token);
	newnode->type = type;
	newnode->next = NULL;
	newnode->prev = NULL;
	if (!newnode->token || !newnode->type)
	{
		perror("ft_strdup");
		free(newnode);
		return (NULL);
	}
	newnode->next = NULL;
	return (newnode);
}

// Func to find the last node
t_token	*ft_last(t_token *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

// Func to add node at the end of the lst
void	ft_add_back(t_token **lst, t_token *new)
{
	t_token	*temp;

	if (*lst)
	{
		temp = ft_last(*lst);
		temp->next = new;
		new->prev = temp;
	}
	else
		*lst = new;
}

// Func to add node at the beging of the lst
void	ft_add_front(t_token **lst, t_token *new)
{
	if (*lst)
	{
		new->next = *lst;
		(*lst)->prev = new;
		*lst = new;
	}
	else
		*lst = new;
}
