/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:36:31 by gacalaza          #+#    #+#             */
/*   Updated: 2023/11/01 19:35:58 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Function to print the linked list
void	printlist(void *head, int check)
{
	t_token	*temp1;
	t_rdct	*temp2;
	int		j;

	if (!head)
	{
		printf("EMPTY LIST\n");
		return ;
	}
	if (check == 1)
	{
		temp1 = (t_token *) head;
		while (temp1 != NULL)
		{
			printf("NODE - token: %s type: %d\n", temp1->token, temp1->type);
			temp1 = temp1->next;
		}
	}
	else
	{
		temp2 = (t_rdct *) head;
		j = 0;
		while (temp2 != NULL)
		{
			for (int i = 0; i < temp2->nbr_rdcts; i++)
			{
				printf("NODE%i - redirect_type: %i file_name: %s, size str:%zu\n", j,
					temp2->redirects[i], temp2->files[i], ft_strlen(temp2->files[i]));
			}
			j++;
			temp2 = temp2->next;
		}
	}
	printf("\n");
}

void	set_data(t_data *data)
{
	data->tokens = NULL;
	data->rdct = NULL;
	data->env_node = NULL;
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	(void)argv;
	(void)argc;
	if (argc != 1)
		return (1);
	set_data(data);
	create_env(&data, envp);
	prompt(data);
	ft_clear_data(data);
	return (0);
}

	// find_token(argv[1], &tokens);
	// printf("MAIN:");
	// printlist(tokens);
	// find_token("dasda*");
	// find_token("da s da *");
	// find_token("? *");
	// find_token("cat black dog > ");
	// find_token("cat oi, tudo bem? > oi.txt");
	// printf("%d\n", is_redirect('>'));
	// printf("%d\n", is_redirect('<'));
	// printf("%d\n", is_redirect('!'));