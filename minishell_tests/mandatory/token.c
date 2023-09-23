/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:12:20 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/23 19:50:27 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_redirect(char c)
{
	if (c == '<')
		return (1);
	if (c == '>')
		return (2);
	else
		return (0);
}

int	is_pipe(char c)
{
	if (c == '|')
		return (3);
	return (0);
}

int	is_flag(char c)
{
	if (c == '-')
		return (4);
	return (0);
}

int	is_slash(char c)
{
	if (c == '/')
		return (5);
	return (0);
}

int	is_questionmark(char c)
{
	if (c == '?')
		return (6);
	return (0);
}

int	is_dollar(char c)
{
	if (c == '$')
		return (7);
	return (0);
}

int	is_quote(char c)
{
	if (c == '\"')
		return (8);
	if (c == '\'')
		return (9);
	return (0);
}

int	is_space(char c)
{
	if (c == ' ')
		return (11);
	return (0);
}

int	find_type(char c)
{
	if (0 < is_redirect(c))
		return (is_redirect(c));
	if (0 < is_pipe(c))
		return (is_pipe(c));
	if (0 < is_flag(c))
		return (is_flag(c));
	if (0 < is_dollar(c))
		return (is_dollar(c));
	if (0 < is_slash(c))
		return (is_slash(c));
	if (0 < is_questionmark(c))
		return (is_questionmark(c));
	if (0 < is_quote(c))
		return (is_quote(c));
	if (0 < is_space(c))
		return (is_space(c));
	else
		return (10);
}

char	*define_type(char c)
{
	if (find_type(c) == 1)
		return (ft_strdup("redirect_in"));
	if (find_type(c) == 2)
		return (ft_strdup("redirect_out"));
	if (find_type(c) == 3)
		return (ft_strdup("pipe"));
	if (find_type(c) == 4)
		return (ft_strdup("flag"));
	if (find_type(c) == 5)
		return (ft_strdup("slash"));
	if (find_type(c) == 6)
		return (ft_strdup("question"));
	if (find_type(c) == 7)
		return (ft_strdup("dollar"));
	if (find_type(c) == 8)
		return (ft_strdup("double_quote"));
	if (find_type(c) == 9)
		return (ft_strdup("single_quote"));
	if (find_type(c) == 10)
		return (ft_strdup("word"));
	if (find_type(c) == 11)
		return (ft_strdup("space"));
}

int	word_len(char *str)
{
	int	len;
	
	len = 0;
	while (*str && find_type(*str) == 10)
	{
		len++;
		str++;
	}
	return (len);
}

void	create_word_token(t_token **tokens, char *str, int len)
{
	t_token	*newnode;
	char	*token;
	int		*type;
	int		j;

	i = 0;
	token = ft_substr(str, 0, len-1);
	type = define_type(str[i]);
	*tokens = createnode(nbr, index);
	while (str[++i] != NULL)
	{
		nbr = ft_atoi_error(str[i]);
		index = find_index(str, nbr, j);
		newnode = createnode(nbr, index);
		if (!newnode)
			break ;
		ft_add_back(a, newnode);
	}
	printf("FUNC: create_word_token: %s \tlen: %d\n", str, len);
}

void	create_token(t_token **tokens, char *str)
{
	printf("FUNC: create_token: %s\n", str);
}

void	find_token(char *str)
{
	int		check;
	int		i;
	t_token	*tokens;

	i = 0;
	while (str[i] != '\0')
	{
		check = find_type(str[i]);
		if (check == 10)
		{
			create_word_token(&tokens, &str[i], word_len(&str[i]));
			i += word_len(&str[i]);
		}
		if (check > 0 && check != 10)
		{
			create_token(&str[i]);
			i++;
		}
	}
}
