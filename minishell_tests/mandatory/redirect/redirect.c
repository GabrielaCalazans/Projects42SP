/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:08:47 by gacalaza          #+#    #+#             */
/*   Updated: 2023/10/17 21:39:06 by gacalaza         ###   ########.fr       */
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

int	check_file_name(t_token *tokens)
{
	t_token	*temp;
	int		check;

	temp = tokens;
	check = 0;
	while (temp)
	{
		if (temp->type == M_SPACE || temp->type == H_TAB)
		{
			while (temp->type == M_SPACE || temp->type == H_TAB)
				temp = temp->next;
		}
		if (is_syntax_error(temp->type) && temp->type != 11)
		{
			ft_error(1);
			check = 1;
		}
		if (temp->type == WORD)
			break ;
		temp = temp->next;
	}
	return (check);
}

void	find_file_name(t_token *tokens)
{	
	t_token	*temp;

	temp = tokens;
	if (check_file_name(tokens))
		return ;
	while (temp)
	{
		if (temp->type == M_SPACE || temp->type == H_TAB)
		{
			while (temp->type == M_SPACE || temp->type == H_TAB)
				temp = temp->next;
		}
		if (temp->type == QUOTE_DOUBLE || QUOTE_SINGLE)
			(take_quoted_name(temp, has_another_quote(temp, temp->type)));
		if (temp->type == WORD)
			return (ft_strdup(temp->token));
		temp = temp->next;
	}
	return (NULL);
}

char	*take_quoted_name(t_token *tokens, int len)
{
	t_token	*temp;
	char	*name;
	int		i;
	int		word_size;

	temp = tokens;
	i = 0;
	word_size = 0;
	if (!has_another_quote(tokens, tokens->type))
	{
		ft_error(2);
		return (NULL);
	}
	while (len > i && temp)
	{
		word_size += ft_strlen(temp->token);
		temp->next;
		i++;
	}
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