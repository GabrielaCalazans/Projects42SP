/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:42:19 by gacalaza          #+#    #+#             */
/*   Updated: 2023/11/09 16:37:56 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// void	move_token_cont(t_data *data, t_token *newlist)
// {
// 	t_token	*head;

// 	head = data->tokens;
// 	while (head->next != NULL)
// 	{
// 		if (head->type != REDIRECT_IN && head->type != REDIRECT_OUT)
// 			head = head->next;
// 		else
// 			break ;
// 	}
// 	head->next = newlist;
// 	data->tokens = head;
// }

// t_token	*jump_word(t_token *tokens)
// {
// 	printf("CHEGUEI AQUI3");
// 	if (tokens == NULL)
// 		return (NULL);
// 	if (is_path(tokens))
// 	{
// 		if (tokens->next)
// 			tokens = tokens->next;
// 		while (tokens)
// 		{
// 			if (tokens->type != SLASH && tokens->type != WORD)
// 				break ;
// 			tokens = tokens->next;
// 		}
// 		return (tokens);
// 	}
// 	return (tokens);
// }

// void	process_rdct_move(t_token *tmp, t_token *prev, t_token *current)
// {
// 	while (tmp)
// 	{
// 		if (tmp->type == C_SPACE || tmp->type == H_TAB)
// 		{
// 			while (tmp->type == C_SPACE || tmp->type == H_TAB)
// 				tmp = tmp->next;
// 		}
// 		if (tmp->type == QUOTED_WORD)
// 		{
// 			tmp = tmp->next;
// 			break ;
// 		}
// 		if (tmp->type == WORD || tmp->type == SLASH)
// 		{
// 			tmp = jump_word(tmp);
// 			break ;
// 		}
// 		else
// 			break ;
// 	}
// 	if (tmp)
// 	{
// 		while (tmp)
// 		{
// 			current = tmp;
// 			ft_add_back(&prev, current);
// 			prev->next = NULL;
// 			tmp = tmp->next;
// 		}
// 	}
// 	// printlist(tmp, 1);
// 	printf("PREV");
// 	printlist(prev, 1);
// 	return ;
// }

// void	check_move(t_token *tmp, t_token *prev, int type, t_token *current)
// {
// 	printf("CHEGUEI AQUI2");
// 	if (type == REDIRECT_IN || type == REDIRECT_OUT)
// 		process_rdct_move(tmp, prev, current);
// }

// void	move_tokens(t_data *data, int type)
// {
// 	t_token	*tmp;
// 	t_token	*prev;
// 	t_token	*current;

// 	tmp = data->tokens;
// 	printf("cheguei aqui %s\t%i\n", tmp->token, tmp->type);
// 	prev = NULL;
// 	if (!tmp)
// 		return ;
// 	tmp = jump_white_spaces(tmp);
// 	while(tmp)
// 	{
// 		printf("cheguei aqui %s\t%i", tmp->token, tmp->type);
// 		if (tmp->type == type)
// 		{
// 			check_move(tmp, prev, type, current);
// 		}
// 		printf("cheguei aqui %s\t%i", tmp->token, tmp->type);
// 		if (tmp)
// 		{
// 			current = tmp;
// 			ft_add_back(&prev, current);
// 			prev->next = NULL;
// 			// printlist(prev, 1);
// 			tmp = tmp->next;
// 		}
// 		printf("cheguei aqui %s\t%i", tmp->token, tmp->type);
// 		// tmp = tmp->next;
// 	}
// }

// data->cmd_args = take_q_name(&*tmp);

// char	**case_redirec_only(t_token *tokens, int pipes)
// {
// 	t_token	*tmp;

// 	tmp = tokens;
// 	while (tmp)
// 	{
// 		if (tmp->type == PIPE)
// 			break ;
// 		if (tmp->token == WORD)
// 	}
// }


int	has_d_redirec_p(t_token *tokens)
{
	t_token	*temp;
	int		r_rdrcts;

	temp = tokens;
	r_rdrcts = 0;
	while (temp)
	{
		if (temp->type == HEREDOC || temp->type == APPEND)
			r_rdrcts++;
		if (temp->type == PIPE)
			break ;
		temp = temp->next;
	}
	return (r_rdrcts);
}

int	nb_words(t_token *tokens)
{
	t_token	*temp;
	int		words;

	temp = tokens;
	words = 0;
	while (temp && temp->type != PIPE)
	{
		if (temp->type == WORD)
			words++;
		temp = temp->next;
	}
	return (words);
}

char	**get_words(t_token *tokens, int len)
{
	t_token	*temp;
	int		i;
	char	**words;

	i = 0;
	temp = tokens;
	words = malloc(sizeof(char **) * (len + 1));
	if (!words)
	{
		printf("erro malloc.\n");
		return (NULL);
	}
	while (temp)
	{
		if (temp->type == WORD || is_special_case(temp->type, 2)
			|| temp->type == QUOTED_WORD)
		{
			words[i] = ft_strdup(temp->token);
			i++;
		}
		temp = temp->next;
	}
	words[i] = NULL;
	return (words);
}

char	**get_all_words(t_token *tokens)
{

	char	**all_words;
	int		check;
	int		pipes;

	check = 0;
	pipes = has_pipe_yet(tokens);
	all_words = NULL;
	if (has_redirect_pipe(tokens))
		check = 1;
	if (has_d_redirec_p(tokens))
		check += 2;
	if (check == 0)
		all_words = get_words(tokens, nb_words(tokens));
	// if (check == 1)
	// 	all_words = fazafunçaõquepegapalavracomredirect;
	// if (check == 2)
	// 	all_words = fazafunçaõquepegapalavrasemosdoubleredirect;
	// if (check == 3)
	// 	all_words = fazafunçaõquepegapalavrasemosodoistrecos;
	if (!all_words)
		printf ("DEU RUIM.\n");
	return (all_words);
}

void	parsing_it(t_data *data)
{
	int		i;
	char	**all_words;

	i = 0;
	all_words = get_all_words(data->tokens);
	// data->cmd = ft_strdup_array(all_words);
	while (all_words[i] != NULL)
	{
		printf("string[%i]: %s\n", i, all_words[i]);
		i++;
	}
}
