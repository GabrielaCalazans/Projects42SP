/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:08:47 by gacalaza          #+#    #+#             */
/*   Updated: 2023/10/30 19:01:07 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*take_quoted_name(t_token *tokens, int len)
{
	char	*name;
	t_token	*temp;
	size_t	word_size;

	temp = tokens->next;
	if (!has_another_quote(tokens, tokens->type))
	{
		ft_error_redirect(2);
		return (NULL);
	}
	word_size = quoted_word_size(temp, len);
	name = ft_strdup(temp->token);
	name = get_name_quoted(temp, name, len);
	if (ft_strlen(name) != word_size)
	{
		ft_error_redirect(3);
		return (NULL);
	}
	return (name);
}

char	*take_q_name(t_token *tokens)
{
	int		type;
	char	*name;

	type = find_type(tokens->token);
	name = ft_strdup(tokens->token);
	if (type == QUOTE_DOUBLE)
		name  = ft_strtrim(name, "\"");
	if (type == QUOTE_SINGLE)
		name  = ft_strtrim(name, "\'");
	return (name);
}

char	*find_file_name(t_token *tokens)
{	
	t_token	*temp;

	temp = tokens;
	if (check_file_name(tokens))
	{
		ft_error_redirect(4);
		return (NULL);
	}
	while (temp)
	{
		if (temp->type == C_SPACE || temp->type == H_TAB)
		{
			while (temp->type == C_SPACE || temp->type == H_TAB)
				temp = temp->next;
		}
		if (temp->type == QUOTED_WORD)
			return (take_q_name(temp));
		if (temp->type == WORD || temp->type == SLASH)
			return (word_case(temp));
		temp = temp->next;
	}
	ft_error_redirect(4);
	return (NULL);
}

// void	sub_create_redirect_lst(t_data *data, t_token *token)
// {
// 	t_rdct	*newnode;

// 	newnode = createnode_rdct(find_file_name(token->next), token->type);
// 	ft_add_back_rdct(&data->rdct, newnode);
// }

// void	create_redirect_lst(t_data *data)
// {
// 	t_token	*temp;

// 	if (first_check(data->tokens))
// 	{
// 		ft_error_redirect(C_ERROR);
// 		return ;
// 	}
// 	temp = data->tokens;
// 	while (temp)
// 	{
// 		if (temp->type == REDIRECT_IN || temp->type == REDIRECT_OUT)
// 			sub_create_redirect_lst(data, &*temp);
// 		temp = temp->next;
// 	}
// 	printlist(data->rdct, 2);
// }

int	has_redirect_pipe(t_token *tokens)
{
	t_token	*temp;
	int		redirects;

	temp = tokens;
	redirects = 0;
	while (temp)
	{
		if (temp->type == 1 || temp->type == 2)
			redirects++;
		if (temp->type == PIPE)
			break ;
		temp = temp->next;
	}
	return (redirects);
}

void	sub_create_redirect_lst(t_data *data, char **files, int *redirects, int len)
{
	t_rdct	*newnode;

	newnode = createnode_rdct(files, redirects, len);
	ft_add_back_rdct(&data->rdct, newnode);
}

void	create_redirect_lst(t_data *data)
{
	t_token	*temp;
	char	**files;
	int		*redirects;
	int		inside_pipe;
	int		len;

	if (first_check(data->tokens))
	{
		ft_error_redirect(C_ERROR);
		return ;
	}
	temp = data->tokens;
	len = 0;
	inside_pipe = 0;
	redirects = malloc(sizeof (int) * (has_redirect_pipe(data->tokens) + 1));
	files = malloc(sizeof (char *) * (has_redirect_pipe(data->tokens) + 1));
	while (temp)
	{
		if (temp->type == PIPE)
		{
			// Move the redirects to a new node and add it to the list
			inside_pipe = 1;
			files[len] = NULL;
			len = 0;
			sub_create_redirect_lst(data, files, redirects, len);
		}
		else if (temp->type == REDIRECT_IN || temp->type == REDIRECT_OUT)
		{
			// Add the redirect to the current pipe's list
			redirects[len] = temp->type;
			files[len] = find_file_name(&*temp);
			len++;
		}
		if (inside_pipe)
		{
			free(files);
			free(redirects);
			if (temp->next)
			{
				redirects = malloc(sizeof (int) * (has_redirect_pipe(temp->next) + 1));
				files = malloc(sizeof (char *) * (has_redirect_pipe(temp->next) + 1));
			}
			inside_pipe = 0;
		}
		temp = temp->next;
	}
	printlist(data->rdct, 2);
}
