/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:51:11 by gacalaza          #+#    #+#             */
/*   Updated: 2024/03/27 20:20:28 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	ft_puterr(char *err)
{
	int	i = 0;
	while (err[i] != '\0')
	{
		write(1, &err[i], 1);
		i++;
	}
	return (1);
}

int	cd(char *argv[], int i)
{
	if (i != 2)
		return (ft_puterr("error: cd: bad arguments\n"));
	if (chdir(argv[1]) == -1)
		return (ft_puterr("error: cd: cannot change directory to "), ft_puterr(argv[1]), ft_puterr("\n"));
	return (0);
}

int	ft_exec(char *argv[], char *env[], int i)
{
	int	fd[2];
	int	status = 0;
	int	has_pipe = argv[i] &&  !strcmp(argv[i], "|");

	if (has_pipe && pipe(fd) == -1)
		return (ft_puterr("error: fatal\n"));
	int	pid = fork();
	if (!pid)
	{
		argv[i] = 0;
		if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return (ft_puterr("error: fatal\n"));
		execve(*argv, argv, env);
		return (ft_puterr("error: cannot execute "), ft_puterr(*argv), ft_puterr("\n"));
	}
	waitpid(pid, &status, 0);
	if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return (ft_puterr("error: fatal\n"));
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int	main(int argc, char *argv[], char *env[])
{
	int	i = 0;
	int	status = 0;

	if (argc > 1)
	{
		while (argv[i] && argv[++i])
		{
			argv += i;
			i = 0;
			while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
				i++;
			if (!strcmp(*argv, "cd"))
				status = cd(argv, i);
			else if (i)
				status = ft_exec(argv, env, i);
		}
	}
	return (status);
}