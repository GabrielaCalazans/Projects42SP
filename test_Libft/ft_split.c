/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:37:55 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/29 01:22:38 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkrow(char const *s, char c)
{
	int	rows;
	int	count;

	while (s[count] != '\0')
	{
		if (s[count] != c && s[count + 1] == c || s[count] != c && s[count + 1] == '\0')
			rows++;
		count++;
	}
	return (rows);
}

void int checkcol(char const *s, char c, int rows, **cols)
{
	int	count;
	int	strlen;
	int	colpos;

	count = 0;
	rowpos = 0;
	strlen = 0;
	*cols = (char **)malloc(rows * sizeof(int));
	while (s[count] != '\0')
	{
		if (s[count] != c)
			strlen++;
		if (s[count] != c && s[count + 1] == c || s[count] != c && s[count + 1] == '\0')
			*col[rowpos] = strlen;
			rowpos++;
			strlen = 0;
		count++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		rows;
	int		cols;

	rows = checkrow(s, c);
	cols = (s, c, rows, array)
	
}
