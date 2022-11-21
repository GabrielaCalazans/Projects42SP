/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_bonus_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 04:50:02 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/21 20:16:13 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/test.h"

void	p_bonus_test()
{
	int	result1;
	int	result2;
	int	i = 42;

	// printing pointer - specifier p
	printf(LIGHT_RED("\n\nBonus test: printing pointer with flags - specifier p:\n"));
	result1 = printf("%%p = |%p|\n", &i);
	result2 = ft_printf("%%p = |%p|\n", &i);
	check_return(result1, result2);
	printf("---------------\n");
	printf(PINK("\nBasic tests:\n"));
	printf(LIGHT_BLUE2("test 1: width\n"));
	result1 = printf("%%20p = |%20p|\n", &i);
	result2 = ft_printf("%%20p = |%20p|\n", &i);
	check_return(result1, result2);
	printf("---------------\n");
	printf(LIGHT_BLUE2("test 2: left padding\n"));
	result1 = printf("%%-20p = |%-20p|\n", &i);
	result2 = ft_printf("%%-20p = |%-20p|\n", &i);
	check_return(result1, result2);

	printf("---------------\n");
	printf(LIGHT_BLUE2("test 4: 0 padding\n"));
	result1 = printf("%%020p = |%020p|\n", &i);
	result2 = ft_printf("%%020p = |%020p|\n", &i);
	check_return(result1, result2);
	result1 = printf("%%-020p = |%-020p|\n", &i);
	result2 = ft_printf("%%-020p = |%-020p|\n", &i);
	check_return(result1, result2);

	printf("---------------\n");
	printf(PINK("Precision tests\n"));
	printf(LIGHT_BLUE2("\ntest 5.1:\n"));
	result1 = printf("%%.3p = |%.3p|\n", &i);
	result2 = ft_printf("%%.3p = |%.3p|\n", &i);
	check_return(result1, result2);
	result1 = printf("%%.15p = |%.15p|\n", &i);
	result2 = ft_printf("%%.15p = |%.15p|\n", &i);
	check_return(result1, result2);

	printf("---------------\n");
	printf(LIGHT_BLUE2("\ntest 5.2: precision and width\n"));
	result1 = printf("%%20.15p = |%20.15p|\n", &i);
	result2 = ft_printf("%%20.15p = |%20.15p|\n", &i);
	check_return(result1, result2);
	result1 = printf("%%-20.15p = |%-20.15p|\n", &i);
	result2 = ft_printf("%%-20.15p = |%-20.15p|\n", &i);
	check_return(result1, result2);
	result1 = printf("%%020.15p = |%020.15p|\n", &i);
	result2 = ft_printf("%%020.15p = |%020.15p|\n", &i);
	check_return(result1, result2);

	printf("---------------\n");
	printf(LIGHT_BLUE2("test 5.3: precision = 0\n"));
	result1 = printf("%%.p = |%.p|\n", &i);
	result2 = ft_printf("%%.p = |%.p|\n", &i);
	check_return(result1, result2);

	printf("---------------\n");
	printf(PINK("Invalids flags for p specifier\n"));
	printf(LIGHT_BLUE2("\ntest 6:\n"));
	result1 = printf("%%+20p = |%+20p|\n", &i);
	result2 = ft_printf("%%+20p = |%+20p|\n", &i);
	check_return(result1, result2);
	result1 = printf("%%- 20p = |%- 20p|\n", &i);
	result2 = ft_printf("%%- 20p = |%- 20p|\n", &i);
	check_return(result1, result2);
	result1 = printf("%%#20p = |%#20p|\n", &i);
	result2 = ft_printf("%%#20p = |%#20p|\n", &i);
	check_return(result1, result2);

	printf("---------------\n");
	printf(PINK("\nnumber = 0\n"));
	printf(LIGHT_BLUE2("\ntest 7.1:\n"));
	result1 = printf("%%p = |%p|\n", 0);
	result2 = ft_printf("%%p = |%p|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%5p = |%5p|\n", 0);
	result2 = ft_printf("%%5p = |%5p|\n", 0);
	check_return(result1, result2);
	printf("---------------\n");
	result1 = printf("%%05p = |%05p|\n", 0);
	result2 = ft_printf("%%05p = |%05p|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%-5p = |%-5p|\n", 0);
	result2 = ft_printf("%%-5p = |%-5p|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%-05p = |%-05p|\n", 0);
	result2 = ft_printf("%%-05p = |%-05p|\n", 0);
	check_return(result1, result2);
	printf("---------------\n");
	printf(LIGHT_BLUE2("\ntest 7.2: precision\n"));
	result1 = printf("%%.5p = |%.5p|\n", 0);
	result2 = ft_printf("%%.5p = |%.5p|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%.05p = |%.05p|\n", 0);
	result2 = ft_printf("%%.05p = |%.05p|\n", 0);
	check_return(result1, result2);
	printf("---------------\n");
	printf(LIGHT_BLUE2("\ntest 7.3: precision and pad\n"));
	result1 = printf("%10s = |%05.3p|\n", "%05.3p", 0);
	result2 = ft_printf("%10s = |%05.3p|\n", "%05.3p", 0);
	check_return(result1, result2);
	printf("---------------\n");
	result1 = printf("%%8.5p = |%8.5p|\n", 0);
	result2 = ft_printf("%%8.5p = |%8.5p|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%08.5p = |%08.5p|\n", 0);
	result2 = ft_printf("%%08.5p = |%08.5p|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%-8.5p = |%-8.5p|\n", 0);
	result2 = ft_printf("%%-8.5p = |%-8.5p|\n", 0);
	check_return(result1, result2);

	printf("---------------\n");
	printf(PINK("\nprecision = 0 and number = 0\n"));
	printf(LIGHT_BLUE2("\ntest 8:\n"));
	result1 = printf("%%.p = |%.p|\n", 0);
	result2 = ft_printf("%%.p = |%.p|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%5.p = |%5.p|\n", 0);
	result2 = ft_printf("%%5.p = |%5.p|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%.-5p = |%.-5p|\n", 0);
	result2 = ft_printf("%%.-5p = |%.-5p|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%05.p = |%05.p|\n", 0);
	result2 = ft_printf("%%05.p = |%05.p|\n", 0);
	check_return(result1, result2);
}
