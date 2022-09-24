/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:09:40 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/23 00:01:47 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	size_s;
	unsigned int	size_sps;

	if (!s)
		return (0);
	size_s = ft_strlen(s);
	size_sps = ft_strlen(s + start);
	if (size_s < start)
		{
			if (!(substr = (char *)malloc(sizeof(char))))
				return (NULL);
			substr[0] = '\0';
			return (substr);
		}
	if ((size_sps < len))
		len = size_sps;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (0);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
