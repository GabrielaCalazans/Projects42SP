/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:31:39 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/21 17:23:25 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	result;
	int		count;
	int		sign;

	count = 0;
	result = 0;
	sign = 1;
	while ((nptr[count] >= 8 && nptr[count] <= 13) || nptr[count] == 32)
	{
		count++;
	}
	if (nptr[count] == '-' || nptr[count] == '+')
	{
		if (nptr[count] == '-')
			sign = -1;
		count++;
	}
	while (nptr[count] != '\0' && ft_isdigit(nptr[count]))
	{
		result = (result * 10) + (nptr[count] - '0');
		count++;
	}
	return (result * sign);
}
