/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:09:40 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/21 16:43:45 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	size;

	if (!s)
		return (NULL);
	size_s = ft_strlen(s);
	while (count < len)
	{
		if (count == start)
		{
			return ((char *)s + count);
		}		
		count++;
	}
	if (*str == start)
	{
		return ((char *)str);
	}
	if (!ft_isprint(c))
	{
		return ((char *)str + count);
	}
	return (NULL);
}
