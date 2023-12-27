/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:58:37 by gacalaza          #+#    #+#             */
/*   Updated: 2023/12/27 15:34:30 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	ft_isdigit(int argument)
{
	if (argument >= '0' && argument <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	size_t	result;
	int		count;
	int		sign;

	count = 0;
	result = 0;
	sign = 1;
	while ((nptr[count] >= 9 && nptr[count] <= 13) || nptr[count] == 32)
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
