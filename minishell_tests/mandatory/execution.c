/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:55:22 by gacalaza          #+#    #+#             */
/*   Updated: 2023/11/22 22:18:13 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// void	exec_cmd(t_data *ptr)
// {
// 	char	*path;
// 	char	**args;
// 	char	*env_var;
// 	pid_t	child_pid;

// 	path = find_path(ptr->cmd);
// 	args = find_args(ptr->args);
// }

// void	exec_check(t_data *ptr)
// {
// 	if (is_builtins(ptr->cmd[0]))
// 		return (call_builtins(ptr));
// 	else
// 		execution(ptr);
// }

/*
[] pipe
[] exit code
[x] path command 
[] mult pipes
*/
void	execution(t_data *data)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		set_path_command(data);
		execve(data->cmd->cmd, data->cmd->args, data->env);
		printf("Error!\n");
		exit(1);
	}
	waitpid(-1, &status, 0);
}

void	dup_pipe(int *fd, int ord, int len_pipe)
{
	if (ord == 0)
		dup2(0, fd[0]);
	else if (ord == len_pipe)
		dup2(1, fd[1]);
	else
	{
		dup2(0, fd[0]);
		dup2(1, fd[1]);
	}
}
