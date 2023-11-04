/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:10:45 by gacalaza          #+#    #+#             */
/*   Updated: 2023/11/03 15:11:17 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*jump_white_spaces(t_token *tokens)
{
	if (tokens == NULL)
		return (NULL);
	if (tokens->type == C_SPACE || tokens->type == H_TAB)
	{
		while (tokens->type == C_SPACE || tokens->type == H_TAB)
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
			return (len);
		len++;
		temp = temp->next;
	}
	return (FALSE);
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

int	is_path(t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens;
	if (tmp->next)
	{
		if (tmp->type == SLASH && tmp->next->type == WORD)
			return (TRUE);
		if (tmp->token[0] == '.' && tmp->next->type == SLASH)
		{
			tmp = tmp->next;
			if (tmp->next->type == WORD)
				return (TRUE);
		}
		tmp = tokens;
		if (tmp->type == WORD && tmp->next->type == SLASH)
			return (TRUE);
	}
	return (FALSE);
}

char	*word_case(t_token *tokens)
{
	t_token	*tmp;
	char	*result;

	tmp = tokens;
	if (is_path(tokens))
	{
		result = ft_strdup(tmp->token);
		if (tmp->next)
			tmp = tmp->next;
		while (tmp)
		{
			if (tmp->type != SLASH && tmp->type != WORD)
				break ;
			result = ft_strjoin(result, tmp->token);
			tmp = tmp->next;
		}
		return (result);
	}
	return (ft_strdup(tokens->token));
}
