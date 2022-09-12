/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:00:08 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/12 19:00:29 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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