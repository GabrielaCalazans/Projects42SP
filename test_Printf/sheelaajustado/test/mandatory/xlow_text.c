/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xlow_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 04:38:15 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/20 06:21:27 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/test.h"

void	lowerhex_test()
{
	int	result1;
	int	result2;
	int	i = 42;
	int *ptr = &i;

	// printing unsigned hex integer lowercase - specifier x
	printf(LIGHT_RED("\n\nprinting unsigned hex integer lowercase - specifier x:\n"));
	printf(PINK("\nbasic tests - specifier x:\n"));
	result1 = printf(LIGHT_BLUE2("unsigned hex integer %%x = |%x|\n"), i);
	result2 = ft_printf(LIGHT_BLUE2("unsigned hex integer %%x = |%x|\n"), i);
	check_return(result1, result2);
	result1 = printf(LIGHT_BLUE2("using a pointer %%x = |%x|\n"), *ptr);
	result2 = ft_printf(LIGHT_BLUE2("using a pointer %%x = |%x|\n"), *ptr);
	check_return(result1, result2);
	result1 = printf(LIGHT_BLUE2("unsigned hex integer %%x = |%x|\n"), 438);
	result2 = ft_printf(LIGHT_BLUE2("unsigned hex integer %%x = |%x|\n"), 438);
	check_return(result1, result2);
	result1 = printf(LIGHT_BLUE2("big unsigned hex integer %%x = |%x|\n"), 2147483648);
	result2 = ft_printf(LIGHT_BLUE2("big unsigned hex integer %%x = |%x|\n"), 2147483648);
	check_return(result1, result2);
	printf("----------------------------------------\n");
	result1 = printf("number %%x = maximum unsigned integer = |%x|\n", 4294967295);
	result2 = ft_printf("number %%x = maximum unsigned integer = |%x|\n", 4294967295);
	check_return(result1, result2);
	result1 = printf("number %%x > maximum unsigned integer = |%x|\n", 4294967296);
	result2 = ft_printf("number %%x > maximum unsigned integer = |%x|\n", 4294967296);
	check_return(result1, result2);
	result1 = printf("number %%x > maximum unsigned integer = |%x|\n", 4294967297);
	result2 = ft_printf("number %%x > maximum unsigned integer = |%x|\n", 4294967297);
	check_return(result1, result2);
	printf("----------------------------------------\n");
	result1 = printf(LIGHT_BLUE2("unsigned hex integer with negative number %%x = |%x|\n"), -42);
	result2 = ft_printf(LIGHT_BLUE2("unsigned hex integer with negative number %%x = |%x|\n"), -42);
	check_return(result1, result2);

	printf(PINK("\nspecifier x - printing a pointer:\n"));
	result1 = printf(LIGHT_BLUE2("pointer value in %%x = |%x|\n"), ptr);
	result2 = ft_printf(LIGHT_BLUE2("pointer value in %%x = |%x|\n"), ptr);
	check_return(result1, result2);

	printf(PINK("\nprinting more than one element:\n"));
	result1 = printf(LIGHT_BLUE2("element 1: |%x|\nelement 2: |%x|\nelement 3: |%x|\nelement 4: |%x|\n"), i, 5456211, 0, 0056);
	printf("--------------------\n");
	result2 = ft_printf(LIGHT_BLUE2("element 1: |%x|\nelement 2: |%x|\nelement 3: |%x|\nelement 4: |%x|\n"), i, 5456211, 0, 0056);
	check_return(result1, result2);

	printf("---------------\n");
	printf(PINK("\nprinting 0\n"));
	result1 = printf("%%x = |%x|\n", 0);
	result2 = ft_printf("%%x = |%x|\n", 0);
}
