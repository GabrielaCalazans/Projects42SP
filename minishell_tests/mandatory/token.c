/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:12:20 by gacalaza          #+#    #+#             */
/*   Updated: 2023/09/21 22:47:40 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_redirect(char c)
{
	if (c == '<')
		return (1);
	if (c == '>')
		return (2);
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
	if (c == 36)
		return (7);
	return (0);
}

int	is_quote(char c)
{
	if (c == 34)
		return (8);
	if (c == 39)
		return (9);
	return (0);
}

int	is_space(char c)
{
	if (c == 32)
		return (11);
	return (0);
}

int	find_type(char c)
{
	int	i;

	i = 0;
	if (i < is_redirect(c))
	{
		i = is_redirect(c);
		return (i);
	}
	if (i < is_pipe(c))
	{
		i = is_pipe(c);
		return (i);
	}
	if (i < is_flag(c))
	{
		i = is_flag(c);
		return (i);
	}
	if (i < is_dollar(c))
	{
		i = is_dollar(c);
		return (i);
	}
	if (i < is_slash(c))
	{
		i = is_slash(c);
		return (i);
	}
	if (i < is_questionmark(c))
	{
		i = is_questionmark(c);
		return (i);
	}
	if (i < is_quote(c))
	{
		i = is_quote(c);
		return (i);
	}
	if (i < is_space(c))
	{
		i = is_space(c);
		return (i);
	}
	else
	{
		i = 10;
		return (i);
	}
}

int	word_len(char *str)
{
	int	len;
	
	len = 0;
	while (*str && find_type(*str) == 10)
	{
		len++;
		str++;
		printf("Word len char: %c type:%d\n", *str, find_type(*str));
	}
	return (len);
}


void	create_word_token(char *str)
{
	printf("FUNC: create_word_token: %s\n", str);
}

void	create_token(char *str)
{
	printf("FUNC: create_token: %s\n", str);
}

void	find_token(char *str)
{
	int	check;

	check = find_type(*str);
	while (*str)
	{
		if (check == 10)
		{
			printf("create_word_token: %c\n", *str);
			create_word_token(str);
			printf("%d\n", word_len(str));
			if (*(str + word_len(str) - 1) != '\0')
				*str = *(str + word_len(str) - 1);
			else
				break ;
			printf("create_word_token: %s\n", str);
		}
		if (check > 0 && check != 10)
		{
			create_token(str);
			printf("create_token: %c\n", *str);
		}
		str++;
		check = find_type(*str);
	}
}
