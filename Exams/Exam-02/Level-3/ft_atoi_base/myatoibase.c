/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myatoibase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:43:56 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/08 23:23:27 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'F')
		return (c + ('a' - 'A'));
	return (c);
}

int	checkbase(char c, int str_base)
{
	int	maxnbr = 0;

	if (str_base < 10)
		maxnbr = str_base + '0';
	if (str_base > 9)
		maxnbr = str_base - 10 + 'a';
	if (c >= '0' && c <= '9' && c <= maxnbr)
		return (c - '0');
	if (c >= 'a' && c <= 'f' && c <= maxnbr)
		return (c + 10 - 'a');
	else
		return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i = 0;
	int	result = 0;
	int	digit = 0;
	int	sign = 1;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((digit = checkbase(ft_tolower(str[i]), str_base)) >= 0)
	{
		result *= str_base;
		result += digit;
		i++;
	}
	return (result * sign);
}

// int	main()
// {
// 	printf("ORIGINAL: STR 10 BASE 10 RESULT: %ld\n", strtol("10", NULL, 4));
// 	printf("FAKE: STR 10 BASE 10 RESULT: %d\n", ft_atoi_base("10", 4));
// 	printf("\n");
// 	printf("ORIGINAL: STR FF BASE 10 RESULT: %ld\n", strtol("FF", NULL, 10));
// 	printf("FAKE: STR FF BASE 10 RESULT: %d\n", ft_atoi_base("FF", 10));
// 	printf("\n");
// 	printf("ORIGINAL: STR FF BASE 16 RESULT: %ld\n", strtol("FF", NULL, 16));
// 	printf("FAKE: STR FF BASE 16 RESULT: %d\n", ft_atoi_base("FF", 16));
// 	printf("\n");
// }