/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:04:33 by ckunimur          #+#    #+#             */
/*   Updated: 2023/11/22 22:18:13 by gacalaza         ###   ########.fr       */
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
	printf("%s", temp->args[i]);
	i++;
	if (ft_strncmp(data->cmd->args[0], "-n", 3) == 0)
	{
		while (temp->args[i])
		{
			printf(" %s", temp->args[i]);
			i++;
		}
	}
	else
	{
		while (temp->args[i])
		{
			printf(" %s", temp->args[i]);
			i++;
		}
		printf("\n");
	}
}