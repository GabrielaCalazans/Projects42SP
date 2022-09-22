/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:55:01 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/22 23:44:36 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	
	if (len_s1 && len_s2 == 0)
		return (NULL);
	strjoin = (char *) malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!strjoin)
		return (NULL);
	ft_strlcat(strjoin, s1, len_s1 + len_s2);
	ft_strlcat(strjoin, s2, len_s1 + len_s2);
	return (strjoin);
}
