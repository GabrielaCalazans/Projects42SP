/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:29:51 by coder             #+#    #+#             */
/*   Updated: 2022/09/10 00:00:18 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	count;
	int	size;

	size = ft_strlen(str);
	count = 0;
	while (count < size)
	{
		if (str[count] == (unsigned char)c)
		{
			return ((char *)str + count);
		}		
		count++;
	}
	if (*str == (unsigned char)c)
	{
		return ((char *)str);
	}
	if (!ft_isprint(c))
	{
		return ((char *)str + count);
	}
	return (NULL);
}
