/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_drandwords.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:05:41 by gacalaza          #+#    #+#             */
/*   Updated: 2023/11/09 22:14:59 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// fun to jump double redirect's file name
t_token	*move_drd(t_token *tokens)
{
	t_token	*tmp;

	tmp = jump_white_spaces(tokens);
	while (tmp && tmp->type != PIPE)
	{
		if (tmp->type == QUOTED_WORD)
		{
			if (tmp->next)
				tmp = tmp->next;
			else
				return (NULL);
		}
		if (tmp->type != WORD && tmp->type != SLASH
			&& is_special_case(tmp->type, 3))
			break ;
		if (tmp->next)
			tmp = tmp->next;
		else
			return (NULL);
	}
	return (tmp);
}

int	nb_words_dr(t_token *tokens)
{
	t_token	*tmp;
	int		words;

	tmp = tokens;
	words = 0;
	while (tmp && tmp->type != PIPE)
	{
		tmp = jump_white_spaces(tmp);
		if (is_word(tmp->type, 2))
			words++;
		if (is_drd_case(tmp->type))
			tmp = move_drd(tmp->next);
		else
		{
			if (tmp->next)
				tmp = tmp->next;
			else
				break ;
		}
	}
	return (words);
}

char	**get_words_dr(t_token *tokens)
{
	t_token	*tmp;
	int		i;
	char	**words;

	i = 0;
	tmp = tokens;
	words = malloc(sizeof(char **) * (nb_words_dr(tokens) + 1));
	if (!words)
		ft_error_parse(1);
	while (tmp && tmp->type != PIPE)
	{
		if (is_word(tmp->type, 2))
			words[i++] = ft_strdup(tmp->token);
		if (is_drd_case(tmp->type))
			tmp = move_drd(tmp->next);
		else
		{
			if (tmp->next)
				tmp = tmp->next;
			else
				break ;
		}
	}
	words[i] = NULL;
	return (words);
}
