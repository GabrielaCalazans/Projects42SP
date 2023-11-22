/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:14:38 by gacalaza          #+#    #+#             */
/*   Updated: 2023/11/22 19:32:03 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**get_cmd(char **words, int len)
{
	char	**cmd;

	cmd = NULL;
	if (len > 1)
	{
		if (find_type(words[0]) == 10 && find_type(words[1]) == 4)
		{
			cmd = ft_arraydup_size(words, 2);
		}
		else
			cmd = ft_arraydup_size(words, 1);
	}
	if (len < 2)
		cmd = ft_arraydup_size(words, 1);
	return (cmd);
}

char	**get_cmd_args(char **words, int check, int len)
{
	char	**cmd_args;

	cmd_args = NULL;
	if (check == 1 && len > 2)
		cmd_args = ft_arraydup(trim_quote(&words[2]));
	if (len > 1 && check == 0)
		cmd_args = ft_arraydup(trim_quote(&words[1]));
	return (cmd_args);
}

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
