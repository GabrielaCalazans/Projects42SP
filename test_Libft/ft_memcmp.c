/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 00:54:16 by coder             #+#    #+#             */
/*   Updated: 2022/09/11 01:05:54 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *str1, const void *str2, size_t len)
{
	size_t	count;
	size_t	size;

	count = 0;
	size = len - 1;
	if (len == 0)
	{
		return (0);
	}
	while ((str1[count] == str2[count] && str1[count]
			!= '\0' && str2[count] != '\0') && count < size)
	{
		count++;
	}
	return (str1[count] - str2[count]);
}