/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_bonus_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 04:13:21 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/21 21:51:19 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/test.h"

void	c_bonus_test()
{
	int		result1;
	int		result2;
	char	c = 'a';

	printf(LIGHT_RED("\nBonus test: printing char with flags - specifier c:\n"));
	result1 = printf("%%c = |%c|\n", c);
	result2 = ft_printf("%%c = |%c|\n", c);
	check_return(result1, result2);
	printf("---------------\n");
	printf(PINK("\nBasic tests:\n"));
	printf(LIGHT_BLUE2("test 1: width\n"));
	result1 = printf("%%5c = |%5c|\n", c);
	result2 = ft_printf("%%5c = |%5c|\n", c);
	check_return(result1, result2);

	printf("---------------\n");
	printf(LIGHT_BLUE2("test 2: left padding\n"));
	result1 = printf("%%-5c = |%-5c|\n", c);
	result2 = ft_printf("%%-5c = |%-5c|\n", c);
	check_return(result1, result2);

	printf("---------------\n");
	printf(LIGHT_BLUE2("test 3: zero padding\n"));
	result1 = printf("%%05c = |%05c|\n", c);
	result2 = ft_printf("%%05c = |%05c|\n", c);
	check_return(result1, result2);
	result1 = printf("%%-05c = |%-05c|\n", c);
	result2 = ft_printf("%%-05c = |%-05c|\n", c);
	check_return(result1, result2);

	printf("---------------\n");
	printf(LIGHT_BLUE2("test 4: other flags\n"));
	result1 = printf("%%+5c = |%+5c|\n", c); // undefined behavior
	result2 = ft_printf("%%+5c = |%+5c|\n", c);
	check_return(result1, result2);
	result1 = printf("%%- 5c = |%- 5c|\n", c); // undefined behavior
	result2 = ft_printf("%%- 5c = |%- 5c|\n", c);
	check_return(result1, result2);
	result1 = printf("%%#5c = |%#5c|\n", c); // undefined behavior
	result2 = ft_printf("%%#5c = |%#5c|\n", c);
	check_return(result1, result2);

	printf("---------------\n");
	printf(PINK("\nPrecision flag tests:\n"));
	printf(LIGHT_BLUE2("test 5.1:\n"));
	result1 = printf("%%.5c = |%.5c|\n", c); // undefined behavior
	result2 = ft_printf("%%.5c = |%.5c|\n", c);
	check_return(result1, result2);
	result1 = printf("%%3.5c = |%3.5c|\n", c); // undefined behavior
	result2 = ft_printf("%%3.5c = |%3.5c|\n", c);
	check_return(result1, result2);
	printf("---------------\n");
	printf(LIGHT_BLUE2("test 5.2: precision = 0\n"));
	result1 = printf("%%.c = |%.c|\n", c);
	result2 = ft_printf("%%.c = |%.c|\n", c);
	check_return(result1, result2);
	result1 = printf("%%5.c = |%5.c|\n", c);
	result2 = ft_printf("%%5.c = |%5.c|\n", c);
	check_return(result1, result2);


	printf("---------------\n");
	printf(PINK("Flags positions variations\n"));
	printf(LIGHT_BLUE2("test 6:\n"));
	result1 = printf("%%5-c = |%5-c|\n", c);
	result2 = ft_printf("%%5-c = |%5-c|\n", c);
	check_return(result1, result2);
	result1 = printf("%%5+c = |%5+c|\n", c);
	result2 = ft_printf("%%5+c = |%5+c|\n", c);
	check_return(result1, result2);
	result1 = printf("%%5 c = |%5 c|\n", c);
	result2 = ft_printf("%%5 c = |%5 c|\n", c);
	check_return(result1, result2);
	result1 = printf("%%5#c = |%5#c|\n", c);
	result2 = ft_printf("%%5#c = |%5#c|\n", c);
	check_return(result1, result2);

	printf("---------------\n");
	printf(LIGHT_BLUE2("test 7:\n"));
	result1 = printf("%%-010.3c = |%-010.3c|\n", c);
	result2 = ft_printf("%%-010.3c = |%-010.3c|\n", c);
	check_return(result1, result2);
	result1 = printf("%%0-10.c = |%0-10.c|\n", c);
	result2 = ft_printf("%%0-10.c = |%0-10.c|\n", c);
	check_return(result1, result2);
	result1 = printf("%%.-05c = |%.-05c|\n", c);
	result2 = ft_printf("%%.-05c = |%.-05c|\n", c);
	check_return(result1, result2);
	result1 = printf("%%-0.5c = |%-0.5c|\n", c);
	result2 = ft_printf("%%-0.5c = |%-0.5c|\n", c);
	check_return(result1, result2);

	printf("---------------\n");
	printf(PINK("null char \\0 tests\n"));
	printf(LIGHT_BLUE2("\ntest 8:\n"));
	result1 = printf("%%c = |%c|\n", '\0');
	result2 = ft_printf("%%c = |%c|\n", '\0');
	check_return(result1, result2);
	result1 = printf("%%5c = |%5c|\n", '\0');
	result2 = ft_printf("%%5c = |%5c|\n", '\0');
	check_return(result1, result2);
	result1 = printf("%%-5c = |%-5c|\n", '\0');
	result2 = ft_printf("%%-5c = |%-5c|\n", '\0');
	check_return(result1, result2);
	result1 = printf("%%05c = |%05c|\n", '\0');
	result2 = ft_printf("%%05c = |%05c|\n", '\0');
	check_return(result1, result2);
	result1 = printf("%%.5c = |%.5c|\n", '\0');
	result2 = ft_printf("%%.5c = |%.5c|\n", '\0');
	check_return(result1, result2);
	result1 = printf("%%5.c = |%5.c|\n", '\0');
	result2 = ft_printf("%%5.c = |%5.c|\n", '\0');
	check_return(result1, result2);
	result1 = printf("%%05.c = |%05.c|\n", '\0');
	result2 = ft_printf("%%05.c = |%05.c|\n", '\0');
	check_return(result1, result2);
}