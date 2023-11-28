/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:55:22 by gacalaza          #+#    #+#             */
/*   Updated: 2023/11/28 19:48:51 by gacalaza         ###   ########.fr       */
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


void	close_fd(t_data *data, int n_fd)
{
	int	i;

	i = 0;
	while (i <= n_fd)
		close(data->fd[i++]);
}

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

void	dup_pipe(int ord, t_data *data)
{
	if (ord == 0)
	{
		dup2(data->fd[1], 1);
		close_fd(data, data->n_cmd * 2);
	}
	else if (ord == data->n_cmd - 1)
	{
		dup2(data->fd[2], 0);
		close_fd(data, data->n_cmd * 2);
	}
	else
	{
		dup2(data->fd[0], 0);
		dup2(data->fd[3], 1);
		close_fd(data, data->n_cmd * 2);
	}
}

