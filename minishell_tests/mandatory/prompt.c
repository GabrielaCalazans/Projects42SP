/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:55:06 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/23 21:55:28 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Adiciona o comando à história se não estiver vazio
// add_history(tmp->prompt_input);
// Agora 'input' contém o comando digitado pelo usuário
void	prompt(void)
{
	t_prompt	*tmp;

	tmp = (t_prompt *)malloc(sizeof(t_prompt));
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
			break ;
		}
		if (tmp->prompt_input[0] != '\0')
		{
			add_history(tmp->prompt_input);
			printf("That's what he said: %s\n", tmp->prompt_input);
		}
		free(tmp->prompt_input);
		tmp->prompt_input = NULL;
	}
	rl_clear_history();
}
