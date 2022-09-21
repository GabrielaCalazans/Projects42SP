/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:09:40 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/21 22:45:02 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	size_s;
	size_t			i;

	i = 0;
	if (!s)
		return (NULL);
	size_s = ft_strlen(s);
	if (start > size_s)
		return (NULL);
	if ((size_s - start) <= len)
		substr = malloc(sizeof(char) * (len + 1));
	else
		substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	ft_memcpy(substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}
