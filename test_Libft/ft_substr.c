/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:09:40 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/24 01:07:02 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	subcount;
	size_t	count;
	size_t	size_s;

	count = 0;
	subcount = 0;
	size_s = ft_strlen(s);
	if (size_s < start)
	{
		if (!(substr = (char *)malloc(sizeof(*s))))
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	else if (size_s < len)
		substr = (char *)malloc(sizeof(char) * size_s + 1);
	else if (len == size_s)
		substr = (char *)malloc(sizeof(char) * size_s - start + 1);
	else
		substr = (char *)malloc(sizeof(char) * len + 1);
	if (!substr)
		return (NULL);
	while (s[count])
	{
		if (count >= start && subcount < len)
		{
			substr[subcount++] = s[count];
		}
		count++;
	}
	substr[subcount] = '\0';
	return (substr);
}
