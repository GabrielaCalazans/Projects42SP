/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:55:06 by gacalaza          #+#    #+#             */
/*   Updated: 2023/12/02 21:27:17 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Adiciona o comando à história se não estiver vazio
// add_history(tmp->prompt_input);
// Agora 'input' contém o comando digitado pelo usuário
// VERIFICAR LEAK DE MEMORIA??
// void	prompt(t_data *data)
// {
// 	while (1)
// 	{
// 		data->prompt_in = readline(PROMPT);
// 		if (data->prompt_in[0] != '\0')
// 		{
// 			add_history(data->prompt_in);
// 			printf("prompt %s\n", data->prompt_in);
// 		}
// 		if (data->prompt_in[0] != '\0')
// 			start_token(data);
// 		if (has_redirect(data->tokens))
// 			create_redirect_lst(data);
// 		ft_clear_data(data);
// 	}
// 	rl_clear_history();
// }

// void	set_path_command(t_data *data)
// {
// 	char	**path;
// 	char	*tmp1;
// 	char	*tmp2;
// 	int		i;

// 	i = 0;
// 	path = ft_split(data->path, ':');
// 	while (path[i])
// 	{
// 		tmp1 = ft_strjoin(path[i], "/");
// 		tmp2 = ft_strjoin(tmp1, data->cmd[0]);
// 		if (tmp1)
// 			free(tmp1);
// 		if (!access(tmp2, F_OK))
// 		{
// 			if (!access(tmp2, X_OK))
// 			{
// 				if (data->cmd[0])
// 					free(data->cmd[0]);
// 				data->cmd[0] = tmp2;
// 				ft_clean_lst(path);
// 				return ;
// 			}
// 		}
// 		if (tmp2)
// 			free(tmp2);
// 		i++;
// 	}
// }

char	*create_command_path(char *path, char *command)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_strjoin(path, "/");
	if (!tmp1)
		return (NULL);
	tmp2 = ft_strjoin(tmp1, command);
	free(tmp1);
	if (!access(tmp2, F_OK) && !access(tmp2, X_OK))
		return (tmp2);
	free(tmp2);
	return (NULL);
}

void	set_path_command(t_data *data)
{
	char	**path;
	char	*command_path;
	int		i;

	path = ft_split(data->path, ':');
	i = 0;
	while (path[i])
	{
		command_path = create_command_path(path[i], data->cmd->cmd);
		if (command_path)
		{
			printf("%s", data->cmd->cmd);
			if (data->cmd->cmd)
				free(data->cmd->cmd);
			data->cmd->cmd = command_path;
			ft_clean_lst(path);
			return ;
		}
		i++;
	}
	ft_clean_lst(path);
}

void	get_path(t_data *data)
{
	t_env	*tmp;

	tmp = data->env_node;
	while (tmp)
	{
		if (ft_strncmp(tmp->var, "PATH", 5) == 0)
		{
			data->path = tmp->value;
			break ;
		}
		tmp = tmp->next;
	}
}

void	prompt(t_data *data)
{
	// run_signals(1);
	data->prompt_in = readline(PROMPT);
	if (data->prompt_in && *data->prompt_in)
	{
		add_history(data->prompt_in);
		printf("PROMPT: %s\n", data->prompt_in);
	}
}

int	command_count(t_data *data)
{
	int		command;
	t_cmd	*tmp;

	command = 0;
	tmp = data->cmd;
	while (tmp)
	{
		command++;
		tmp = tmp->next;
	}
	return (command);
}

void	mini_start(t_data *data)
{
	extern char	**environ;

	data->env = environ;
	get_path(data);
	if (ft_strlen(data->prompt_in) != 0)
		start_token(data);
	if (has_redirect(data->tokens) || has_dredirect(data->tokens))
		create_redirect_lst(data);
	parsing_it(data);
	data->n_cmd = command_count(data);
	printf("comands: %i\n", data->n_cmd);
	if (!exec_builtin(data))
		execution(data);
}

// data->cmd = ft_split(data->prompt_in, ' ');
// data->path = TEST_PATH;
// void	prompt(t_data *data)
// {
// 	extern char	**environ;

// 	while (1)
// 	{
// 		data->prompt_in = readline(PROMPT);
// 		if (data->prompt_in[0] != '\0')
// 		{
// 			add_history(data->prompt_in);
// 			printf("PROMPT: %s\n", data->prompt_in);
// 		}
// 		data->cmd->cmd = ft_split(data->prompt_in, ' ');
// 		if (data->prompt_in[0] != '\0')
// 			start_token(data);
// 		if (has_redirect(data->tokens))
// 			create_redirect_lst(data);
// 		parsing_it(data);
// 		data->env = environ;
// 		get_path(data);
// 		// parsing_it(data);
// 		if (!exec_builtin(data))
// 			execution(data);
// 		ft_clear_data(data);
// 	}

// }
