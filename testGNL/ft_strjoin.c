/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:55:01 by gacalaza          #+#    #+#             */
/*   Updated: 2022/10/25 22:41:43 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strnew;
	size_t	len_s1;
	size_t	len_s2;
	int		i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	strnew = (char *) malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!strnew)
		return (NULL);
	i = -1;
	if (s1)
	{
		while (s1[++i])
			strnew[i] = s1[i];
	}
	i = -1;
	while (s2[++i])
	{
		strnew[len_s1] = s2[i];
		len_s1++;
	}
	strnew[len_s1] = '\0';
return (strnew);
}
