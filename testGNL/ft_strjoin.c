/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:55:01 by gacalaza          #+#    #+#             */
/*   Updated: 2022/10/23 22:19:47 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	len_s1;
	size_t	len_s2;
	int		i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	strjoin = (char *) malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!strjoin)
		return (NULL);
	i = -1;
	printf("\njoin1:%s\n", strjoin);
	if (s1[0] != '\0')
	{
		while (s1[++i])
			strjoin[i] = s1[i];
	}
	printf("\njoin2:%s\n", strjoin);
	i = -1;
	while (s2[++i])
	{
		strjoin[len_s1] = s2[i];
		len_s1++;
	}
	printf("\njoin3:%s\n", strjoin);
	strjoin[len_s1] = '\0';
return (strjoin);
}
