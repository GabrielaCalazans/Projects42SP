/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:29:51 by coder             #+#    #+#             */
/*   Updated: 2022/09/09 02:18:25 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	int	count;

	count = 0;
	if (0 == str[0])
		return (str);
	while (str[count])
	{
		if (str[count] == c)
		{
			return ((char *)str + count);
		}		
		count++;
	}
	return (0);
}
