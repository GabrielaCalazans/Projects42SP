/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:55:01 by coder             #+#    #+#             */
/*   Updated: 2022/09/10 17:27:21 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	countbig;
	size_t	countlittle;

	size_big = ft_strlen(big);
	count = 0;
	if (!ft_strlen(little))
		return (big);
	while (count < size_big)
	{
		if (big[count] == little[count])
		{
			return ((char *)big + count);
		}		
		count++;
	}
	return (NULL);
}
