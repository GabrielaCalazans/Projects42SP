/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_test.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 04:38:04 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/20 04:42:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/test.h"

void	u_test()
{
	int	result1;
	int	result2;
	unsigned int	i = 42;
	int *ptr = &i;

	// printing unsigned integer - specifier u:
	printf(LIGHT_RED("\n\nprinting unsigned integer - specifier u:\n"));
	result1 = printf(LIGHT_BLUE2("number %%u = |%u|\n"), i);
	result2 = ft_printf(LIGHT_BLUE2("number %%u = |%u|\n"), i);
	check_return(result1, result2);
	result1 = printf("number %%u using pointer = |%u|\n", *ptr);
	result2 = ft_printf("number %%u using pointer = |%u|\n", *ptr);
	check_return(result1, result2);
	result1 = printf(LIGHT_BLUE2("number %%u negative = |%u|\n"), -42);
	result2 = ft_printf(LIGHT_BLUE2("number %%u negative = |%u|\n"), -42);
	check_return(result1, result2);
	result1 = printf(LIGHT_BLUE2("number %%u < 0 = |%u|\n"), -1);
	result2 = ft_printf(LIGHT_BLUE2("number %%u < 0 = |%u|\n"), -1);
	check_return(result1, result2);
	result1 = printf("number %%u = maximum unsigned integer = |%u|\n", 4294967295);
	result2 = ft_printf("number %%u = maximum unsigned integer = |%u|\n", 4294967295);
	check_return(result1, result2);
	result1 = printf("number %%u > maximum unsigned integer = |%u|\n", 4294967296);
	result2 = ft_printf("number %%u > maximum unsigned integer = |%u|\n", 4294967296);
	check_return(result1, result2);
	printf("----------------------------------------\n");
	result1 = printf("number %%u > maximum unsigned integer = |%u|\n", 4294967297);
	result2 = ft_printf("number %%u > maximum unsigned integer = |%u|\n", 4294967297);
	check_return(result1, result2);

	printf(PINK("\nprinting more than one element:\n"));
	result1 = printf(LIGHT_BLUE2("element 1: |%u|\nelement 2: |%u|\nelement 3: |%u|\nelement 4: |%u|\n"), i, 2147483648, 1000000000, 0);
	printf("--------------------\n");
	result2 = ft_printf(LIGHT_BLUE2("element 1: |%u|\nelement 2: |%u|\nelement 3: |%u|\nelement 4: |%u|\n"), i, 2147483648, 1000000000, 0);
	check_return(result1, result2);
}
