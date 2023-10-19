/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:08:47 by gacalaza          #+#    #+#             */
/*   Updated: 2023/10/18 21:30:26 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_file_name(t_token *tokens)
{
	t_token	*temp;
	int		check;

	temp = tokens;
	check = 0;
	if (tokens == NULL)
		return (M_ERROR);
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

int	first_check(t_token *tokens)
{
	t_token	*temp;
	int		check;

	temp = tokens;
	check = 0;
	while (temp)
	{
		if (temp->type == 1 || temp->type == 2)
			check += check_file_name(temp->next);
		temp = temp->next;
	}
	return (check);
}

char	*take_quoted_name(t_token *tokens, int len)
{
	t_token	*temp;
	char	*name;
	int		i;
	int		word_size;
	int		check;

	temp = tokens->next;
	i = 0;
	word_size = 0;
	check = 0;
	if (!has_another_quote(tokens, tokens->type))
	{
		ft_error(2);
		return (NULL);
	}
	while (len > i && temp)
	{
		if (temp->type == QUOTE_DOUBLE || temp->type == QUOTE_SINGLE)
			break ;
		word_size += ft_strlen(temp->token);
		temp = temp->next;
		i++;
	}
	printf("word_size: %d\n", word_size);
	if (word_size > 0)
		name = ft_strdup(tokens->token);
	temp = tokens->next;
	i = 0;
	while (len > i && temp)
	{
		if (temp->type == QUOTE_DOUBLE || temp->type == QUOTE_SINGLE)
			break ;
		ft_strjoin(name, temp->token);
		temp = temp->next;
		i++;
	}
	check = ft_strlen(name) - word_size;
	printf("size word - len name: %d\n", check);
	return (name);
}

char	*find_file_name(t_token *tokens)
{	
	t_token	*temp;

	temp = tokens;
	if (check_file_name(tokens))
	{
		printf("Deu ruim no check_file_name\n");
		return (NULL);
	}
	while (temp)
	{
		if (temp->type == M_SPACE || temp->type == H_TAB)
		{
			while (temp->type == M_SPACE || temp->type == H_TAB)
				temp = temp->next;
		}
		if (temp->type == QUOTE_DOUBLE || temp->type == QUOTE_SINGLE)
			return (take_quoted_name(temp, has_another_quote(temp, temp->type)));
		if (temp->type == WORD)
			return (ft_strdup(temp->token));
		temp = temp->next;
	}
	printf("Chegou aqui deu ruim");
	return (NULL);
}

void	sub_create_redirect_lst(t_data *data, t_token *token)
{
	t_rdct	*newnode;

	newnode = createnode_rdct(find_file_name(token->next), token->type);
	ft_add_back_rdct(&data->rdct, newnode);
}

void	create_redirect_lst(t_data *data, int len)
{
	t_token	*temp;

	if (first_check(data->tokens))
	{
		ft_error(first_check(data->tokens));
		return ;
	}
		
	temp = data->tokens;
	while (temp)
	{
		if (temp->type == 1 || temp->type == 2)
			sub_create_redirect_lst(data, &*temp);
		temp = temp->next;
	}
	printf("len: %d size: %d\n",len, ft_size_rdct(data->rdct));
	printlist(data->rdct, 2);
}
