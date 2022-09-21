/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:43:45 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/20 20:56:22 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
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
