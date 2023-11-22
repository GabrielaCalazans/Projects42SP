/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:32:37 by gacalaza          #+#    #+#             */
/*   Updated: 2023/11/22 19:32:58 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*trim_process(char *word, int type)
{
	char	*name;

	name = ft_strdup(word);
	if (type == QUOTE_DOUBLE)
		name = ft_strtrim(name, "\"");
	if (type == QUOTE_SINGLE)
		name = ft_strtrim(name, "\'");
	return (name);
}

char	**trim_quote(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		if (find_type(words[i]) == 8
			|| find_type(words[i]) == 9)
			words[i] = trim_process(words[i], find_type(words[i]));
		i++;
	}
	return (words);
}
