/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:42:19 by gacalaza          #+#    #+#             */
/*   Updated: 2023/11/02 21:19:08 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// void	move_token_cont(t_data *data, t_token *newlist)
// {
// 	t_token	*head;

// 	head = data->tokens;
// 	while (head->next != NULL)
// 	{
// 		if (head->type != REDIRECT_IN && head->type != REDIRECT_OUT)
// 			head = head->next;
// 		else
// 			break ;
// 	}
// 	head->next = newlist;
// 	data->tokens = head;
// }

// t_token	*jump_word(t_token *tokens)
// {
// 	t_token	*tmp;

// 	tmp = tokens;
// 	if (is_path(tokens))
// 	{
// 		if (tmp->next)
// 			tmp = tmp->next;
// 		while (tmp)
// 		{
// 			if (tmp->type != SLASH && tmp->type != WORD)
// 				break ;
// 			tmp = tmp->next;
// 		}
// 		return (tmp);
// 	}
// 	return (tmp);
// }

// void	process_rdct_move(t_data *data, t_token *tmp, t_token *prev, int type)
// {
// 	t_token	*temp;

// 	temp = data->tokens;
// 	while (tmp)
// 	{
// 		if (tmp->type == C_SPACE || tmp->type == H_TAB)
// 		{
// 			while (tmp->type == C_SPACE || temp->type == H_TAB)
// 				tmp = tmp->next;
// 		}
// 		if (tmp->type == QUOTED_WORD)
// 		{
// 			tmp = tmp->next;
// 		}
// 		if (tmp->type == WORD || tmp->type == SLASH)
// 		{
// 			tmp = jump_word(tmp);
// 		}
// 	}
// 	ft_error_redirect(5);
// }

// void	check_move(t_data *data, t_token *tmp, t_token *prev, int type)
// {
// 	if (type == REDIRECT_IN || type == REDIRECT_OUT)
// 		process_rdct_move(data, tmp, prev, type);
// }

// void	move_tokens(t_data *data, int type)
// {
// 	t_token	*tmp;
// 	t_token	*prev;

// 	tmp = data->tokens;
// 	prev = data->tokens;
// 	if (!tmp)
// 		return ;
// 	tmp = jump_white_spaces(tmp);
// 	while(tmp)
// 	{
// 		if (tmp->type == type)
// 			check_move(data, tmp, prev, type);
// 		tmp = tmp->next;
// 		prev = tmp->prev;
// 	}
// }

// data->cmd_args = take_q_name(&*tmp);
void	parsing_it(t_data *data)
{
	t_token	*tmp;

	tmp = data->tokens;
	if (tmp->type == WORD && tmp->next->type == QUOTED_WORD)
	{
		data->cmd = &tmp->token;
		tmp = tmp->next;
	}
}
