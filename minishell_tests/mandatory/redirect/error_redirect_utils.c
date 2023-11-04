/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_redirect_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:48:47 by gacalaza          #+#    #+#             */
/*   Updated: 2023/11/04 19:49:22 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	tilde_case(t_token *tokens)
{
	if (tokens->next->type != WORD)
		return (C_ERROR);
	return (0);
}

int	asterick_case(t_token *tokens)
{
	if (tokens->next->type != WORD)
		return (C_ERROR);
	return (0);
}

int	is_special_case(int type, int check)
{
	if (check == 1)
	{
		if (type != 11
			&& type != 6 && type != 4)
			return (TRUE);
	}
	if (check == 2)
	{
		if (type != 6 && type != 4)
			return (TRUE);
	}
	return (FALSE);
}
