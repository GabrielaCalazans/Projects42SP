/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:44:16 by coder             #+#    #+#             */
/*   Updated: 2022/09/08 20:32:57 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int charc, size_t len)
{
	size_t			count;
	unsigned char	*strup;

	count = 0;
	strup = (unsigned char *)str;
	while (count < len)
	{
		strup[count] = charc;
		count++;
	}
	return (str);
}
