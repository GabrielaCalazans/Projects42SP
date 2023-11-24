/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:14:38 by gacalaza          #+#    #+#             */
/*   Updated: 2023/11/23 13:22:10 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

// void	ft_clear_cmd(t_data *data)
// {
// 	free(data->cmd->cmd);
// 	data->cmd->args = freearray(data->cmd->args);
// 	data->cmd->args = NULL;
// }

void	print_array(char **array, char *type)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i] != NULL)
	{
		printf("%s[%i]: %s\n", type, i, array[i]);
		i++;
	}
	printf("\n");
}
