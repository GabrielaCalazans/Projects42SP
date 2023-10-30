/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:42:19 by gacalaza          #+#    #+#             */
/*   Updated: 2023/10/30 19:06:13 by gacalaza         ###   ########.fr       */
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

// void	move_token(t_data *data)
// {
// 	int	type;
// 	t_token	*tmp;

// 	tmp = data->tokens->next;
// 	if (!tmp)
// 		return ;
// 	tmp = jump_white_spaces(tmp);
// 	type = 0;
// 	if (tmp->type == QUOTE_DOUBLE || tmp->type == QUOTE_SINGLE)
// 	{
// 		type = tmp->type;
// 		if (has_another_quote(tmp, type))
// 		{
// 			while (has_another_quote(tmp, type) > 0)
// 				tmp = tmp->next;
// 			if (tmp->type == type)
// 				tmp = tmp->next;
// 		}
// 	}
// 	else if (tmp->type  == WORD || tmp->type == SLASH)
// 	{
// 		if (is_path(tmp))
// 		{
// 			while (tmp)
// 			{
// 				if (tmp->type != SLASH && tmp->type != WORD)
// 					break ;
// 				tmp = tmp->next;
// 			}
// 		}
// 	}
// 	move_token_cont(data, tmp);
// }

void	parsing_it(t_data *data)
{
	t_token	*tmp;

	tmp = data->tokens;
	if (tmp->type == WORD && tmp->next->type == QUOTED_WORD)
	{
		data->cmd = &tmp->token;
		tmp = tmp->next;
		// data->cmd_args = take_q_name(&*tmp);
		tmp = tmp->next;
	}
}
