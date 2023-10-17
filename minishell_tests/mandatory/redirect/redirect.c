/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:08:47 by gacalaza          #+#    #+#             */
/*   Updated: 2023/10/16 20:01:40 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// int	find_type_redirect(char c)
// {
// }

t_token *jump_white_spaces(t_token *tokens)
{
	if (tokens->type == M_SPACE || tokens->type == H_TAB)
	{
		while (tokens->type == M_SPACE || tokens->type == H_TAB)
			tokens = tokens->next;
	}
	return (tokens);
}

void	find_file_name(t_token *tokens)
{	
	t_token	*temp;

	temp = tokens;
	check_file_name(tokens);

	while (temp)
	{
		if (temp->type == M_SPACE || temp->type == H_TAB)
		{
			while (temp->type == M_SPACE || temp->type == H_TAB)
				temp = temp->next;
		}
		temp = temp->next;
	}
}

void	check_file_name(t_token *tokens)
{
	t_token	*temp;

	temp = tokens;
	while (temp)
	{
		if (temp->type == M_SPACE || temp->type == H_TAB)
		{
			while (temp->type == M_SPACE || temp->type == H_TAB)
				temp = temp->next;
		}
		if (is_syntax_error(temp->type) && temp->type != 11)
			ft_error(1);
		if (temp->type == WORD)
			break ;
		temp = temp->next;
	}
}

void	check_quoted(t_token *tokens, int type)
{
	t_token	*temp;

	temp = tokens;
	if (!has_another_quote(tokens, type))
		ft_error(2);
	else
		take_quoted(tokens, has_another_quote(tokens, type));
}

char	*take_quoted(t_token *tokens, int len)
{
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
			printf("achei 2ª");
			return (len);
		}
		len++;
		temp = temp->next;
	}
	return (0);
}

// void	redirect_lst(t_token *tokens)
// {
// }