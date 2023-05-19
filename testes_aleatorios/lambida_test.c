/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambida_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:41:20 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/18 11:55:06 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Definição do tipo de função esperado
typedef int (*OperacaoMatematica)(int);

// Função que aplica uma operação matemática a um número
int aplicarOperacao(int numero, OperacaoMatematica operacao)
{
	return operacao(numero);
}

// Função que calcula o quadrado de um número
int quadrado(int x)
{
	return x * x;
}

int main(int argc, char *argv[])
{
	int	n;

	if (argc == 2)
	{
		n = atoi(argv[1]);
		OperacaoMatematica funcao = quadrado;

		int resultado = aplicarOperacao(n, funcao);
		printf("%d ao quadrado: %d\n", n, resultado);  // Saída: 25
	}
	else if (argc > 2)
		printf ("Executar com somente um número de argumento ex.: ./a.out 42\n");
	else
		printf ("Executar com pelo menos um número de argumento ex.: ./a.out 42\n");
	return 0;
}

