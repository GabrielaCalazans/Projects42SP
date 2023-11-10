/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:14:38 by gacalaza          #+#    #+#             */
/*   Updated: 2023/11/09 22:09:24 by gacalaza         ###   ########.fr       */
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

void	*ft_error_parse(int error)
{
	if (error == 1)
		printf("erro malloc\n");
	else if (error == 2)
		printf("DEU RUIM.\n");
	else if (error == 3)
		printf("ELSE\n");
	else if (error == 4)
		printf("ELSE\n");
	else
	{
		printf("undefined error\n");
	}
	return (NULL);
}

int	is_rd_case(int type)
{
	if (type == REDIRECT_IN)
		return (TRUE);
	if (type == REDIRECT_OUT)
		return (TRUE);
	return (FALSE);
}

int	is_drd_case(int type)
{
	if (type == HEREDOC)
		return (TRUE);
	if (type == APPEND)
		return (TRUE);
	return (FALSE);
}

int	is_word(int type, int check)
{
	if (check == 1)
	{
		if (type == WORD)
			return (TRUE);
		if (type == QUOTED_WORD)
			return (TRUE);
	}
	if (check == 2)
	{
		if (type == WORD)
			return (TRUE);
		if (type == QUOTED_WORD)
			return (TRUE);
		if (!is_special_case(type, 3))
			return (TRUE);
	}
	return (FALSE);
}
