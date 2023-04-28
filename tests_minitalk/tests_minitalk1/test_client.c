/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:52:56 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/14 21:55:17 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

int	g_bitc;

// static void	coder(unsigned char ch, pid_t pid)
// {
// 	int				c;
// 	unsigned int	base;

// 	c = 7; // contador para os bits da mensagem
// 	base = 128; // 1000 0000 em binário, base para calcular o valor de cada bit
// 	while (c >= 0) // iterando pelos bits da mensagem
// 	{
// 		if (ch < base) // se o bit atual é zero
// 		{
// 			// ft_putchar_fd('0', 1); // escreve 0 no console
// 			kill(pid, SIGUSR1); // envia sinal SIGUSR1 para o processo receptor
// 		}
// 		else // se o bit atual é um
// 		{
// 			// ft_putchar_fd('1', 1); // escreve 1 no console
// 			kill(pid, SIGUSR2);  // envia sinal SIGUSR2 para o processo receptor
// 			ch = ch - base; // calcula o valor do bit atual
// 		}
// 		base = base / 2; // divide a base por 2 para calcular o próximo bit
// 		c--; // decrementa o contador para processar o próximo bit
// 		usleep(9000);// espera 5000 microssegundos antes de enviar o próximo sinal
// 	}
// }

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
			write(1, " ", 1);
			return ;
		}
	}
}

static void	roger_that(int sig)
{
	if (sig == SIGUSR1)
	{
		g_bitc++;
		ft_putchar_fd('1', 1);
	}
	else if (sig == SIGUSR2)
	{
		g_bitc++;
		ft_putchar_fd('0', 1);
	}
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

int	main(int argc, char *argv[])
{
	size_t	count;
	int		server_pid;

	// Configurar o manipulador de sinal para SIGUSR1
	g_bitc = 0;
	// sa.sa_handler = roger_that;
	// sa.sa_flags = 0;
	signal(SIGUSR2, roger_that);
	sidecodergnal(SIGUSR1, roger_that);
	count = 0; // contador para os caracteres da mensagem
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		while (argv[2][count])
		{
			if (argv[2][count] == '\0')
				break ;
			coder(server_pid, argv[2][count]); // convertendo cada caractere em uma sequência de bits e enviando para o processo receptor
			// ft_putchar_fd('\n', 1);
			count++;
		}
		coder(server_pid, '\n');
		exit(0);
	}
	else
		client_usage();
}
