/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:12:33 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/16 16:27:57 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Func to create a new node
t_cmds	*createnode(char *cmd, char *cmd_args, char *heredocs)
{
	t_cmds	*newnode;

	newnode = (t_cmds *)malloc(sizeof(t_cmds));
	if (!newnode)
		ft_puterror();
	newnode->command = cmd;
	newnode->cmd_args = cmd_args;
	newnode->heredocs = heredocs;
	newnode->next = NULL;
	return (newnode);
}

// Func to find the last node
t_cmds	*ft_last(t_cmds *lst)
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

// Func to find almost last
t_cmds	*ft_prevlast(t_cmds *lst)
{
	t_cmds	*last;

	last = ft_last(lst);
	if (lst == NULL)
		return (0);
	while (lst)
	{
		if (lst->next == last)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

// Func to find almost last
t_cmds	*ft_second(t_cmds *lst)
{
	t_cmds	*second;

	if (lst == NULL)
		return (0);
	second = lst->next;
	return (second);
}
