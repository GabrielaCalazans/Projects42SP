/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pai.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:18:00 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/16 20:08:39 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int main()
{
	char	*program_path;
	char	*env_var; // variável de ambiente que quiser acessar
	char	*env_value;
	char	*command[2];
	int		status;
	pid_t	child_pid;
	
	env_var = "USER";
	program_path = "./filho";
	command[0] = program_path;
	command[1] = NULL;
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return 1;
	}
	if (child_pid == 0)
	{
		env_value = getenv(env_var); // Usando getenv para obter o valor da variável de ambiente
		if (env_value == NULL)
		{
			perror("getenv");
			return 1;
		}
		// Este é o processo filho
		printf("env_value: %s\n", env_value);
		execve(program_path, command, &env_var);
		// Se chegarmos aqui, algo deu errado com execve
		perror("execve");
		exit(1);
	}
	else
	{
		if (child_pid > 0) // Verifica se este é o processo pai
		{
			printf("Executando o programa pai...\n");
		}
		waitpid(child_pid, &status, 0);
		printf("-Execução do programa filho concluída.\n");
	}
	return 0;
}
