/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:00:10 by gacalaza          #+#    #+#             */
/*   Updated: 2023/11/01 15:26:50 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*take_q_name(t_token *tokens)
{
	int		type;
	char	*name;

	type = find_type(tokens->token);
	name = ft_strdup(tokens->token);
	if (type == QUOTE_DOUBLE)
		name = ft_strtrim(name, "\"");
	if (type == QUOTE_SINGLE)
		name = ft_strtrim(name, "\'");
	return (name);
}

int	*ft_intdup(int *array, int size)
{
	int		*array_copy;
	int		i = 0;

	if (array == NULL)
		return (NULL);
	array_copy = (int *)malloc(sizeof(int) * size);
	if (array_copy == NULL)
		return (NULL);
	while (i < size)
	{
		array_copy[i] = array[i];
		i++;
	}
	return (array_copy);
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

char	**ft_strdup_array(char **array)
{
	int		length;

	if (array == NULL)
		return (NULL);
	length = ft_array_size(array);
	return (ft_copy_array(array, length));
}
