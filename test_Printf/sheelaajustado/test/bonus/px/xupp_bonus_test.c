/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xupp_bonus_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 04:50:31 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/21 20:16:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/test.h"

void	xupp_bonus_test()
{
	int	result1;
	int	result2;

	// printing unsigned hex integer uppercase - specifier X
	printf(LIGHT_RED("\n\nBonus test: printing unsigned hex integer lowercase with flags - specifier X:\n"));
	result1 = printf("%%X = |%X|\n", 42427);
	result2 = ft_printf("%%X = |%X|\n", 42427);
	check_return(result1, result2);
	printf("---------------\n");
	printf(PINK("\nBasic tests:\n"));
	printf(LIGHT_BLUE2("test 1: width\n"));
	result1 = printf("%%10X = |%10X|\n", 42427);
	result2 = ft_printf("%%10X = |%10X|\n", 42427);
	check_return(result1, result2);
	printf("---------------\n");
	printf(LIGHT_BLUE2("test 2: left padding\n"));
	result1 = printf("%%-10X = |%-10X|\n", 42427);
	result2 = ft_printf("%%-10X = |%-10X|\n", 42427);
	check_return(result1, result2);

	printf("---------------\n");
	printf(LIGHT_BLUE2("test 3: 0x\n"));
	result1 = printf("%%#10X = |%#10X|\n", 42427);
	result2 = ft_printf("%%#10X = |%#10X|\n", 42427);
	check_return(result1, result2);
	result1 = printf("%%#-10X = |%#-10X|\n", 42427);
	result2 = ft_printf("%%#-10X = |%#-10X|\n", 42427);
	check_return(result1, result2);
	result1 = printf("%%-#10X = |%-#10X|\n", 42427);
	result2 = ft_printf("%%-#10X = |%-#10X|\n", 42427);
	check_return(result1, result2);

	printf("---------------\n");
	printf(LIGHT_BLUE2("test 4: 0 padding\n"));
	result1 = printf("%%010X = |%010X|\n", 42427);
	result2 = ft_printf("%%010X = |%010X|\n", 42427);
	check_return(result1, result2);
	result1 = printf("%%-010X = |%-010X|\n", 42427);
	result2 = ft_printf("%%-010X = |%-010X|\n", 42427);
	check_return(result1, result2);
	result1 = printf("%%-0#10X = |%-0#10X|\n", 42427);
	result2 = ft_printf("%%-0#10X = |%-0#10X|\n", 42427);
	check_return(result1, result2);
	result1 = printf("%%0#10X = |%0#10X|\n", 42427);
	result2 = ft_printf("%%0#10X = |%0#10X|\n", 42427);
	check_return(result1, result2);

	printf("---------------\n");
	printf(PINK("Precision tests\n"));
	printf(LIGHT_BLUE2("\ntest 5.1:\n"));
	result1 = printf("%%.3X = |%.3X|\n", 42427);
	result2 = ft_printf("%%.3X = |%.3X|\n", 42427);
	check_return(result1, result2);
	result1 = printf("%%.8X = |%.8X|\n", 42427);
	result2 = ft_printf("%%.8X = |%.8X|\n", 42427);
	check_return(result1, result2);
	result1 = printf("%%#.5X = |%#.5X|\n", 42427);
	result2 = ft_printf("%%#.5X = |%#.5X|\n", 42427);
	check_return(result1, result2);

	printf("---------------\n");
	printf(LIGHT_BLUE2("\ntest 5.2: precision and width\n"));
	result1 = printf("%%10.5X = |%10.5X|\n", 42427);
	result2 = ft_printf("%%10.5X = |%10.5X|\n", 42427);
	check_return(result1, result2);
	result1 = printf("%%-10.5X = |%-10.5X|\n", 42427);
	result2 = ft_printf("%%-10.5X = |%-10.5X|\n", 42427);
	check_return(result1, result2);
	result1 = printf("%%#10.5X = |%#10.5X|\n", 42427);
	result2 = ft_printf("%%#10.5X = |%#10.5X|\n", 42427);
	check_return(result1, result2);

	printf("---------------\n");
	printf(LIGHT_BLUE2("test 5.3: precision = 0\n"));
	result1 = printf("%%.X = |%.X|\n", 42427);
	result2 = ft_printf("%%.X = |%.X|\n", 42427);
	check_return(result1, result2);
	result1 = printf("%%#5.X = |%#5.X|\n", 42427);
	result2 = ft_printf("%%#5.X = |%#5.X|\n", 42427);
	check_return(result1, result2);

	printf("---------------\n");
	printf(PINK("Invalids flags for X specifier\n"));
	printf(LIGHT_BLUE2("\ntest 6:\n"));
	result1 = printf("%%+10X = |%+10X|\n", 42427);
	result2 = ft_printf("%%+10X = |%+10X|\n", 42427);
	check_return(result1, result2);
	result1 = printf("%%- 10X = |%- 10X|\n", 42427);
	result2 = ft_printf("%%- 10X = |%- 10X|\n", 42427);
	check_return(result1, result2);

	printf("---------------\n");
	printf(PINK("\nnumber = 0\n"));
	printf(LIGHT_BLUE2("\ntest 7.1:\n"));
	result1 = printf("%%X = |%X|\n", 0);
	result2 = ft_printf("%%X = |%X|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%5X = |%5X|\n", 0);
	result2 = ft_printf("%%5X = |%5X|\n", 0);
	check_return(result1, result2);
	printf("---------------\n");
	result1 = printf("%%05X = |%05X|\n", 0);
	result2 = ft_printf("%%05X = |%05X|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%-5X = |%-5X|\n", 0);
	result2 = ft_printf("%%-5X = |%-5X|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%-05X = |%-05X|\n", 0);
	result2 = ft_printf("%%-05X = |%-05X|\n", 0);
	check_return(result1, result2);
	printf("---------------\n");
	result1 = printf("%%#5X = |%#5X|\n", 0);
	result2 = ft_printf("%%#5X = |%#5X|\n", 0);
	check_return(result1, result2);
	printf("---------------\n");
	printf(LIGHT_BLUE2("\ntest 7.2:\n"));
	result1 = printf("%%.5X = |%.5X|\n", 0);
	result2 = ft_printf("%%.5X = |%.5X|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%#.5X = |%#.5X|\n", 0);
	result2 = ft_printf("%%#.5X = |%#.5X|\n", 0);
	check_return(result1, result2);
	printf("---------------\n");
	result1 = printf("%%.05X = |%.05X|\n", 0);
	result2 = ft_printf("%%.05X = |%.05X|\n", 0);
	check_return(result1, result2);

	printf("---------------\n");
	printf(PINK("\nprecision = 0 and number = 0\n"));
	printf(LIGHT_BLUE2("\ntest 8:\n"));
	result1 = printf("%%.X = |%.X|\n", 0);
	result2 = ft_printf("%%.X = |%.X|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%.#5X = |%.#5X|\n", 0);
	result2 = ft_printf("%%.#5X = |%.#5X|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%.-5X = |%.-5X|\n", 0);
	result2 = ft_printf("%%.-5X = |%.-5X|\n", 0);
	check_return(result1, result2);
}
