/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:02:03 by gacalaza          #+#    #+#             */
/*   Updated: 2024/06/01 15:37:26 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"
#include <stdio.h>

int err(char *str) 
{
	while (*str)
		write(2, str++, 1);
	return 1;
}

int cd(char **argv, int i) 
{
	if (i != 2)
		return err("error: cd: bad arguments\n");
	else if (chdir(argv[1]) == -1)
		return err("error: cd: cannot change directory to "), err(argv[1]), err("\n");
	return 0;
}

// int exec(char **argv, char **envp, int i) 
// {
// 	int	fd[2];
// 	int	status;
// 	int	has_pipe = argv[i] && !strcmp(argv[i], "|");

// 	if (has_pipe && pipe(fd) == -1)
// 		return err("error: fatal\n");

// 	int pid = fork();
// 	if (pid == 0)
// 	{
// 		argv[i] = 0;
// 		if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
// 			return err("error: fatal\n");
// 		execve(*argv, argv, envp);
// 		return err("error: cannot execute "), err(*argv), err("\n");
// 	}

// 	waitpid(pid, &status, 0);
// 	if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
// 		return err("error: fatal\n");
// 	return WIFEXITED(status) && WEXITSTATUS(status);
// }

int	exec(char **argv, char **envp, int i) 
{
	int fd[2];
	int status;
	int has_pipe = (argv[i] && !strcmp(argv[i], "|"));

	if (has_pipe && pipe(fd) == -1)
		return err("error: fatal\n");

	int pid = fork();
	if (pid == 0)
	{
		argv[i] = 0; // Terminate the current command arguments
		if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return err("error: fatal\n");
		// {
		// 	dup2(fd[1], 1); // Redirect stdout to the write end of the pipe
		// 	close(fd[0]);   // Close unused read end
		// 	close(fd[1]);   // Close write end after redirect
		// }
		execve(argv[0], argv, envp);
		return err("error: cannot execute "), err(argv[0]), err("\n");
	}
	else if (pid < 0) // Fork failed
	{
		return err("error: fatal\n");
	}

	waitpid(pid, &status, 0);
	if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return err("error: fatal\n");
	// {
	// 	dup2(fd[0], 0); // Redirect stdin to the read end of the pipe
	// 	close(fd[0]);   // Close read end after redirect
	// 	close(fd[1]);   // Close unused write end
	// }
	return WIFEXITED(status) && WEXITSTATUS(status);
}


// int	main(int argc, char **argv, char **envp) 
// {
// 	int	i = 0;
// 	int	status = 0;

// 	if (argc > 1) 
// 	{
// 		while (argv[i] && argv[++i]) 
// 		{
// 			argv += i;
// 			i = 0;
// 			printf("VAL: %i\n\n", strcmp(argv[i], "|"));
// 			while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
// 				i++;
// 			if (!strcmp(*argv, "cd"))
// 				status = cd(argv, i);
// 			else if (i)
// 				status = exec(argv, envp, i);
// 		}
// 	}
// 	return (status);
// }

int	main(int argc, char **argv, char **envp) 
{
	int i = 1;
	int status = 0;

	while (i < argc)
	{
		int j = i;
		while (j < argc && strcmp(argv[j], "|") && strcmp(argv[j], ";"))
			j++;
		
		argv[j] = 0; // Terminate current command arguments
		
		if (!strcmp(argv[i], "cd"))
			status = cd(&argv[i], j - i);
		else if (j != i)
			status = exec(&argv[i], envp, j - i);

		i = j + 1;
	}
	return status;
}