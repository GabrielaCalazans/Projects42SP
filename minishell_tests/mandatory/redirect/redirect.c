/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:08:47 by gacalaza          #+#    #+#             */
/*   Updated: 2023/11/01 21:27:31 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

void	sub_create_redirect_lst(t_data *data, char **files, int *redirects, int len)
{
	t_rdct	*newnode;

	newnode = createnode_rdct(files, redirects, len);
	ft_add_back_rdct(&data->rdct, newnode);
}

int	has_pipe_yet(t_token *tokens)
{
	t_token	*tmp;
	int		check;

	tmp = tokens;
	check = 0;
	while (tmp)
	{
		if (tmp->type == PIPE)
			check++;
		tmp = tmp->next;
	}
	return (check);
}

int	has_rdct_yet(t_token *tokens)
{
	t_token	*tmp;
	int		check;

	tmp = tokens;
	check = 0;
	while (tmp)
	{
		if (tmp->type == REDIRECT_IN || tmp->type == REDIRECT_OUT)
			check++;
		if (tmp->type == PIPE)
			break ;
		tmp = tmp->next;
	}
	return (check);
}

void	create_redirect_lst(t_data *data)
{
	t_token	*temp;
	char	**files;
	int		*redirects;
	int		inside_pipe;
	int		len;
	int		i;

	i = 0;
	inside_pipe = 0;
	redirects = NULL;
	files = NULL;
	if (first_check(data->tokens))
	{
		ft_error_redirect(C_ERROR);
		return ;
	}
	temp = data->tokens;
	len = has_rdct_yet(temp);
	while (temp)
	{
		if ((temp->type == PIPE || !has_pipe_yet(temp)) && !has_rdct_yet(temp))
		{
			files[i] = NULL;
			sub_create_redirect_lst(data, files, redirects, len);
			inside_pipe = 1;
		}
		if (inside_pipe == 1)
		{
			if (len > 0)
				files = freearray(files);
			free(redirects);
			redirects = NULL;
			files = NULL;
			len = has_rdct_yet(temp->next);
			if (len < 1)
				break ;
			i = 0;
			inside_pipe = 0;
		}
		if (temp->type == REDIRECT_IN || temp->type == REDIRECT_OUT)
		{
			if (inside_pipe == 0)
			{
				redirects = malloc(sizeof (int) * (len + 1));
				files = malloc(sizeof (char **) * (len + 1));
				if (!redirects || !files)
				{
					printf("Error malloc: create_redirect_lst 1");
					return ;
				}
				inside_pipe = 3;
			}
			if (i < len)
			{
				redirects[i] = temp->type;
				files[i] = find_file_name(temp->next);
				i++;
			}
		}
		temp = temp->next;
	}
	if (redirects)
		free(redirects);
	if (files)
		files = freearray(files);
	printlist(data->rdct, 2);
}
