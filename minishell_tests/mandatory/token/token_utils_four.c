/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils_four.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:05:39 by gacalaza          #+#    #+#             */
/*   Updated: 2023/10/16 16:46:46 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_special_char(char c)
{
	if (c == '*')
		return (ASTERISK);
	if (c == '&')
		return (AMPERSAND);
	if (c == '~')
		return (TILDE);
	if (c == '.')
		return (DOT);
	if (c == ';')
		return (SEMICOLON);
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
