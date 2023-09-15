/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:36:31 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/15 20:17:30 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int argc, char *argv[], char* envp[])
{
	char *input;
	
	(void)argv;
	(void)envp;
	if (argc != 1)
		return (1);
	while (1)
	{
		input = readline("chora$ ");
		if (input == NULL)
		{
			printf("\n");
			break;
		}
		if (input[0] != '\0')
		{
			// Adiciona o comando à história se não estiver vazio
			add_history(input);
			// Agora 'input' contém o comando digitado pelo usuário
			printf("That's what she said: %s\n", input);
		}
		free(input);
		input = NULL;
	}
	return 0;
}
