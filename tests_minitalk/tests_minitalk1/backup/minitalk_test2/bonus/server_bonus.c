/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:48:49 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/15 18:03:11 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

void	decoder(int sig, siginfo_t *info, void *context)
{
	static int	count = 0;
	static char	c = 0;

	(void)context;
	if (sig == SIGUSR2)
		c = c | 128 >> count;
	count++;
	if (count == 8)
	{
		ft_putchar_fd(c, 1);
		c = 0;
		count = 0;
	}
	if (sig == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
	else
		kill(info->si_pid, SIGUSR1);
}

static void	server_usage(void)
{
	ft_putstr_fd("Incorrect number of arguments\n\t", 1);
	ft_putstr_fd("Server Usage:\n\t", 1);
	ft_putstr_fd("To run, use only -> ./Server\n", 1);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sig;
	sigset_t			sigset;

	(void)argv;
	if (argc != 1)
	{
		server_usage();
		exit(1);
	}
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	sig.sa_handler = NULL;
	sig.sa_mask = sigset;
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = decoder;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	ft_printf("Server PID: %d", getpid());
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
}
