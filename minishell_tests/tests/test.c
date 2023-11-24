/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:55:33 by gacalaza          #+#    #+#             */
/*   Updated: 2023/11/23 15:30:24 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/minishell.h"

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

int	is_quote(char c)
{
	if (c == '\"')
		return (QUOTE_DOUBLE);
	if (c == '\'')
		return (QUOTE_SINGLE);
	return (0);
}

int	has_asquote_str(char *str, int type)
{
	int	i;

	i = 0;
	while (str[++i] != '\0')
	{
		printf(" str[%i]:%c ", i, str[i]);
		if (type == is_quote(str[i]))
		{
			printf("len%i\n", i);
			return (i);
		}
	}
	return (0);
}


int	ft_strrchr_len(char *str, int type)
{
	int	size;

	size = ft_strlen(str);
	printf("size%i\n", size);
	while (str[--size] && size >= 0)
	{
		printf("str[%i]:%c\n", size, str[size]);
		if (is_quote(str[size]) == type)
		{
			return (size);
		}
	}
	return (FALSE);
}


int	main(void)
{
	char	*str = "oi \"sei \"o que lá";
	int		len = ft_strlen(str);
	printf ("%d\tlen:%i\n", ft_strrchr_len(&str[4], QUOTE_DOUBLE), len);
	// int		pipe_fd[2];
	// pid_t	child_pid;

	// // Cria um pipe
	// if (pipe(pipe_fd) == -1) {
	// 	perror("Erro ao criar o pipe");
	// 	exit(EXIT_FAILURE);
	// }
	// // Cria um novo processo
	// if ((child_pid = fork()) == -1)
	// {
	// 	perror("Erro ao criar um novo processo");
	// 	exit(EXIT_FAILURE);
	// }
	// if (child_pid == 0)
	// {
	// 	// Código do filho (processo 1)
	// 	// Fecha a extremidade de leitura do pipe
	// 	close(pipe_fd[0]);
	// 	// Redireciona a saída padrão para a extremidade de escrita do pipe
	// 	dup2(pipe_fd[1], STDOUT_FILENO);
	// 	// Execute o primeiro comando usando execve
	// 	char *command1[] = {"/bin/ls", "-l", NULL};
	// 	execve(command1[0], command1, NULL);
	// 	perror("Erro ao executar o primeiro comando");
	// 	exit(EXIT_FAILURE);
	// }
	// else
	// {
	// 	// Código do pai (processo 2)
	// 	close(pipe_fd[1]); // Fecha a extremidade de escrita do pipe
	// 	// Redireciona a entrada padrão para a extremidade de leitura do pipe
	// 	dup2(pipe_fd[0], STDIN_FILENO);
	// 	// Execute o segundo comando usando execve
	// 	char *command2[] = {"/usr/bin/grep", "keyword", NULL};
	// 	execve(command2[0], command2, NULL);
	// 	perror("Erro ao executar o segundo comando");
	// 	exit(EXIT_FAILURE);
	// }
	return (0);
}
