/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 00:31:25 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/13 01:47:25 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int			count;
	const char	*point;

	count = 0;
	while (str++)
	{
		if (*(str) == (unsigned char)c)
		{
			point = (char *)str;
		}
	}
	return ((char *)point);
}