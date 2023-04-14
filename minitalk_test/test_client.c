/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:52:56 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/14 00:28:48 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

int	check;

static void	coder(unsigned char ch, pid_t pid)
{
	int				c;
	unsigned int	base;

	c = 7; // contador para os bits da mensagem
	base = 128; // 1000 0000 em binário, base para calcular o valor de cada bit
	while (c >= 0) // iterando pelos bits da mensagem
	{
		if (ch < base) // se o bit atual é zero
		{
			// ft_putchar_fd('0', 1); // escreve 0 no console
			kill(pid, SIGUSR1); // envia sinal SIGUSR1 para o processo receptor
		}
		else // se o bit atual é um
		{
			// ft_putchar_fd('1', 1); // escreve 1 no console
			kill(pid, SIGUSR2);  // envia sinal SIGUSR2 para o processo receptor
			ch = ch - base; // calcula o valor do bit atual
		}
		base = base / 2; // divide a base por 2 para calcular o próximo bit
		c--; // decrementa o contador para processar o próximo bit
		usleep(200);// espera 200 microssegundos antes de enviar o próximo sinal
	}
}

static void	roger_that(int sig)
{
	if (sig == SIGUSR2 && check == 1)
	{
		ft_putstr_fd("Message received by the server.\n", 1);
		check = 2;
	}
}

static void	client_usage(void)
{
	ft_putstr_fd("Incorrect number of arguments\n\t", 1);
	ft_putstr_fd("Client Usage:\n\t", 1);
	ft_putstr_fd("To run -> ./Client server PID number \"string\"\n", 1);
}

int	main(int argc, char *argv[])
{
	int					count;
	int					server_pid;
	struct sigaction	sa;

	// Configurar o manipulador de sinal para SIGUSR1
	check = 1;
	sa.sa_handler = roger_that;
	sa.sa_flags = 0;
	sigaction(SIGUSR2, &sa, NULL);
	count = 0; // contador para os caracteres da mensagem
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		while (argv[2][count])
		{
			coder(argv[2][count], server_pid); // convertendo cada caractere em uma sequência de bits e enviando para o processo receptor
			// ft_putchar_fd('\n', 1);
			count++;
		}
		coder('\n', server_pid);
	}
	else
		client_usage();
	return (0);
}
