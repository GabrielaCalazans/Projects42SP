/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:12:57 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/17 16:23:56 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int	new_process(char *program, char ** list_of_args)
{
	pid_t	pid_child;
	pid_child = fork();
	if (pid_child != 0)
		return pid_child;
	else
	{
		execvp(program, list_of_args);
		printf("ERROR EXEC\n");
		abort();
	}
}

int	main()
{
	printf("The PID is: %d\n", (int) getpid());
	printf("The PARENT PPID is: %d\n", getppid());

	// char *list_of_args[] = {"ls", "-l", "/", NULL};
	// new_process("ls", list_of_args);
	// printf("Este é o processo PAI\n");
	
	return 0;
}
