/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:55:06 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/18 14:52:01 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	prompt(void)
{
	t_init	*tmp;

	tmp = (t_init *)malloc(sizeof(t_init));
		if (tmp == NULL)
		{
			perror("Memory allocation failure at prompt func.");
			exit(EXIT_FAILURE);
		}
	while (1)
	{
		
		tmp->prompt_input = readline("chora$> ");
		if (tmp->prompt_input == NULL)
		{
			printf("\n");
			break;
		}
		if (tmp->prompt_input[0] != '\0')
		{
			// Adiciona o comando à história se não estiver vazio
			add_history(tmp->prompt_input);
			// Agora 'input' contém o comando digitado pelo usuário
			printf("That's what he said: %s\n", tmp->prompt_input);
		}
		free(tmp->prompt_input);
		tmp->prompt_input = NULL;
	}
	rl_clear_history();
}
