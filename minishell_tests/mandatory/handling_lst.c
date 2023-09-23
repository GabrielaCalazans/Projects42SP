/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:12:33 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/23 15:09:04 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Func to create a new node
t_token	*createnode(char *token, char *type)
{
	t_token	*newnode;

	newnode = (t_token *)malloc(sizeof(t_token));
	if (!newnode)
		ft_puterror();
	newnode->token = token;
	newnode->type = type;
	newnode->next = NULL;
	return (newnode);
}

// Func to find the last node
t_token	*ft_last(t_token *lst)
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

void	sub_starting(t_token **tokens, char **str, int i)
{
	t_token	*newnode;
	int		index;
	int		nbr;
	int		j;

	j = i;
	nbr = ft_atoi_error(str[i]);
	index = find_index(str, nbr, j);
	*a = createnode(nbr, index);
	while (str[++i] != NULL)
	{
		nbr = ft_atoi_error(str[i]);
		index = find_index(str, nbr, j);
		newnode = createnode(nbr, index);
		if (!newnode)
			break ;
		ft_add_back(a, newnode);
	}
}

t_token	*starting(t_token **tokens, int argc, char *argv[])
{
	int		i;
	char	**str;

	if (argc == 2)
	{
		i = 0;
		str = ft_split(argv[1], 32);
	}
	else
	{
		i = 1;
		str = argv;
	}
	if (!ft_checkdup(str, i))
		ft_puterror();
	sub_starting(a, str, i);
	if (argc == 2)
		ft_freearray(str);
	return (*a);
}
