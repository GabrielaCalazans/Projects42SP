/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:08:47 by gacalaza          #+#    #+#             */
/*   Updated: 2023/10/28 17:41:42 by gacalaza         ###   ########.fr       */
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

void	sub_create_redirect_lst(t_data *data, t_token *token)
{
	int		*redirects;
	int		redirect_type;
	char	**files;
	char	*file_name;
	t_rdct	*newnode;

	redirect_type = token->type;
	file_name = find_file_name(token->next);
	redirects = malloc(sizeof(int));
	files = malloc(sizeof(char *));
	redirects[0] = redirect_type;
	files[0] = file_name;
	newnode = createnode_rdct(find_file_name(token->next), token->type);
	ft_add_back_rdct(&data->rdct, newnode);
}

void	create_redirect_lst(t_data *data)
{
	t_token	*temp;

	if (first_check(data->tokens))
	{
		ft_error_redirect(C_ERROR);
		return ;
	}
	temp = data->tokens;
	while (temp)
	{
		if (temp->type == REDIRECT_IN || temp->type == REDIRECT_OUT)
			sub_create_redirect_lst(data, &*temp);
		temp = temp->next;
	}
	printlist(data->rdct, 2);
}

// void	sub_create_redirect_lst(t_data *data, t_token *token)
// {
// 	int redirect_type = token->type;
// 	char *file_name = find_file_name(token->next);
// 	int *redirects = malloc(sizeof(int));
// 	char **files = malloc(sizeof(char *));

// 	redirects[0] = redirect_type;
// 	files[0] = file_name;
	
// 	t_rdct *newnode = createnode_rdct(redirects, 1, files);
// 	ft_add_back_rdct(&data->rdct, newnode);
// }

// void create_redirect_lst(t_data *data)
// {
// 	t_token *temp;

// 	if (first_check(data->tokens))
// 	{
// 		ft_error_redirect(C_ERROR);
// 		return;
// 	}
// 	temp = data->tokens;
// 	int inside_pipe = 0;
// 	int current_pipe_redirects = 0;
// 	int *redirects = NULL;
// 	char **files = NULL;
// 	while (temp)
// 	{
// 		if (temp->type == PIPE)
// 		{
// 			inside_pipe = 1;
// 			if (current_pipe_redirects > 0)
// 			{
// 				// Move the redirects to a new node and add it to the list
// 				t_rdct *newnode = createnode_rdct(redirects, current_pipe_redirects, files);
// 				ft_add_back_rdct(&data->rdct, newnode);
// 				free(redirects);
// 				free(files);
// 				redirects = NULL;
// 				files = NULL;
// 				current_pipe_redirects = 0;
// 			}
// 		}
// 		else if (temp->type == REDIRECT_IN || temp->type == REDIRECT_OUT)
// 		{
// 			if (inside_pipe)
// 			{
// 				// Add the redirect to the current pipe's list
// 				current_pipe_redirects++;
// 				redirects = realloc(redirects, current_pipe_redirects * sizeof(int));
// 				files = realloc(files, current_pipe_redirects * sizeof(char *));
// 				redirects[current_pipe_redirects - 1] = temp->type;
// 				files[current_pipe_redirects - 1] = find_file_name(temp->next);
// 			}
// 			else
// 			{
// 				// Add the redirect as a single-node list
// 				sub_create_redirect_lst(data, &*temp);
// 			}
// 		}
// 		temp = temp->next;
// 	}
// 	if (current_pipe_redirects > 0)
// 	{
// 		// Add any remaining redirects to the list
// 		t_rdct *newnode = createnode_rdct(redirects, current_pipe_redirects, files);
// 		ft_add_back_rdct(&data->rdct, newnode);
// 		free(redirects);
// 		free(files);
// 	}
// 	printlist(data->rdct, 2);
// }
