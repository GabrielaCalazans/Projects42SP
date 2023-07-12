/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myatoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:49:59 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/29 12:05:41 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	result = 0;
	int	i = 0;
	int	sign = 1;

	if (!str)
		return(0);
	while (str[i] >= 8 && str[i] <= 13)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

// int	main()
// {
// 	printf("   FAKE: %d\n", ft_atoi("42"));
// 	printf("ORIGINAL: %d\n", atoi("42"));
// 	printf("   FAKE: %d\n", ft_atoi("-30432"));
// 	printf("ORIGINAL: %d\n", atoi("-30432"));
// 	printf("   FAKE: %d\n", ft_atoi("-28381748"));
// 	printf("ORIGINAL: %d\n", atoi("-28381748"));
// 	printf("   FAKE: %d\n", ft_atoi("-283a81748"));
// 	printf("ORIGINAL: %d\n", atoi("-283a81748"));
// 	return (0);
// }