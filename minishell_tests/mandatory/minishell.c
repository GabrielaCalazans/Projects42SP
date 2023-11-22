/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:36:31 by gacalaza          #+#    #+#             */
/*   Updated: 2023/11/22 00:52:01 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Function to print the linked list
void	printlist(void *head, int check)
{
	t_token	*temp1;
	t_rdct	*temp2;
	t_cmd	*temp3;
	int		j;
	int		i;

	if (!head)
	{
		printf("EMPTY LIST\n");
		return ;
	}
	if (check == 1)
	{
		temp1 = (t_token *)head;
		while (temp1 != NULL)
		{
			printf("NODE - token: %s type: %d\n", temp1->token, temp1->type);
			temp1 = temp1->next;
		}
	}
	if (check == 2)
	{
		temp3 = (t_cmd *)head;
		j = 0;
		while (temp3 != NULL)
		{
			i = 0;
			while (temp3->cmd)
			{
				
				printf("NODE %i - cmd: %i cmd_args: %s\n", j,
					temp3->cmd[i], temp3->cmd_args[i]);
				i++;
			}
			j++;
			temp3 = temp3->next;
		}
	}
	printf("\n");
	}
	else
	{
		temp2 = (t_rdct *)head;
		j = 0;
		while (temp2 != NULL)
		{
			i = 0;
			while (i < temp2->nbr_rdcts)
			{
				printf("NODE %i - rdct: %i file: %s, size str:%zu\n", j,
					temp2->redirects[i], temp2->files[i],
					ft_strlen(temp2->files[i]));
				i++;
			}
			j++;
			temp2 = temp2->next;
		}
	}
	printf("\n");
}

void	set_data(t_data *data, char *envp[], char *argv[])
{
	(void)argv;
	data->tokens = NULL;
	data->rdct = NULL;
	data->env_node = NULL;
	data->pcmd = NULL;
	create_env(&data, envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	*data;

	if (argc != 1)
		return (1);
	data = malloc(sizeof(t_data));
	set_data(data, envp, argv);
	while (1)
	{
		data->out_fd = STDOUT_FILENO;
		data->in_fd = STDIN_FILENO;
		prompt_new(data);
		mini_start(data);
		ft_clear_data(data);
	}
	// prompt(data);
	// ft_clear_data(data);
	rl_clear_history();
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