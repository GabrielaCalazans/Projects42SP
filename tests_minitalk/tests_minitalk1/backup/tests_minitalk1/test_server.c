/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:13:01 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/14 16:53:58 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

static void	decoder(int sig, siginfo_t *info, void *context)
{
	static int	count = 0;
	static char	c = 0;
	(void)context;

	if (sig == SIGUSR2)
		c = c | 128 >> count; // setar o MSB em c qndo client envia um sinal 
		//SIGUSR2, o bit "1" é adicionado em c no bit mais significativo 
		// (128 >> counter) e essa operação é realizada até q os 8 bits q compõem 
		// o char estejam completos
	count++;
	// Após o recebimento de um bit, a var count é incrementada e é 
	// verificado se foram recebidos os 8 bits de um char. 
	// Quando count atinge 8, é impresso o caractere correspondente usando 
	// ft_putchar_fd e as variáveis count e c são resetadas
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

// static void decoder(int sig, siginfo_t *info, void *context)
// {
// 	static int count = 0;
// 	static unsigned char buffer = 0;
// 	(void)context;

// 	if (sig == SIGUSR2)
// 		buffer |= (1 << (7 - count));
// 	count++;
// 	if (count == 8)
// 	{
// 		ft_putchar_fd(buffer, 1);
// 		count = 0;
// 		buffer = 0;
// 	}
// 	// Verifica se a mensagem foi recebida completa
// 	if (buffer == '\0')
// 	{
// 		// Envia sinal de confirmação ao cliente
// 		kill(info->si_pid, SIGUSR1);
// 	}
// }


// static void	decoder(int sig, siginfo_t *info, void *context)
// {
// 	static unsigned char	byte = 0;
// 	static int				bit_count = 0;
// 	unsigned char			mask;

// 	(void)context;
// 	mask = 1 << bit_count;
// 	if (sig == SIGUSR1)
// 		byte &= ~mask;
// 	else if (sig == SIGUSR2)
// 		byte |= mask;

// 	bit_count++;
// 	if (bit_count == 8)
// 	{
// 		if (byte == '\0')
// 			kill(info->si_pid, SIGUSR2); // envia sinal de volta para o cliente
// 		else
// 			ft_putchar_fd(byte, 1);
// 		byte = 0;
// 		bit_count = 0;
// 	}
// }

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
	sig.sa_flags = SA_SIGINFO; //A flag SA_SIGINFO não afeta o comportamento do 
	// manipulador de sinal(decoder), apenas define que informações adicionais sobre o 
	// sinal serão passadas para o manipulador. mas devo inicializar os membros da struct
	sig.sa_sigaction = decoder;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	ft_printf("Server PID: %d", getpid());
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
}
