/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xupp_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 04:38:19 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/20 06:21:22 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/test.h"

void	upperhex_test()
{
	int	result1;
	int	result2;
	int	i = 42;
	int *ptr = &i;

	// printing unsigned hex integer uppercase - specifier X
	printf(LIGHT_RED("\n\nprinting unsigned hex integer uppercase - specifier X:\n"));
	printf(PINK("\nbasic tests - specifier X:\n"));
	result1 = printf(LIGHT_BLUE2("unsigned hex integer %%X = |%X|\n"), i);
	result2 = ft_printf(LIGHT_BLUE2("unsigned hex integer %%X = |%X|\n"), i);
	check_return(result1, result2);
	result1 = printf(LIGHT_BLUE2("using a pointer %%X = |%X|\n"), *ptr);
	result2 = ft_printf(LIGHT_BLUE2("using a pointer %%X = |%X|\n"), *ptr);
	check_return(result1, result2);
	result1 = printf(LIGHT_BLUE2("unsigned hex integer %%X = |%X|\n"), 438);
	result2 = ft_printf(LIGHT_BLUE2("unsigned hex integer %%X = |%X|\n"), 438);
	check_return(result1, result2);
	result1 = printf(LIGHT_BLUE2("big unsigned hex integer %%X = |%X|\n"), 2147483648);
	result2 = ft_printf(LIGHT_BLUE2("big unsigned hex integer %%X = |%X|\n"), 2147483648);
	check_return(result1, result2);
	printf("----------------------------------------\n");
	result1 = printf("number %%X = maximum unsigned integer = |%X|\n", 4294967295);
	result2 = ft_printf("number %%X = maximum unsigned integer = |%X|\n", 4294967295);
	check_return(result1, result2);
	result1 = printf("number %%X > maximum unsigned integer = |%X|\n", 4294967296);
	result2 = ft_printf("number %%X > maximum unsigned integer = |%X|\n", 4294967296);
	check_return(result1, result2);
	result1 = printf("number %%X > maximum unsigned integer = |%X|\n", 4294967297);
	result2 = ft_printf("number %%X > maximum unsigned integer = |%X|\n", 4294967297);
	check_return(result1, result2);
	printf("----------------------------------------\n");
	result1 = printf(LIGHT_BLUE2("unsigned hex integer with negative number %%X = |%X|\n"), -42);
	result2 = ft_printf(LIGHT_BLUE2("unsigned hex integer with negative number %%X = |%X|\n"), -42);
	check_return(result1, result2);

	printf(PINK("\nspecifier X - printing a pointer:\n"));
	result1 = printf(LIGHT_BLUE2("pointer value in %%X = |%X|\n"), ptr);
	result2 = ft_printf(LIGHT_BLUE2("pointer value in %%X = |%X|\n"), ptr);
	check_return(result1, result2);

	printf(PINK("\nprinting more than one element:\n"));
	result1 = printf(LIGHT_BLUE2("element 1: |%X|\nelement 2: |%X|\nelement 3: |%X|\nelement 4: |%X|\n"), i, 5456211, 0, 0056);
	printf("--------------------\n");
	result2 = ft_printf(LIGHT_BLUE2("element 1: |%X|\nelement 2: |%X|\nelement 3: |%X|\nelement 4: |%X|\n"), i, 5456211, 0, 0056);
	check_return(result1, result2);

	printf("---------------\n");
	printf(PINK("\nprinting 0\n"));
	result1 = printf("%%X = |%X|\n", 0);
	result2 = ft_printf("%%X = |%X|\n", 0);
}
