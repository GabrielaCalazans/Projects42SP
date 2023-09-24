/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:55:06 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/24 18:16:46 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Adiciona o comando à história se não estiver vazio
// add_history(tmp->prompt_input);
// Agora 'input' contém o comando digitado pelo usuário
void	prompt(void)
{
	char	*prompt_input;
	t_token	*tokens;

	while (1)
	{
		prompt_input = readline("chora$> ");
		if (prompt_input == NULL)
		{
			printf("\n");
			break ;
		}
		if (prompt_input[0] != '\0')
		{
			add_history(prompt_input);
			printf("prompt %s\n", prompt_input);
		}
		// printlist(tokens);
		// tokens = create_lst(prompt_input, &tokens);
		find_token(prompt_input, &tokens);
		// printlist(tokens);
		free(prompt_input);
		// ft_clear(&tokens);
		prompt_input = NULL;
	}
	rl_clear_history();
}
