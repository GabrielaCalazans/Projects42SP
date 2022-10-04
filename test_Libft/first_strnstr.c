/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_strnstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:45:08 by gacalaza          #+#    #+#             */
/*   Updated: 2022/10/04 19:29:17 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count;
	size_t	count_little;
	size_t	count_big;
	int		match;
	size_t	size_little;

	size_little = ft_strlen(little);
	count = 0;
	match = 1;
	if (0 == ft_strlen(little))
		return ((char *)big);
	while (*(big + count) && count < len)
	{
		count_little = 0;
		if (*(big + count) == *(little + 0))
		{
			count_big = count;
			match = 1;
			while (*(big + count_big) && *(little + count_little)
				&& count_big < len && count_little < len)
			{
				if (*(big + count_big++) != *(little + count_little++))
				{
					match = 0;
				}
				if (match == 1 && size_little == count_little)
				{
					return ((char *)big + count);
				}
			}
		}
		count++;
	}
	return (NULL);
}
