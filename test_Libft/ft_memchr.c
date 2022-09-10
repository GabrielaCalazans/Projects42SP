/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 23:34:32 by coder             #+#    #+#             */
/*   Updated: 2022/09/11 00:50:57 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	size_t		count;
	size_t		size;
	const char	*point_str;

	size = len -1;
	count = 0;
	point_str = (const char *)str;
	if (len <= 0)
	{
		return (NULL);
	}
	while (count < size)
	{
		if (point_str[count] == (char)c)
		{
			return ((char *)point_str + count);
		}		
		count++;
	}
	if (point_str[count] == (const char)c)
	{
		return ((char *)point_str + count);
	}
	return (NULL);
}
