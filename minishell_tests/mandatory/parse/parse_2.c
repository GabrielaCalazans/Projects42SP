/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:42:19 by gacalaza          #+#    #+#             */
/*   Updated: 2023/11/22 00:54:04 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**get_all_words2(t_token *tokens)
{
	char	**all_words;
	int		check;
	// int		pipes;

	check = 0;
	// pipes = has_pipe_yet(tokens);
	all_words = NULL;
	if (has_redirect_pipe(tokens))
		check = 1;
	if (has_d_redirec_p(tokens))
		check += 2;
	if (check == 0)
		all_words = get_words(tokens, nb_words(tokens));
	if (check == 1)
		all_words = get_words_one(tokens);
	if (check == 2)
		all_words = get_words_two(tokens);
	if (check == 3)
		all_words = get_words_three(tokens);
	if (!all_words)
		ft_error_parse(2);
	return (all_words);
}

void	print_array2(char **array, char *type)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i] != NULL)
	{
		printf("%s[%i]: %s\n", type, i, array[i]);
		i++;
	}
	printf("\n");
}

void	finalizepipe_cmd(t_data *data, char	**all_words)
{
	t_cmd	*newnode;
	char	**cmd_args;
	char	**cmd;
	int		len;
	int		check;

	if (!all_words)
	{
		ft_error_parse(5);
		return ;
	}
	check = 0;
	len = ft_array_size(all_words);
	cmd = n_get_cmd(all_words, len);
	if (t_array_size(cmd) > 1)
		check = 1;
	cmd_args = get_cmd_args(all_words, check, len);
	newnode = createnode_cmd(cmd, cmd_args);
	ft_add_back_cmd(&data->pcmd, newnode);
}

char	**fixwords(t_token tokens, char **words)
{
	if (words)
		ft_free_array(words);
	words = get_all_words(tokens);
	if (!words)
		words = ft_error_parse(5);
	return (words);
}

void	cmd_pipe(t_data *data)
{
	t_token	tmp;
	char	**all_words;
	tmp = data->token;

	all_words = get_all_words(data->tokens);
	while (tmp)
	{
		if (tmp->type == PIPE || tmp->next == NULL)
		{
			finalizepipe_cmd(data, all_words)
			if (tmp->next != NULL)
				all_words = fix_words(tmp->next);
		}
		tmp = tmp->next;
	}
}

	// data->cmd = ft_arraydup(all_words);
void	parsing_it2(t_data *data)
{
	char	**all_words;

	if (has_pipe(data) > 0)
	{
		cmd_pipe(data);
		print_array(data->cmd, "cmd");
		print_array(data->cmd_args, "cmd_args");
	}
	else
	{
		all_words = get_all_words(data->tokens);
		get_cmd(data, all_words);
	}
}

// pensar sobre quando não há argumentos
// lém disso ajustar o printlist para array de tamanho variado no mesmo nó