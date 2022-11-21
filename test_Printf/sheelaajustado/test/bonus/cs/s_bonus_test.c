/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_bonus_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 04:49:47 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/21 23:43:48 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/test.h"

s_bonus_test()
{
	char	str[13] = "Hello World!";
	int	result1;
	int	result2;

	// printing string - specifier s
	printf(LIGHT_RED("\nBonus test: printing string with flags - specifier s:\n"));
	result1 = printf("string %%s = |%s|\n", str);
	result2 = ft_printf("string %%s = |%s|\n", str);
	check_return(result1, result2);

	printf("-----------------------------------------------\n");
	printf(PINK("\nBasic tests:\n"));
	printf(LIGHT_BLUE2("test 1 - width:\n"));
	result1 = printf("string %%5s = |%5s|\n", str);
	result2 = ft_printf("string %%5s = |%5s|\n", str);
	check_return(result1, result2);
	result1 = printf("string %%20s = |%20s|\n", str);
	result2 = ft_printf("string %%20s = |%20s|\n", str);
	check_return(result1, result2);

	printf("-----------------------------------------------\n");
	printf(LIGHT_BLUE2("test 2: left padding\n"));
	result1 = printf("string %%-20s = |%-20s|\n", str);
	result2 = ft_printf("string %%-20s = |%-20s|\n", str);
	check_return(result1, result2);

	printf("-----------------------------------------------\n");
	printf(LIGHT_BLUE2("test 3: zero padding\n"));
	result1 = printf("string %%020s = |%020s|\n", str);
	result2 = ft_printf("string %%020s = |%020s|\n", str);
	check_return(result1, result2);
	result1 = printf("string %%-020s = |%-020s|\n", str);
	result2 = ft_printf("string %%-020s = |%-020s|\n", str);
	check_return(result1, result2);

	printf("-----------------------------------------------\n");
	printf(LIGHT_BLUE2("test 4: other flags\n"));
	result1 = printf("string %%+20s = |%+20s|\n", str);
	result2 = ft_printf("string %%+20s = |%+20s|\n", str);
	check_return(result1, result2);
	result1 = printf("string %%- 20s = |%- 20s|\n", str);
	result2 = ft_printf("string %%- 20s = |%- 20s|\n", str);
	check_return(result1, result2);
	result1 = printf("string %%#20s = |%#20s|\n", str);
	result2 = ft_printf("string %%#20s = |%#20s|\n", str);
	check_return(result1, result2);

	printf("-----------------------------------------------\n");
	printf(PINK("\nPrecision flag:\n"));
	printf(LIGHT_BLUE2("test 5.1:\n"));
	result1 = printf("string %%.5s = |%.5s|\n", str);
	result2 = ft_printf("string %%.5s = |%.5s|\n", str);
	check_return(result1, result2);
	result1 = printf("string %%.20s = |%.20s|\n", str);
	result2 = ft_printf("string %%.20s = |%.20s|\n", str);
	check_return(result1, result2);
	result1 = printf("string %%020.5s = |%020.5s|\n", str);
	result2 = ft_printf("string %%020.5s = |%020.5s|\n", str);
	check_return(result1, result2);
	printf("-----------------------------------------------\n");
	printf(LIGHT_BLUE2("test 5.2: precision = 0\n"));
	result1 = printf("string %%.s = |%.s|\n", str);
	result2 = ft_printf("string %%.s = |%.s|\n", str);
	check_return(result1, result2);
	printf("-----------------------------------------------\n");
	printf(LIGHT_BLUE2("test 5.3:\n"));
	result1 = printf("string %%20.5s = |%20.5s|\n", str);
	result2 = ft_printf("string %%20.5s = |%20.5s|\n", str);
	check_return(result1, result2);
	result1 = printf("string %%-20.5s = |%-20.5s|\n", str);
	result2 = ft_printf("string %%-20.5s = |%-20.5s|\n", str);
	check_return(result1, result2);
	result1 = printf("string %%5.10s = |%5.10s|\n", str);
	result2 = ft_printf("string %%5.10s = |%5.10s|\n", str);
	check_return(result1, result2);
	result1 = printf("string %%10.5s = |%10.5s|\n", str);
	result2 = ft_printf("string %%10.5s = |%10.5s|\n", str);
	check_return(result1, result2);
	printf("-----------------------------------------------\n");
	printf(LIGHT_BLUE2("test 5.4:\n"));
	result1 = printf("string %%-.20s = |%-.20s|\n", str);
	result2 = ft_printf("string %%-.20s = |%-.20s|\n", str);
	check_return(result1, result2);
	result1 = printf("string %%20-.5s = |%20-.5s|\n", str);
	result2 = ft_printf("string %%20-.5s = |%20-.5s|\n", str);
	check_return(result1, result2);

	printf("-----------------------------------------------\n");
	printf(PINK("Flags positions variations\n"));
	printf(PINK("\ntest 6:\n"));
	result1 = printf("string %%.-20s = |%.-20s|\n", str);
	result2 = ft_printf("string %%.-20s = |%.-20s|\n", str);
	check_return(result1, result2);
	result1 = printf("string %%20.-s = |%20.-s|\n", str);
	result2 = ft_printf("string %%20.-s = |%20.-s|\n", str);
	check_return(result1, result2);

	printf("-----------------------------------------------\n");
	printf(PINK("\nEmpty string tests\n"));
	printf(LIGHT_BLUE2("\ntest 7:\n"));
	result1 = printf("string %%5s = |%5s|\n", "");
	result2 = ft_printf("string %%5s = |%5s|\n", "");
	check_return(result1, result2);
	result1 = printf("string %%.5s = |%.5s|\n", "");
	result2 = ft_printf("string %%.5s = |%.5s|\n", "");
	check_return(result1, result2);
	result1 = printf("string %%10.5s = |%10.5s|\n", "");
	result2 = ft_printf("string %%10.5s = |%10.5s|\n", "");
	check_return(result1, result2);
	result1 = printf("string %%5.10s = |%5.10s|\n", "");
	result2 = ft_printf("string %%5.10s = |%5.10s|\n", "");
	check_return(result1, result2);
	result1 = printf("%%5.s = |%5.s|\n", "");
	result2 = ft_printf("%%5.s = |%5.s|\n", "");
	check_return(result1, result2);
	result1 = printf("%%05.s = |%05.s|\n", "");
	result2 = ft_printf("%%05.s = |%05.s|\n", "");
	check_return(result1, result2);
	printf("-----------------------------------------------\n");

	char *null_str = NULL;
	printf(PINK("\nPaulo Santana null string tests\n"));
	printf(LIGHT_BLUE2("\ntest 8: \n"));
	result1 = printf("%%.1s = |%.1s|\n", null_str);
	result2 = ft_printf("%%.1s = |%.1s|\n", null_str);
	check_return(result1, result2);
	result1 = printf("%%.2s = |%.2s|\n", null_str);
	result2 = ft_printf("%%.2s = |%.2s|\n", null_str);
	check_return(result1, result2);
	result1 = printf("%%.3s = |%.3s|\n", null_str);
	result2 = ft_printf("%%.3s = |%.3s|\n", null_str);
	check_return(result1, result2);
	result1 = printf("%%.10s = |%.10s|\n", null_str);
	result2 = ft_printf("%%.10s = |%.10s|\n", null_str);
	check_return(result1, result2);
}
