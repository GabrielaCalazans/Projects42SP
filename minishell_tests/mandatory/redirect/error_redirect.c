/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:31:51 by gacalaza          #+#    #+#             */
/*   Updated: 2023/10/16 19:54:21 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_error(int error)
{
	if (error == 1)
		printf("syntax error");
	else
		printf("undefined error");
}

int	is_syntax_error(int type)
{
	if (type == REDIRECT_IN || type == REDIRECT_OUT)
		return (M_ERROR);
	if (type == PIPE || type == APPEND || type == HEREDOC)
		return (M_ERROR);
	return (0);
}

int	is_possible_error(int type)
{
	if (type == DOT || type == SLASH)
		return (M_ERROR);
	if (type == TILDE || type == BACKSLASH || type == ASTERISK)
		return (M_ERROR);
	return (0);
}

int	check_error(t_token *tokens)
{
	int		current;
	t_token	*temp;

	current = tokens->type;
	temp = tokens->next;
	while (temp)
	{
		if (temp->type == M_SPACE || temp->type == H_TAB)
			temp = jump_white_spaces(temp);
		if (temp->type == DOT)
			return (dot_case(temp));
		if (temp->type == TILDE )
			return (tilde_case(temp));
		if (temp->type == ASTERISK)
			return (asterick_case(temp));
		temp = temp->next;
	}
	return (0);
}

// TODO: VALIDATE THE PATH TO '> ./bla/bla.txt' case
int	dot_case(t_token *tokens)
{
	if (tokens->next == M_SPACE || tokens->next == NULL)
		return (M_ERROR);
	if (tokens->next == SLASH)
		return (validate_path(tokens));
	if (tokens->next != WORD)
		return (M_ERROR);
	return (0);
}

int	tilde_case(t_token *tokens)
{
	if (tokens->next != WORD)
		return (M_ERROR);
	return (0);
}

int	asterick_case(t_token *tokens)
{
	if (tokens->next != WORD)
		return (M_ERROR);
	return (0);
}

t_token *jump_white_spaces(t_token *tokens)
{
	if (tokens->type == M_SPACE || tokens->type == H_TAB)
	{
		while (tokens->type == M_SPACE || tokens->type == H_TAB)
			tokens = tokens->next;
	}
	return (tokens);
}
