/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:10:45 by gacalaza          #+#    #+#             */
/*   Updated: 2023/10/18 21:23:03 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*jump_white_spaces(t_token *tokens)
{
	if (tokens->type == M_SPACE || tokens->type == H_TAB)
	{
		while (tokens->type == M_SPACE || tokens->type == H_TAB)
			tokens = tokens->next;
	}
	return (tokens);
}

int	has_another_quote(t_token *tokens, int type)
{
	t_token	*temp;
	int		len;

	temp = tokens->next;
	len = 0;
	while (temp)
	{
		if (temp->type == type)
		{
			printf("achei 2ª quote len:%d\n", len);
			return (len);
		}
		len++;
		temp = temp->next;
	}
	return (0);
}

int	has_redirect(t_token *tokens)
{
	t_token	*temp;
	int		redirects;

	temp = tokens;
	redirects = 0;
	while (temp)
	{
		if (temp->type == 1 || temp->type == 2)
			redirects++;
		temp = temp->next;
	}
	return (redirects);
}
