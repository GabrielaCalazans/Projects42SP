/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:55:33 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/13 23:51:47 by gacalaza         ###   ########.fr       */
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



Hoje é um dia ensolarado ☀️, perfeito para sair e aproveitar o ar livre 🌳. Eu acordei cedo e fui dar uma caminhada pela praia 🚶‍♀️. A vista era incrível, com o mar azul e o sol brilhando no horizonte 🌊. Eu tirei algumas fotos para compartilhar com meus amigos depois 📷.

Depois da caminhada, eu decidi ir ao mercado fazer compras 🛒. Havia muitas pessoas por lá, todas usando máscaras 😷 para se proteger do coronavírus. Eu fiz minhas compras e voltei para casa 🏠. No caminho de volta, parei em uma loja de café ☕️ e comprei uma xícara de café quente para me aquecer.

Chegando em casa, eu liguei o computador 💻 e comecei a trabalhar. Eu tinha muitas tarefas para fazer, mas felizmente eu estava me sentindo muito produtiva hoje. Eu consegui terminar todas as minhas tarefas antes do meio-dia 🕛 e decidi dar uma pausa para almoçar.

Eu preparei uma salada 🥗 e comi enquanto assistia um episódio da minha série favorita na Netflix 📺. Depois do almoço, eu decidi fazer uma pausa na tela do computador e ler um livro 📖. Eu escolhi um romance de época e mergulhei na história.

Quando eu olhei no relógio, percebi que já era tarde 😱. Eu precisava me preparar para o jantar com meus amigos hoje à noite 🍴. Eu tomei um banho e me arrumei. Eu escolhi um vestido bonito 👗 e coloquei alguns brincos 💎.

Eu encontrei meus amigos no restaurante 🍽️ e nós tivemos uma noite incrível juntos. Nós rimos muito e comemos uma comida deliciosa. Depois do jantar, nós decidimos ir a um bar 🍻 para tomar uma bebida. Eu pedi um coquetel 🍹 e nós continuamos a conversar e nos divertir.

Quando finalmente chegou a hora de ir para casa, eu me senti cansada, mas feliz 😊. Eu tinha tido um dia incrível, cheio de atividades e pessoas especiais. Eu me senti grata por ter tantas coisas boas em minha vida e fui para casa dormir 💤.