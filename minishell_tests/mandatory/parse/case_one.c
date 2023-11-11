/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:35:31 by gacalaza          #+#    #+#             */
/*   Updated: 2023/11/11 17:57:27 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// fun to jump redirect's file name
t_token	*move_one(t_token *tokens)
{
	t_token	*tmp;

	tmp = jump_white_spaces(tokens);
	while (tmp && tmp->type != PIPE)
	{
		printf("MOVE\ttoken: %s\n", tmp->token);
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

		// if (!is_rd_case(tmp->type) && !is_word(tmp->type, 2))
		// 	tmp = tmp->next;
int	nb_words_r(t_token *tokens)
{
	t_token	*tmp;
	int		words;

	tmp = tokens;
	words = 0;
	printf("HERE\tnb: %i\n", words);
	while (tmp && tmp->type != PIPE)
	{
		printf("HERE antes\tnb: %i\n", words);
		tmp = jump_white_spaces(tmp);
		if (is_word(tmp->type, 2))
			words++;
		if (is_rd_case(tmp->type))
			tmp = move_one(tmp->next);
		else
		{
			if (tmp->next)
				tmp = tmp->next;
			else
				break ;
		}
		printf("HERE depois\tnb: %i\n", words);
	}
	return (words);
}

		// if (!is_rd_case(tmp->type) && !is_word(tmp->type, 2))
		// 	tmp = tmp->next;
char	**get_words_one(t_token *tokens)
{
	t_token	*tmp;
	int		i;
	char	**words;

	i = 0;
	tmp = tokens;
	words = malloc(sizeof(char **) * (nb_words_r(tokens) + 1));
	if (!words)
		ft_error_parse(1);
	while (tmp && tmp->type != PIPE)
	{
		if (is_word(tmp->type, 2))
			words[i++] = ft_strdup(tmp->token);
		if (is_rd_case(tmp->type))
			tmp = move_one(tmp->next);
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
