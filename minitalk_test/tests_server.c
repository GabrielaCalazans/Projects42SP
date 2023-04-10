/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:13:01 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/10 20:13:47 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

static void	decoder(int sig, siginfo_t *info, void *context)
{
	static int	counter = 0;
	static char	ch = 0;
	(void)info;

	if (sig == SIGUSR2)
		ch = ch | 128 >> counter;
	counter++;
	if (counter == 8)
	{
		ft_putchar_fd(ch, 1);
		ch = 0;
		counter = 0;
	}
}

int	main(void)
{
	struct sigaction	sa1;
	struct sigaction	sa2;
	int					my_pid;
	
	my_pid = getpid();
	ft_printf("Server PID is %d", my_pid);
	ft_putchar_fd('\n', 1);
	sa1.sa_flags = SA_SIGINFO;
	sa1.sa_sigaction = decoder;
	sigaction(SIGUSR1, &sa1, NULL);
	sa2.sa_flags = SA_SIGINFO;
	sa2.sa_sigaction = decoder;
	sigaction(SIGUSR2, &sa2, NULL);
	while (1)
		sleep(5);
	return (0);
}
