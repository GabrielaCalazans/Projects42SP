/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:44:47 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/19 19:45:05 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	srclen;

	count = 0;
	srclen = ft_strlen(src);
	if (srclen + 1 < size)
	{
		ft_memcpy(dst, src, srclen + 1);
	}
	else if (size > 1)
	{
		ft_memcpy(dst, src, size - 1);
	}
	else if (size == 1)
	{
		dst[size - 1] = '\0';
	}
	return (srclen);
}
