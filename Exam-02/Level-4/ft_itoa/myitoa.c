/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myitoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:01:14 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/15 15:39:20 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int	ft_lennbr(int nbr)
{
	int		len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

int	ft_checksign(int nbr, char *result)
{
	if (nbr == -2147483648)
	{
		result[0] = '-';
		result[1] = '2';
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		result[0] = '0';
	return (nbr);
}

char	*ft_itoa(int nbr)
{
	int		len;
	char	*result;

	len = ft_lennbr(nbr);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	nbr = ft_checksign(nbr, result);
	while (nbr)
	{
		result[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (result);
}

// int	main()
// {
// 	printf("nbr: %s\n", ft_itoa(10));
// 	printf("nbr: %s\n", ft_itoa(5593610));
// 	printf("nbr: %s\n", ft_itoa(-5593610));
// 	printf("nbr: %s\n", ft_itoa(0));
// 	printf("nbr: %s\n", ft_itoa(0));
// 	printf("nbr: %s\n", ft_itoa(INT_MAX));
// 	printf("nbr: %s\n", ft_itoa(INT_MIN));
// 	printf("min int: %d\n", INT_MIN);
// 	return (0);
// }