/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:55:33 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/10 16:38:21 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"
#include "stdio.h"
#include <sys/wait.h>

int	x = 0;

void	handler(int num)
{
	write(STDOUT_FILENO, "I won't die!\n", 13);
}

void	handle_sigusr1(int sig)
{
	if (x == 0)
		printf("\n(HINT) Remenber that multiplication is repetitive addition!\n");
}

void	handle_sigtstp(int sig)
{
	printf("Stoped not allowed\n");
}

int	main(int argc, char* argv[])
{
	// *************** TESTS1 **************************
	// signal(SIGINT, handler); // kill -KILL id
	// while (1)
	// {
	// 	printf("Days left in your life [%d]\n", getpid());
	// 	sleep(3);
	// }

	// *************** TESTS2 **************************
	// int pid;

	// pid = fork();

	// if (pid == -1)
	// {
	// 	return 1;
	// }
	// if (pid == 0)
	// {
	// 	// Child process
	// 	sleep(5);
	// 	kill(getppid(), SIGUSR1);
	// }
	// else
	// {
	// 	struct sigaction sa;
	// 	sa.sa_flags = SA_RESTART;
	// 	sa.sa_handler = &handle_sigusr1;
	// 	sigaction(SIGUSR1, &sa, NULL);
		

	// 	// Parent process
	// 	printf("What is the result of 3 x 5:  ");
	// 	scanf("%d", &x);
	// 	if (x == 15)
	// 	{
	// 		printf("Right!");
	// 	}
	// 	else
	// 	{
	// 		printf("Wrong!");
	// 	}
	// 	wait(NULL);
	// }

	// *************** TESTS3 **************************

	struct sigaction sa;
	sa.sa_handler = &handle_sigtstp;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGTSTP, &sa, NULL);

	ft_printf("Input number: ");
	scanf("%d", &x);
	ft_printf("Result %d * 5 = %d\n", x, x * 5);
	


	return 0;
}
