/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:55:22 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/21 16:07:47 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// void	exec_cmd(t_data *ptr)
// {
// 	char	*path;
// 	char	**cmd_args;
// 	char	*env_var;
// 	pid_t	child_pid;

// 	path = find_path(ptr->cmd);
// 	cmd_args = find_args(ptr->cmd_args);
// }

int	is_builtins(char *check)
{
	if (ft_strncmp(check, "echo", 4) == 0)
		return (1);
	if (ft_strncmp(check, "cd", 2) == 0)
		return (2);
	if (ft_strncmp(check, "pwd", 3) == 0)
		return (3);
	if (ft_strncmp(check, "export", 6) == 0)
		return (4);
	if (ft_strncmp(check, "unset", 5) == 0)
		return (5);
	if (ft_strncmp(check, "env", 3) == 0)
		return (6);
	if (ft_strncmp(check, "exit", 4) == 0)
		return (7);
	else
		return (0);
}

void	call_builtins(t_data *ptr)
{
	if (is_builtins(ptr->cmd[0]) == 1)
		ft_echo(ptr);
	if (is_builtins(ptr->cmd[0]) == 2)
		ft_cd(ptr);
	if (is_builtins(ptr->cmd[0]) == 3)
		ft_pwd(ptr);
	if (is_builtins(ptr->cmd[0]) == 4)
		ft_export(ptr);
	if (is_builtins(ptr->cmd[0]) == 5)
		ft_unset(ptr);
	if (is_builtins(ptr->cmd[0]) == 6)
		ft_env(ptr);
	if (is_builtins(ptr->cmd[0]) == 7)
		ft_exit(ptr);
	else
		printf("Them, all, eventually, went to shit");
}

void	exec_check(t_data *ptr)
{
	if (is_builtins(ptr->cmd[0]))
		return (call_builtins(ptr));
	else
		printf("Se foda.");
}
