/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:55:06 by gacalaza          #+#    #+#             */
/*   Updated: 2023/10/24 20:40:57 by gacalaza         ###   ########.fr       */
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
		command_path = create_command_path(path[i], data->cmd[0]);
		if (command_path)
		{
			if (data->cmd[0])
				free(data->cmd[0]);
			data->cmd[0] = command_path;
			ft_clean_lst(path);
			return ;
		}
		i++;
	}
	ft_clean_lst(path);
}

// data->cmd = ft_split(data->prompt_in, ' ');
// data->path = TEST_PATH;
void	prompt(t_data *data)
{
	extern char	**environ;

	while (1)
	{
		data->prompt_in = readline(PROMPT);
		if (data->prompt_in[0] != '\0')
		{
			add_history(data->prompt_in);
			printf("prompt %s\n", data->prompt_in);
		}
		data->cmd = ft_split(data->prompt_in, ' ');
		if (data->prompt_in[0] != '\0')
			start_token(data);
		if (has_redirect(data->tokens))
			create_redirect_lst(data);
		data->env = environ;
		if (!exec_builtin(data))
			execution(data);
		ft_clear_data(data);
	}
	rl_clear_history();
}
