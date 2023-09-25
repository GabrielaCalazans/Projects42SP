/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:12:20 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/25 20:40:05 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*define_type(char *str)
{
	int	i;

	i = find_type(str);
	if (i == 1)
		return (ft_strdup("redirect_in"));
	if (i == 2)
		return (ft_strdup("redirect_out"));
	if (i == 3)
		return (ft_strdup("pipe"));
	if (i == 4)
		return (ft_strdup("flag"));
	if (i == 5)
		return (ft_strdup("slash"));
	if (i == 6)
		return (ft_strdup("question"));
	if (i == 7)
		return (ft_strdup("dollar"));
	if (i == 8)
		return (ft_strdup("double_quote"));
	if (i == 9)
		return (ft_strdup("single_quote"));
	if (i == 10)
		return (ft_strdup("word"));
	if (i == 11)
		return (ft_strdup("space"));
	if (i == 12)
		return (ft_strdup("append"));
	if (i == 13)
		return (ft_strdup("heredoc"));
	return ("error");
}

int	word_len(char *str)
{
	int	len;

	len = 0;
	while (*str && find_type(str) == 10)
	{
		len++;
		str++;
	}
	return (len);
}

t_token	*create_word_token(char *str, int len)
{
	t_token	*newnode;
	char	*token;
	char	*type;
	int		i;

	i = 0;
	token = ft_substr(str, 0, len);
	type = define_type(&str[i]);
	newnode = createnode(token, type);
	// printf("FUNC: create_word_token: %s \t len: %d \t type: %s\n", token, len, type);
	return (newnode);
}

t_token	*create_token(char *str)
{
	t_token	*newnode;
	char	*token;
	char	*type;
	int		i;
	int		len;

	i = 0;
	len = 1;
	if (find_type(&str[i]) == 12 || find_type(&str[i]) == 13)
			len += 1;
	token = ft_substr(str, 0, len);
	type = define_type(&str[i]);
	newnode = createnode(token, type);
	// printf("FUNC: create_token: %s \t type: %s\n", token, type);
	return (newnode);
}

void	find_token(t_data *data)
{
	int		check;
	int		i;
	t_token	*newnode;

	if (data->prompt_in == NULL)
	{
		printf("NO STR");
		return ;
	}
	i = 0;
	while (data->prompt_in[i] != '\0')
	{
		check = find_type(&data->prompt_in[i]);
		if (check == 10)
		{
			newnode = create_word_token(&data->prompt_in[i], word_len(&data->prompt_in[i]));
			if (!newnode)
				break ;
			ft_add_back(&data->tokens, newnode);
			i += word_len(&data->prompt_in[i]);
		}
		if (check > 0 && check != 10)
		{
			newnode = create_token(&data->prompt_in[i]);
			if (!newnode)
				break ;
			ft_add_back(&data->tokens, newnode);
			i++;
		}
		// if (data->prompt_in[i] == '\0' || data->prompt_in[i])
		// 	break ;
	}
	printlist(data->tokens);
	ft_clear(&data->tokens);
}

// t_token	create_lst(char *str, t_token	**tokens)
// {
// 	int		check;
// 	int		i;

	
// }
