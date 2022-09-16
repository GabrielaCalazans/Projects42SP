/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:18:13 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/16 20:57:22 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	dlen;

	count = 0;
	dlen = ft_strlen(src);
	while (*dst && size > 0 && size--)
	{
		dst++;
		count++;
	}
	while (*src && size > 1 && size--)
	{
		*dst++ = *src++;
	}
	if (size == 1)
		*dst = '\0';
	return (dlen + count);
}
