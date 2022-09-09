/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:55:01 by coder             #+#    #+#             */
/*   Updated: 2022/09/09 02:25:25 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	count;
	size_t size_big;
	
	size_big = ft_strlen(big);
	count = 0;
	if (0 == size_big)
		return (str); //in case of void point
	while (big[count])
	{
		if (big[count] == little[count])
		{
			return ((char *)big + count);
		}		
		count++;
	}
	return (0);
}
