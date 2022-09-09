/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 01:32:45 by coder             #+#    #+#             */
/*   Updated: 2022/09/09 22:39:38 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void	*dest, const void	*src, size_t len)
{
	char	*strdest;
	char	*strsrc;
	size_t	count;

	strdest = (char *)dest;
	strsrc = (char *)src;
	count = 0;
	if (strsrc == NULL)
		return (dest);
	if (strsrc < strdest)
	{
		while (len--)
		{
			*(strdest + len) = *(strsrc + len);
		}
	}
	else
	{
		while (count < len)
		{
			*(strdest + count) = *(strsrc + count);
			count++;
		}
	}
	return (dest);
}
