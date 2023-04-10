/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:52:56 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/10 19:48:29 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

static void	decoder(unsigned char ch, pid_t pid)
{
	int				c;
	unsigned int	base;

	c = 7;
	base = 128;
	while (c >= 0)
	{
		if (ch < base)
		{
			ft_putchar_fd('0', 1);
			kill(pid, SIGUSR1);
		}
		else
		{
			ft_putchar_fd('1', 1);
			kill(pid, SIGUSR2);
			ch = ch - base;
		}
		base = base / 2;
		c--;
		usleep(200);
	}
}

int	main(int args, char **argv)
{
	int	counter;
	int	server_pid;

	counter = 0;
	if (args == 3)
	{
		server_pid = ft_atoi(argv[1]);
		while (argv[2][counter])
		{
			decoder(argv[2][counter], server_pid);
			ft_putchar_fd('\n', 1);
			counter++;
		}
		decoder('\n', server_pid);
	}
	return (0);
}
