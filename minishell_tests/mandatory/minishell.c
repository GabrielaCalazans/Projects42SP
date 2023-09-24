/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:36:31 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/24 18:13:25 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Function to print the linked list
void	printlist(t_token *head)
{
	t_token	*temp;

	if (!head)
		printf("EMPTY");
	temp = head;
	while (temp != NULL)
	{
		printf("NODE - token: %s type: %s\n", temp->token, temp->type);
		temp = temp->next;
	}
	printf("\n");
}


int	main(int argc, char *argv[], char *envp[])
{
	// t_token	*tokens;
	(void)argv;
	(void)envp;
	(void)argc;

	// if (argc != 1)
	// 	return (1);
	prompt();
	// find_token(argv[1], &tokens);
	// printf("MAIN:");
	// printlist(tokens);
	return (0);
}

	// find_token("dasda*");
	// find_token("da s da *");
	// find_token("? *");
	// find_token("cat black dog > ");
	// find_token("cat oi, tudo bem? > oi.txt");
	// printf("%d\n", is_redirect('>'));
	// printf("%d\n", is_redirect('<'));
	// printf("%d\n", is_redirect('!'));