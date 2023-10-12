/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:08:47 by gacalaza          #+#    #+#             */
/*   Updated: 2023/10/12 20:40:49 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// int	find_type_redirect(char c)
// {
// }

void	error(int error)
{
	if (error == 1)
		printf("syntax error");
	else
		printf("undefined error");
}

int	is_syntax_error(int type)
{
	if (type == 1 || type == 2)
		return (1);
	if (type == 3 || type == 12 || type == 13)
		return (1);
	if (type == 16 || type == 17 || type == 18)
		return (1);
	return (0);
}

int	is_possible_error(int type)
{
	if (type == 19 || type == 21)
		return (1);
	if (type == 5 || type == 20 || type == 15)
		return (1);
	return (0);
}

int	check_error(t_token *tokens)
{
	t_token *current;
	t_token *next;

	current = tokens;
	next = tokens->next;
	if (tokens->type == 1 || type == 2)
		return (1);
	if (type == 3 || type == 12 || type == 13)
		return (1);
	if (type == 16 || type == 17)
		return (1);
	return (0);
}

void	find_file_name(t_token *tokens)
{	
	t_token	*temp;

	temp = tokens;
	while (temp)
	{
		if (temp->type == 11)
		{
			while (temp->type == 11)
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
		if (temp->type == 11)
		{
			while (temp->type == 11)
				temp = temp->next;
		}
		if (is_syntax_error(temp->type) && temp->type != 11)
			error(1);
		
		temp = temp->next;
	}
}

void	check_quoted(t_token *tokens, int type)
{
	t_token	*temp;

	temp = tokens;
	if (!has_another_quote(tokens, type))
		error(2);
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