/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 23:23:07 by coder             #+#    #+#             */
/*   Updated: 2022/09/08 20:33:31 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t len)
{
	unsigned int	count;
	unsigned char	*strdest;
	unsigned char	*strsrc;

	strdest = (unsigned char *)dest;
	strsrc = (unsigned char *)src;
	count = 0;
	while (count < len)
	{
		strdest[count] = strsrc[count];
		count++;
	}
	while (count < len)
	{
		strdest[count] = '\0';
		count++;
	}
	return (dest);
}
