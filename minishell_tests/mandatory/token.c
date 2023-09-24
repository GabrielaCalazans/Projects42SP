/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:12:20 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/23 22:00:34 by gacalaza         ###   ########.fr       */
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

t_token	*create_word_token(t_token **tokens, char *str, int len)
{
	t_token	*newnode;
	char	*token;
	int		*type;
	int		i;

	i = 0;
	token = ft_substr(str, 0, len);
	type = define_type(&str[i]);
	*tokens = createnode(token, type);
	printf("FUNC: create_word_token: %s \tlen: %d\n", str, len);
	return (newnode);
}

t_token	*create_token(t_token **tokens, char *str)
{
	t_token	*newnode;
	char	*token;
	int		*type;
	int		i;
	int		len;

	i = 0;
	len = 1;
	if (find_type(&str[i]) == 1 || find_type(&str[i]) == 2)
	{
		if (str[i] == str[i + 1])
			len += 1;
	}
	token = ft_substr(str, 0, len);
	type = define_type(&str[i]);
	*tokens = createnode(token, type);
	printf("FUNC: create_word_token: %s \tlen: %d\n", str);
	return (newnode);
}

void	find_token(char *str)
{
	int		check;
	int		i;
	t_token	*tokens;
	t_token	*newnode;

	i = 0;
	while (str[i] != '\0')
	{
		check = find_type(&str[i]);
		if (check == 10)
		{
			newnode = create_word_token(&tokens, &str[i], word_len(&str[i]));
			ft_add_back(tokens, newnode);
			i += word_len(&str[i]);
		}
		if (check > 0 && check != 10)
		{
			newnode = create_token(&tokens, &str[i]);
			ft_add_back(tokens, newnode);
			i++;
		}
	}
}
