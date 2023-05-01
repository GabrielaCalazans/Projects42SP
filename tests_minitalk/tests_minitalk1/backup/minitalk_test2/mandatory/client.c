/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:14:55 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/19 15:27:01 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../include/minitalk.h"

int	g_bitc;

void	coder(int server_pid, char c)
{
	while (g_bitc < 8)
	{
		if ((128 >> g_bitc) & c)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(5000);
		if (g_bitc == 8)
		{
			g_bitc = 0;
			return ;
		}
	}
}

static void	roger_that(int sig)
{
	if (sig == SIGUSR1)
		g_bitc++;
	else if (sig == SIGUSR2)
		g_bitc++;
	else
	{
		ft_printf("\tError: Signal is invalid.\n");
		exit(1);
	}
}

static void	client_usage(void)
{
	ft_putstr_fd("Incorrect number of arguments\n\t", 1);
	ft_putstr_fd("Client Usage:\n\t", 1);
	ft_putstr_fd("To run -> ./Client server PID \"string\"\n", 1);
}

void	check_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i] != '\0')
	{
		if (!ft_isdigit(pid[i]))
		{
			ft_putstr_fd("Invalid Server PID entered. Please enter a valid PID and try again..\n", 1);
			ft_putstr_fd("The PID(Process IDentifier) is a interger number.\n", 1);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	size_t	count;
	int		server_pid;

	g_bitc = 0;
	signal(SIGUSR2, roger_that);
	signal(SIGUSR1, roger_that);
	count = 0;
	if (argc == 3)
	{
		check_pid(argv[1]);
		server_pid = ft_atoi(argv[1]);
		while (argv[2][count])
		{
			if (argv[2][count] == '\0')
				break ;
			coder(server_pid, argv[2][count]);
			count++;
		}
		coder(server_pid, '\n');
		exit(0);
	}
	else
		client_usage();
}
