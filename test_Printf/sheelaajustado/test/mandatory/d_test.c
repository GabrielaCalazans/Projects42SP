/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_test.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 04:37:57 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/20 04:42:08 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/test.h"

void	di_test()
{
	int	result1;
	int	result2;
	int	i = -42;
	int *ptr = &i;

	// printing signed decimal integer - specifiers d and i
	printf(LIGHT_RED("\n\nprinting signed decimal integer - specifier d:\n"));
	printf(PINK("\nbasic tests:\n"));
	result1 = printf(LIGHT_BLUE2("number %%d = |%d|\n"), i);
	result2 = ft_printf(LIGHT_BLUE2("number %%d = |%d|\n"), i);
	check_return(result1, result2);
	result1 = printf("number %%d using pointer = |%d|\n", *ptr);
	result2 = ft_printf("number %%d using pointer = |%d|\n", *ptr);
	check_return(result1, result2);
	result1 = printf("number %%d > maximum signed integer = |%d|\n", 2147483648);
	result2 = ft_printf("number %%d > maximum signed integer = |%d|\n", 2147483648);
	check_return(result1, result2);
	result1 = printf("number %%d < minimum signed integer = |%d|\n", -2147483649);
	result2 = ft_printf("number %%d < minimum signed integer = |%d|\n", -2147483649);
	check_return(result1, result2);

	printf(PINK("\nprinting more than one element:\n"));
	result1 = printf(LIGHT_BLUE2("element 1: |%d|\nelement 2: |%d|\nelement 3: |%i|\nelement 4: |%i|\n"), i, 5456211, 0, 0056);
	printf("--------------------\n");
	result2 = ft_printf(LIGHT_BLUE2("element 1: |%d|\nelement 2: |%d|\nelement 3: |%i|\nelement 4: |%i|\n"), i, 5456211, 0, 0056);
	check_return(result1, result2);
}
