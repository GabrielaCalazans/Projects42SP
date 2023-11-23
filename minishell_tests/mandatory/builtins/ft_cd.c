/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:03:28 by ckunimur          #+#    #+#             */
/*   Updated: 2023/11/22 22:22:34 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_cd(t_data *data)
{
	char	*go_home;

	if (data->cmd->args[0] == NULL)
	{
		go_home = getenv("HOME");
		if (go_home != NULL)
		{
			if (chdir(go_home) != 0)
				perror("cd");
		}
		else
			ft_putendl_fd("cd: could not determine home directory\n", 2);
	}
	else if (data->cmd->args[0] != NULL && chdir(data->cmd->args[0]) != 0)
		perror("cd");
}