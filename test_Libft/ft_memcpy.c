/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:43:35 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/12 19:43:37 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
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
