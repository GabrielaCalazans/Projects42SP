/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:39:01 by coder             #+#    #+#             */
/*   Updated: 2022/09/10 21:39:34 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t len)
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
