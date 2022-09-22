/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:18:13 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/22 20:49:05 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	dlen;
	int		i;

	count = 0;
	i = 0;
	dlen = ft_strlen(src);
	while (*dest && size > 0 && size--)
	{
		dest++;
		count++;
	}
	while (*src && size > 1 && size--)
	{
		*dest++ = *src++;
	}
	if (size == 1)
		*dest = '\0';
	return (dlen + count);
}
