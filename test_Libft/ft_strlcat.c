/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:18:13 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/21 17:31:23 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	dlen;

	count = 0;
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
