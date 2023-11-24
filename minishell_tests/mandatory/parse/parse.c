/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:42:19 by gacalaza          #+#    #+#             */
/*   Updated: 2023/11/23 20:20:26 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	finalizepipe_cmd(t_data *data, char	**all_words)
{
	t_cmd	*newnode;
	char	**args;
	char	*cmd;
	int		len;
	int		check;

	if (!all_words)
	{
		ft_error_parse(5);
		return ;
	}
	check = 0;
	len = ft_array_size(all_words);
	cmd = get_cmd(all_words);
	args = NULL;
	if (len > 1)
		args = get_args(all_words, len);
	newnode = createnode_cmd(cmd, args);
	ft_add_back_cmd(&data->cmd, newnode);
}

char	**fixwords(t_token *tokens, char **words)
{
	if (words)
		freearray(words);
	words = get_all_words(tokens);
	if (!words)
		words = ft_error_parse(5);
	return (words);
}

void	cmd_pipe(t_data *data)
{
	t_token	*tmp;
	char	**all_words;

	tmp = data->tokens;
	all_words = get_all_words(data->tokens);
	while (tmp)
	{
		if (tmp->type == PIPE || tmp->next == NULL)
		{
			finalizepipe_cmd(data, all_words);
			if (tmp->next != NULL)
				all_words = fixwords(tmp->next, all_words);
		}
		tmp = tmp->next;
	}
}

char	**get_all_words(t_token *tokens)
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

int	word_has_quotes(char *str)
{
	int	i;
	int	check;
	int	type;

	i = 0;
	type = 0;
	check = 0;
	while(str[i] != '\0' || is_space(str[i]))
	{
		if (check == 0 && is_quote(str[i]))
		{
			type = is_quote(str[i]);
			check++;
		}
		if (check == 1 && is_quote(str[i]) == type)
			check++;
		if (check == 2)
			return (type);
		i++;
	}
	return (FALSE);
}

// char	*remove_quote(char *str, int type)
// {
// 	int		i;
// 	char	*result;
// 	i = 0;
// 	result = malloc(sizeof(char *) * (ft_strlen(str)));
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == )
// 	}
// }

// char	**check_quote(char **all_words)
// {
// 	int	i;

// 	i = 0;
// 	while (all_words[i] != NULL)
// 	{
// 		if (word_has_quotes(all_words[i]))
// 			all_words[i] = remove_quote(all_words[i], word_has_quotes(all_words[i]));
// 	}
// }

	// data->cmd = ft_arraydup(all_words);
void	parsing_it(t_data *data)
{
	char	**all_words;

	if (has_pipe(data) > 0)
		cmd_pipe(data);
	else
	{
		all_words = get_all_words(data->tokens);
		// print_array(all_words, "all_words");
		finalizepipe_cmd(data, all_words);
	}
	printlist(data->cmd, 3);
}
// idea = ter uma struct pra colocar os comandos e argumentos
// deveria incluir um type?
// cada nó seria um pipe

// pensar sobre quando não há argumentos
// lém disso ajustar o printlist para array de tamanho variado no mesmo nó