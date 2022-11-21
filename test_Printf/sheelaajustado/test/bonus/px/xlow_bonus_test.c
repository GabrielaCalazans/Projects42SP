/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xlow_bonus_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 04:50:16 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/21 20:16:22 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/test.h"

void	xlow_bonus_test()
{
	int	result1;
	int	result2;

	// printing unsigned hex integer lowercase - specifier x
	printf(LIGHT_RED("\n\nBonus test: printing unsigned hex integer lowercase with flags - specifier x:\n"));
	result1 = printf("%%x = |%x|\n", 42427);
	result2 = ft_printf("%%x = |%x|\n", 42427);
	check_return(result1, result2);
	printf("---------------\n");
	printf(PINK("\nBasic tests:\n"));
	printf(LIGHT_BLUE2("test 1: width\n"));
	result1 = printf("%%10x = |%10x|\n", 42427);
	result2 = ft_printf("%%10x = |%10x|\n", 42427);
	check_return(result1, result2);
	printf("---------------\n");
	printf(LIGHT_BLUE2("test 2: left padding\n"));
	result1 = printf("%%-10x = |%-10x|\n", 42427);
	result2 = ft_printf("%%-10x = |%-10x|\n", 42427);
	check_return(result1, result2);

	printf("---------------\n");
	printf(LIGHT_BLUE2("test 3: 0x\n"));
	result1 = printf("%%#10x = |%#10x|\n", 42427);
	result2 = ft_printf("%%#10x = |%#10x|\n", 42427);
	check_return(result1, result2);
	result1 = printf("%%#-10x = |%#-10x|\n", 42427);
	result2 = ft_printf("%%#-10x = |%#-10x|\n", 42427);
	check_return(result1, result2);
	result1 = printf("%%-#10x = |%-#10x|\n", 42427);
	result2 = ft_printf("%%-#10x = |%-#10x|\n", 42427);
	check_return(result1, result2);

	printf("---------------\n");
	printf(LIGHT_BLUE2("test 4: 0 padding\n"));
	result1 = printf("%%010x = |%010x|\n", 42427);
	result2 = ft_printf("%%010x = |%010x|\n", 42427);
	check_return(result1, result2);
	result1 = printf("%%-010x = |%-010x|\n", 42427);
	result2 = ft_printf("%%-010x = |%-010x|\n", 42427);
	check_return(result1, result2);
	result1 = printf("%%-0#10x = |%-0#10x|\n", 42427);
	result2 = ft_printf("%%-0#10x = |%-0#10x|\n", 42427);
	check_return(result1, result2);
	result1 = printf("%%0#10x = |%0#10x|\n", 42427);
	result2 = ft_printf("%%0#10x = |%0#10x|\n", 42427);
	check_return(result1, result2);

	printf("---------------\n");
	printf(PINK("Precision tests\n"));
	printf(LIGHT_BLUE2("\ntest 5.1:\n"));
	result1 = printf("%%.3x = |%.3x|\n", 42427);
	result2 = ft_printf("%%.3x = |%.3x|\n", 42427);
	check_return(result1, result2);
	result1 = printf("%%.8x = |%.8x|\n", 42427);
	result2 = ft_printf("%%.8x = |%.8x|\n", 42427);
	check_return(result1, result2);
	result1 = printf("%%#.5x = |%#.5x|\n", 42427);
	result2 = ft_printf("%%#.5x = |%#.5x|\n", 42427);
	check_return(result1, result2);

	printf("---------------\n");
	printf(LIGHT_BLUE2("\ntest 5.2: precision and width\n"));
	result1 = printf("%%10.5x = |%10.5x|\n", 42427);
	result2 = ft_printf("%%10.5x = |%10.5x|\n", 42427);
	check_return(result1, result2);
	result1 = printf("%%-10.5x = |%-10.5x|\n", 42427);
	result2 = ft_printf("%%-10.5x = |%-10.5x|\n", 42427);
	check_return(result1, result2);
	result1 = printf("%%#10.5x = |%#10.5x|\n", 42427);
	result2 = ft_printf("%%#10.5x = |%#10.5x|\n", 42427);
	check_return(result1, result2);

	printf("---------------\n");
	printf(LIGHT_BLUE2("test 5.3: precision = 0\n"));
	result1 = printf("%%.x = |%.x|\n", 42427);
	result2 = ft_printf("%%.x = |%.x|\n", 42427);
	check_return(result1, result2);
	result1 = printf("%%#5.x = |%#5.x|\n", 42427);
	result2 = ft_printf("%%#5.x = |%#5.x|\n", 42427);
	check_return(result1, result2);

	printf("---------------\n");
	printf(PINK("Invalids flags for x specifier\n"));
	printf(LIGHT_BLUE2("\ntest 6:\n"));
	result1 = printf("%%+10x = |%+10x|\n", 42427);
	result2 = ft_printf("%%+10x = |%+10x|\n", 42427);
	check_return(result1, result2);
	result1 = printf("%%- 10x = |%- 10x|\n", 42427);
	result2 = ft_printf("%%- 10x = |%- 10x|\n", 42427);
	check_return(result1, result2);

	printf("---------------\n");
	printf(PINK("\nnumber = 0\n"));
	printf(LIGHT_BLUE2("\ntest 7.1:\n"));
	result1 = printf("%%x = |%x|\n", 0);
	result2 = ft_printf("%%x = |%x|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%5x = |%5x|\n", 0);
	result2 = ft_printf("%%5x = |%5x|\n", 0);
	check_return(result1, result2);
	printf("---------------\n");
	result1 = printf("%%05x = |%05x|\n", 0);
	result2 = ft_printf("%%05x = |%05x|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%-5x = |%-5x|\n", 0);
	result2 = ft_printf("%%-5x = |%-5x|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%-05x = |%-05x|\n", 0);
	result2 = ft_printf("%%-05x = |%-05x|\n", 0);
	check_return(result1, result2);
	printf("---------------\n");
	result1 = printf("%%#5x = |%#5x|\n", 0);
	result2 = ft_printf("%%#5x = |%#5x|\n", 0);
	check_return(result1, result2);
	printf("---------------\n");
	printf(LIGHT_BLUE2("\ntest 7.2: precision\n"));
	result1 = printf("%%.5x = |%.5x|\n", 0);
	result2 = ft_printf("%%.5x = |%.5x|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%#.5x = |%#.5x|\n", 0);
	result2 = ft_printf("%%#.5x = |%#.5x|\n", 0);
	check_return(result1, result2);
	printf("---------------\n");
	result1 = printf("%%.05x = |%.05x|\n", 0);
	result2 = ft_printf("%%.05x = |%.05x|\n", 0);
	check_return(result1, result2);
	printf("---------------\n");
	printf(LIGHT_BLUE2("\ntest 7.3: precision and pad\n"));
	result1 = printf("%%8.5x = |%8.5x|\n", 0);
	result2 = ft_printf("%%8.5x = |%8.5x|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%08.5x = |%08.5x|\n", 0);
	result2 = ft_printf("%%08.5x = |%08.5x|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%-8.5x = |%-8.5x|\n", 0);
	result2 = ft_printf("%%-8.5x = |%-8.5x|\n", 0);
	check_return(result1, result2);

	printf("---------------\n");
	printf(PINK("\nprecision = 0 and number = 0\n"));
	printf(LIGHT_BLUE2("\ntest 8:\n"));
	result1 = printf("%%.x = |%.x|\n", 0);
	result2 = ft_printf("%%.x = |%.x|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%.#5x = |%.#5x|\n", 0);
	result2 = ft_printf("%%.#5x = |%.#5x|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%.-5x = |%.-5x|\n", 0);
	result2 = ft_printf("%%.-5x = |%.-5x|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%05.x = |%05.x|\n", 0);
	result2 = ft_printf("%%05.x = |%05.x|\n", 0);
	check_return(result1, result2);
}
