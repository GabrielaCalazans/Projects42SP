/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:04:33 by ckunimur          #+#    #+#             */
/*   Updated: 2023/11/23 13:32:36 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// void	ft_echo(t_data *data)
// {
// 	int		i;
// 	t_data	*temp;

// 	i = 0;
// 	temp = data;
// 	printf("%s", temp->args[i]);
// 	i++;
// 	while (temp->args[i])
// 	{
// 		printf(" %s", temp->args[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

void	ft_echo(t_data *data)
{
	int		i;
	t_cmd	*temp;

	i = 0;
	temp = data->cmd;
	if (ft_strncmp(data->cmd->args[0], "-n", 3) == 0)
	{
		i++;
		printf("%s", temp->args[i]);
		while (temp->args[i] != NULL)
		{
			printf(" %s", temp->args[++i]);
		}
	}
	else
	{
		printf("%s", temp->args[i]);
		i++;
		while (temp->args[i])
		{
			printf(" %s", temp->args[i]);
			i++;
		}
		printf("\n");
	}
}

// CORRIGIR ESTÁ IMPRIMINDO NULL DO FINAL 