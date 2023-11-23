/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:06:15 by ckunimur          #+#    #+#             */
/*   Updated: 2023/11/22 22:20:15 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_unset(t_data *data)
{
	t_env	*env_node;
	t_env	*temp_node;

	temp_node = ft_calloc(sizeof(t_env), 1);
	env_node = data->env_node;
	if (data->cmd->args[0])
	{
		temp_node = have_var(data);
		if (temp_node == NULL)
			return ;
		while (env_node->next != temp_node)
				env_node = env_node->next;
			env_node->next = temp_node->next;
		ft_clear_env(temp_node);
	}
}
