/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:14:38 by gacalaza          #+#    #+#             */
/*   Updated: 2023/11/07 23:12:42 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	has_d_redirec_p(t_token *tokens)
{
	t_token	*temp;
	int		r_rdrcts;

	temp = tokens;
	r_rdrcts = 0;
	while (temp)
	{
		if (temp->type == HEREDOC || temp->type == APPEND)
			r_rdrcts++;
		if (temp->type == PIPE)
			break ;
		temp = temp->next;
	}
	return (r_rdrcts);
}

int	nb_words(t_token *tokens)
{
	t_token	*temp;
	int		words;

	temp = tokens;
	words = 0;
	while (temp)
	{
		if (temp->type == WORD)
			words++;
		if (temp->type == PIPE)
			break ;
		temp = temp->next;
	}
	return (words);
}

// char	**get_words(t_token *tokens)
// {
// 	t_token	*temp;
// 	int		nb_words;

// 	temp = tokens;
// 	nb_words = 0;
// 	while (temp)
// 	{

// 	}
// }
