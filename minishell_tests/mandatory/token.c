/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:12:20 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/21 16:25:32 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_redirect(char c)
{
	if (c == '<')
		return (1);
	if (c == '>')
		return (1);
	return (0);
}

int	is_pipe(char c)
{
	if (c == '|')
		return (1);
	return (0);
}

int	is_flag(char c)
{
	if (c == '-')
		return (1);
	return (0);
}

int	is_flag(char c)
{
	if (c == '-')
		return (1);
	return (0);
}



void	creat_token(char *str)
{
	while (*str)
	{
		if (str)
		str++;
	}
}
