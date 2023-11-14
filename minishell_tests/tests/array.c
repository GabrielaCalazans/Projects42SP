/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:38:49 by gacalaza          #+#    #+#             */
/*   Updated: 2023/11/13 22:03:41 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/minishell.h"

char	*take_quoted_name(t_token *tokens, int len)
{
	char	*name;
	t_token	*temp;
	size_t	word_size;

	temp = tokens->next;
	if (!has_another_quote(tokens, tokens->type))
	{
		ft_error_redirect(2);
		return (NULL);
	}
	word_size = quoted_word_size(temp, len);
	name = ft_strdup(temp->token);
	name = get_name_quoted(temp, name, len);
	if (ft_strlen(name) != word_size)
	{
		ft_error_redirect(3);
		return (NULL);
	}
	return (name);
}

char	**freearray(char **array)
{
	size_t	i;
	size_t	sizearray;

	sizearray = 0;
	while (array[sizearray] != NULL)
	{
		sizearray++;
	}
	i = 0;
	if (i < sizearray)
	{
		while (array[i])
		{
			free(array[i]);
			array[i] = NULL;
			i++;
		}
	}
	if (!array)
		return (NULL);
	return (array);
}

int	ft_array_size(char **array)
{
	int		length;

	length = 0;
	while (array[length] != NULL)
		length++;
	return (length);
}

// char	**ft_arraydup(char **array)
// {
// 	int		length;
// 	int		i;
// 	char	**array_copy;

// 	if (array == NULL)
// 		return (NULL);
// 	length = ft_array_size(array);
// 	i = -1;
// 	array_copy = (char **)malloc(sizeof(char *) * (length + 1));
// 	if (array_copy == NULL)
// 		return (NULL);
// 	while (++i < length)
// 	{
// 		if (array[i] != NULL)
// 		{
// 			array_copy[i] = ft_strdup(array[i]);
// 			if (array_copy[i] == NULL)
// 			{
// 				freearray(array_copy);
// 				return (NULL);
// 			}
// 		}
// 		else
// 			array_copy[i] = NULL;
// 	}
// 	array_copy[length] = NULL;
// 	return (array_copy);
// }

char	**ft_copy_array(char **array, int length)
{
	int		i;
	char	**array_copy;

	array_copy = (char **)malloc(sizeof(char *) * (length + 1));
	if (array_copy == NULL)
		return (NULL);
	i = -1;
	while (++i < length)
	{
		if (array[i] != NULL)
		{
			array_copy[i] = ft_strdup(array[i]);
			if (array_copy[i] == NULL)
			{
				freearray(array_copy);
				return (NULL);
			}
		}
		else
			array_copy[i] = NULL;
	}
	array_copy[length] = NULL;
	return (array_copy);
}

char	**ft_arraydup(char **array)
{
	int		length;

	if (array == NULL)
		return (NULL);
	length = ft_array_size(array);
	return (ft_copy_array(array, length));
}

int	main(void)
{
	char	*original_array[] = {"one", "two", "three", NULL};
	char	**copy_array;
	int		i;

	copy_array = ft_arraydup(original_array);
	if (copy_array)
	{
		i = 0;
		while (copy_array[i] != NULL)
		{
			printf("%s\n", copy_array[i]);
			i++;
		}
		freearray(copy_array);
	}
	return (0);
}
