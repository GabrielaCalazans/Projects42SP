/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:42:19 by gacalaza          #+#    #+#             */
/*   Updated: 2023/10/26 16:54:51 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	move_token(t_data *data)
{
	int	i;

	i = 0;
	data->tokens = data->tokens->next;
	data->tokens = jump_white_spaces(data->tokens);
	if (data->tokens->type == QUOTE_DOUBLE || data->tokens->type == QUOTE_SINGLE)
	{
		if (has_another_quote(data->tokens, data->tokens->type))
		{
			while (i < has_another_quote(data->tokens, data->tokens->type))
				data->tokens = data->tokens->next;
		}
	}
	if (data->tokens->type == WORD)
	{
		if (is_path(data->tokens))
		{
			while (data->tokens->type == SLASH && data->tokens->type == WORD)
				data->tokens = data->tokens->next;
		}
	}
}

void	parsing_it(t_data *data)
{
	t_token	*temp;

	temp = data->tokens;
	data->cmd = ft_split(data->prompt_in, ' ');
	return ;
	while (temp)
	{
		
	}
}

// char	*find_cmd(t_data *data)
// {
// }