/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:55:06 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/16 16:08:11 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	prompt(t_init *ptr)
{
	t_init	*tmp;

	tmp = ptr;
	while (1)
	{
		tmp->prompt_input = readline("chora$> ");
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
}
