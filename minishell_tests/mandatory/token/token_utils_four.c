/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils_four.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:05:39 by gacalaza          #+#    #+#             */
/*   Updated: 2023/10/12 19:28:19 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_asterisk(char c)
{
	if (c == '*')
		return (ASTERISK);
	return (0);
}

int	is_ampersand(char c)
{
	if (c == '&')
		return (AMPERSAND);
	return (0);
}

int	is_r_bracket(char c)
{
	if (c == '(')
		return (R_BRACKET_O);
	if (c == ')')
		return (R_BRACKET_C);
	return (0);
}
