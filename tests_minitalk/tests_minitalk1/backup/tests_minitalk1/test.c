/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:58:06 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/12 01:36:21 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

#include <signal.h>
#include <unistd.h>
#include "libft.h"

static void	decoder(int sig, siginfo_t *info, void *context)
{
    static int	counter = 0;
    static char	ch = 0;
    (void)context;

    if (sig == SIGUSR2)
        ch = ch | 128 >> counter;
    counter++;
    if (counter == 8)
    {
        ft_putchar_fd(ch, 1);
        ch = 0;
        counter = 0;
        // Envia um sinal de volta para o cliente
        kill(info->si_pid, SIGUSR1);
    }
}

static void	handler(int sig, siginfo_t *info, void *context)
{
    (void)context;
    if (sig == SIGUSR1)
    {
        ft_putstr_fd("Mensagem recebida pelo servidor\n", 1);
        // Envia um sinal de volta para o cliente confirmando que a mensagem foi recebida
        kill(info->si_pid, SIGUSR2);
    }
}

int	main(void)
{
    struct sigaction    sa1;
    struct sigaction    sa2;
    struct sigaction    sa3;
    pid_t               my_pid;

    my_pid = getpid();
    ft_printf("Server PID is %d", (int)my_pid);
    ft_putchar_fd('\n', 1);

    sa1.sa_flags = SA_SIGINFO;
    sa1.sa_sigaction = decoder;
    sigaction(SIGUSR1, &sa1, NULL);

    sa2.sa_flags = SA_SIGINFO;
    sa2.sa_sigaction = decoder;
    sigaction(SIGUSR2, &sa2, NULL);

    sa3.sa_flags = SA_SIGINFO;
    sa3.sa_sigaction = handler;
    sigaction(SIGUSR1, &sa3, NULL);

    while (1)
        sleep(5);

    return (0);
}

