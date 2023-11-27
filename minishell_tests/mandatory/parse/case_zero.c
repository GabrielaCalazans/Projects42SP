/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:06:03 by gacalaza          #+#    #+#             */
/*   Updated: 2023/11/26 22:13:15 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	nb_words(t_token *tokens)
{
	t_token	*tmp;
	int		words;

	tmp = tokens;
	words = 0;
	while (tmp && tmp->type != PIPE)
	{
		// if (flag_case(tmp) > 0)
		// 	words = 1;
		if (is_word(tmp->type, 2))
			words++;
		tmp = tmp->next;
	}
	return (words);
}

int	flag_case(t_token *tokens)
{
	t_token	*tmp;
	int		flags;

	flags = 0;
	tmp = tokens;
	while(tmp && tmp->type == FLAG)
	{
		flags++;
		tmp = tmp->next;
	}
	return(flags);
}

char	*flag_process(t_token *tokens)
{
	t_token	*tmp;
	char	*flags;

	tmp = tokens->next;
	flags = ft_strdup(tokens->token);
	while (tmp && tmp->type == FLAG)
	{
		flags = ft_strjoin(flags, tmp->token);
		if (tmp->next && tmp->next->type == FLAG)
			flags = ft_strjoin(flags, " ");
		tmp = tokens->next;
	}
	return (flags);
}

char	**get_words(t_token *tokens, int len)
{
	t_token	*tmp;
	int		i;
	char	**words;

	i = 0;
	tmp = tokens;
	// printf("len:%i\n", len);
	words = ft_calloc((len + 1), sizeof(char *));
	if (!words)
		ft_error_parse(1);
	while (tmp && tmp->type != PIPE)
	{
		// printf("token:%s[%i] type:%i\n", tmp->token, i, tmp->type);
		if (i == 0 && tmp->type == 10)
		{
			words[i] = ft_strdup(tmp->token);
			// printf("DENTRO word[%i]: %s\n", i, words[i]);
			i++;
		}
		// else if (tmp->type == FLAG && i > 0 && flag_case(tmp) > 1)
		// {
		// 	printf("word[%i]: %s\n", 0, words[0]);
		// 	printf("ENTREI FLAG%i\n", i);
		// 	words[i] = flag_process(tmp);
		// 	while (flag_case(tmp) > 0)
		// 		tmp = tmp->next;
		// 	i++;
		// }
		else if (is_word(tmp->type, 2) && i != 0)
		{
			// printf("word[%i]: %s\n", 0, words[0]);
			// printf("ENTREI%i\n", i);
			if (tmp->type == QUOTED_WORD)
			{
				printf("ENTREI\n");
				words[i] = trim_process(tmp->token, find_type(tmp->token));
			}
			else
			{
				printf("ENTREI 2\n");
				words[i] = ft_strdup(tmp->token);
			}
			i++;
		}
		tmp = tmp->next;
	}
	words[i] = NULL;
	// printf("SAINDO zero\n");
	return (words);
}
