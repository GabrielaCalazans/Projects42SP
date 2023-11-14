/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:05:26 by ckunimur          #+#    #+#             */
/*   Updated: 2023/11/14 15:14:57 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_exit(t_data *data)
{
	long	err;

	err = 1;
	if (!data->cmd[1])
	{
		ft_clear_data(data);
		ft_printf("exit\n");
		exit(err);
	}
	else if (data->cmd[2])
		printf("exit: too many argments\n");
	else if (data->cmd[1])
	{
		if (ft_atoi(data->cmd[1]) == 0 && (data->cmd[1][0] != '0'))
		{
			err = 2;
			ft_printf("numeric argument is required\n");
		}
		else if (ft_strlen(data->cmd[1]) < 19)
			err = ft_atoi(data->cmd[1]);
		ft_clear_data(data);
		ft_printf("exit\n");
		exit(err);
	}
}
