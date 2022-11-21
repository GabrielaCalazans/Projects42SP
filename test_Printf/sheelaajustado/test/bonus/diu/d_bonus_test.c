/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_bonus_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 04:17:43 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/21 20:15:27 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/test.h"

void	d_bonus_test()
{
	int	result1;
	int	result2;

	printf(LIGHT_RED("\nBonus test: printing decimal int with flags - specifier d:\n"));
	printf(PINK("\nBasic tests:\n"));
	printf(LIGHT_BLUE2("test 1: width\n"));
	result1 = printf("%10s = |%5d|\n", "%5d", -42);
	result2 = ft_printf("%10s = |%5d|\n", "%5d", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%5d|\n", "%5d", 42);
	result2 = ft_printf("%10s = |%5d|\n", "%5d", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 2: left padding\n"));
	result1 = printf("%10s = |%-5d|\n", "%-5d", -42);
	result2 = ft_printf("%10s = |%-5d|\n", "%-5d", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%-5d|\n", "%-5d", 42);
	result2 = ft_printf("%10s = |%-5d|\n", "%-5d", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 3: zero padding\n"));
	result1 = printf("%10s = |%05d|\n", "%05d", -42);
	result2 = ft_printf("%10s = |%05d|\n", "%05d", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%05d|\n", "%05d", 42);
	result2 = ft_printf("%10s = |%05d|\n", "%05d", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%-05d|\n", "%-05d", -42);
	result2 = ft_printf("%10s = |%-05d|\n", "%-05d", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%-05d|\n", "%-05d", 42);
	result2 = ft_printf("%10s = |%-05d|\n", "%-05d", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%0-5d|\n", "%0-5d", -42);
	result2 = ft_printf("%10s = |%0-5d|\n", "%0-5d", -42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 4: sign flags\n"));
	result1 = printf("%10s = |%+5d|\n", "%+5d", -42);
	result2 = ft_printf("%10s = |%+5d|\n", "%+5d", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%+5d|\n", "%+5d", 42);
	result2 = ft_printf("%10s = |%+5d|\n", "%+5d", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |% 5d|\n", "% 5d", -42);
	result2 = ft_printf("%10s = |% 5d|\n", "% 5d", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |% 5d|\n", "% 5d", 42);
	result2 = ft_printf("%10s = |% 5d|\n", "% 5d", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 5: other flags\n"));
	result1 = printf("%10s = |%#5d|\n", "%#5d", -42);
	result2 = ft_printf("%10s = |%#5d|\n", "%#5d", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%#5d|\n", "%#5d", 42);
	result2 = ft_printf("%10s = |%#5d|\n", "%#5d", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(PINK("\nFlags combinations:\n"));
	printf(LIGHT_BLUE2("test 6.1:\n"));
	result1 = printf("%10s = |%5-0d|\n", "%5-0d", -42);
	result2 = ft_printf("%10s = |%5-0d|\n", "%5-0d", -42);
	check_return(result1, result2);
	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 6.2:\n"));
	result1 = printf("%10s = |%+05d|\n", "%+05d", -42);
	result2 = ft_printf("%10s = |%+05d|\n", "%+05d", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%+05d|\n", "%+05d", 42);
	result2 = ft_printf("%10s = |%+05d|\n", "%+05d", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%0+5d|\n", "%0+5d", -42);
	result2 = ft_printf("%10s = |%0+5d|\n", "%0+5d", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%0+5d|\n", "%0+5d", 42);
	result2 = ft_printf("%10s = |%0+5d|\n", "%0+5d", 42);
	check_return(result1, result2);
	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 6.3:\n"));
	result1 = printf("%10s = |% 05d|\n", "% 05d", -42);
	result2 = ft_printf("%10s = |% 05d|\n", "% 05d", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |% 05d|\n", "% 05d", 42);
	result2 = ft_printf("%10s = |% 05d|\n", "% 05d", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%0 5d|\n", "%0 5d", -42);
	result2 = ft_printf("%10s = |%0 5d|\n", "%0 5d", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%0 5d|\n", "%0 5d", 42);
	result2 = ft_printf("%10s = |%0 5d|\n", "%0 5d", 42);
	check_return(result1, result2);
	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 6.4:\n"));
	result1 = printf("%10s = |%-+05d|\n", "%-+05d", -42);
	result2 = ft_printf("%10s = |%-+05d|\n", "%-+05d", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%-+05d|\n", "%-+05d", 42);
	result2 = ft_printf("%10s = |%-+05d|\n", "%-+05d", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%+-05d|\n", "%+-05d", -42);
	result2 = ft_printf("%10s = |%+-05d|\n", "%+-05d", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%+-05d|\n", "%+-05d", 42);
	result2 = ft_printf("%10s = |%+-05d|\n", "%+-05d", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%0+-5d|\n", "%0+-5d", -42);
	result2 = ft_printf("%10s = |%0+-5d|\n", "%0+-5d", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%0+-5d|\n", "%0+-5d", 42);
	result2 = ft_printf("%10s = |%0+-5d|\n", "%0+-5d", 42);
	check_return(result1, result2);
	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 6.5:\n"));
	result1 = printf("%10s = |%- 05d|\n", "%- 05d", -42);
	result2 = ft_printf("%10s = |%- 05d|\n", "%- 05d", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%- 05d|\n", "%- 05d", 42);
	result2 = ft_printf("%10s = |%- 05d|\n", "%- 05d", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 6.6: #\n"));
	result1 = printf("%10s = |%+ 05d|\n", "%+ 05d", -42);
	result2 = ft_printf("%10s = |%+ 05d|\n", "%+ 05d", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%+ 05d|\n", "%+ 05d", 42);
	result2 = ft_printf("%10s = |%+ 05d|\n", "%+ 05d", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |% +05d|\n", "% +05d", -42);
	result2 = ft_printf("%10s = |% +05d|\n", "% +05d", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |% +05d|\n", "% +05d", 42);
	result2 = ft_printf("%10s = |% +05d|\n", "% +05d", 42);

	printf("--------------------------------\n");
	printf(PINK("\nPrecision flag tests:\n"));
	printf(LIGHT_BLUE2("test 7.1:\n"));
	result1 = printf("%10s = |%.4d|\n", "%.4d", -42);
	result2 = ft_printf("%10s = |%.4d|\n", "%.4d", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%.04d|\n", "%.04d", -42);
	result2 = ft_printf("%10s = |%.04d|\n", "%.04d", -42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 7.2: precision and width\n"));
	result1 = printf("%10s = |%5.3d|\n", "%5.3d", -42);
	result2 = ft_printf("%10s = |%5.3d|\n", "%5.3d", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%5.4d|\n", "%5.4d", -42);
	result2 = ft_printf("%10s = |%5.4d|\n", "%5.4d", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%5.4d|\n", "%5.4d", 42);
	result2 = ft_printf("%10s = |%5.4d|\n", "%5.4d", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 7.3: precision > width\n"));
	result1 = printf("%10s = |%5.8d|\n", "%5.8d", -42);
	result2 = ft_printf("%10s = |%5.8d|\n", "%5.8d", -42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 7.4: precision, width and sign\n"));
	result1 = printf("%10s = |%+5.4d|\n", "%+5.4d", 42);
	result2 = ft_printf("%10s = |%+5.4d|\n", "%+5.4d", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |% 5.4d|\n", "% 5.4d", 42);
	result2 = ft_printf("%10s = |% 5.4d|\n", "% 5.4d", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 7.5: precision and 0 padding\n"));
	result1 = printf("%10s = |%05.3d|\n", "%05.3d", -42);
	result2 = ft_printf("%10s = |%05.3d|\n", "%05.3d", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%05d|\n", "%05d", -42);
	result2 = ft_printf("%10s = |%05d|\n", "%05d", -42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 7.6: precision and left padding\n"));
	result1 = printf("%10s = |%-5.3d|\n", "%-5.3d", -42);
	result2 = ft_printf("%10s = |%-5.3d|\n", "%-5.3d", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%-5.4d|\n", "%-5.4d", 42);
	result2 = ft_printf("%10s = |%-5.4d|\n", "%-5.4d", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 7.7: presision = 0\n"));
	result1 = printf("%10s = |%05.-d|\n", "%05.-d", -42);
	result2 = ft_printf("%10s = |%05.-d|\n", "%05.-d", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%05.-d|\n", "%05.-d", 42);
	result2 = ft_printf("%10s = |%05.-d|\n", "%05.-d", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%05. d|\n", "%05. d", -42);
	result2 = ft_printf("%10s = |%05. d|\n", "%05. d", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%05. d|\n", "%05. d", 42);
	result2 = ft_printf("%10s = |%05. d|\n", "%05. d", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(PINK("\nnumber = 0\n"));
	result1 = printf("%%d = |%d|\n", 0);
	result2 = ft_printf("%%d = |%d|\n", 0);
	check_return(result1, result2);
	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 8.1:\n"));
	result1 = printf("%%5d = |%5d|\n", 0);
	result2 = ft_printf("%%5d = |%5d|\n", 0);
	result1 = printf("%%05d = |%05d|\n", 0);
	result2 = ft_printf("%%05d = |%05d|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%-5d = |%-5d|\n", 0);
	result2 = ft_printf("%%-5d = |%-5d|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%-05d = |%-05d|\n", 0);
	result2 = ft_printf("%%-05d = |%-05d|\n", 0);
	check_return(result1, result2);
	printf("--------------------------------\n");
	result1 = printf("%%+05i = |%+05i|\n", 0);
	result2 = ft_printf("%%+05i = |%+05i|\n", 0);
	check_return(result1, result2);
	result1 = printf("%% 05i = |% 05i|\n", 0);
	result2 = ft_printf("%% 05i = |% 05i|\n", 0);
	check_return(result1, result2);
	printf("--------------------------------\n");
	result1 = printf("%%#5d = |%#5d|\n", 0);
	result2 = ft_printf("%%#5d = |%#5d|\n", 0);
	check_return(result1, result2);
	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 8.2:\n"));
	result1 = printf("%%.5d = |%.5d|\n", 0);
	result2 = ft_printf("%%.5d = |%.5d|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%.d = |%.d|\n", 0);
	result2 = ft_printf("%%.d = |%.d|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%#.5d = |%#.5d|\n", 0);
	result2 = ft_printf("%%#.5d = |%#.5d|\n", 0);
	check_return(result1, result2);
	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 8.3:\n"));
	result1 = printf("%10s = |%05.3d|\n", "%05.3d", 0);
	result2 = ft_printf("%10s = |%05.3d|\n", "%05.3d", 0);
	check_return(result1, result2);
	result1 = printf("%10s = |%-5.3d|\n", "%-5.3d", 0);
	result2 = ft_printf("%10s = |%-5.3d|\n", "%-5.3d", 0);
	check_return(result1, result2);
	result1 = printf("%10s = |%+-5.2d|\n", "%+-5.2d", 0);
	result2 = ft_printf("%10s = |%+-5.2d|\n", "%+-5.2d", 0);
	check_return(result1, result2);
	result1 = printf("%10s = |% -5.2d|\n", "% -5.2d", 0);
	result2 = ft_printf("%10s = |% -5.2d|\n", "% -5.2d", 0);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(PINK("\nBigger number\n"));
	printf(LIGHT_BLUE2("test 9:\n"));
	result1 = printf("%%10d = |%10d|\n", 1000000);
	result2 = ft_printf("%%10d = |%10d|\n", 1000000);
	check_return(result1, result2);
	result1 = printf("%%010d = |%010d|\n", 1000000);
	result2 = ft_printf("%%010d = |%010d|\n", 1000000);
	check_return(result1, result2);
	result1 = printf("%%-010d = |%-010d|\n", 1000000);
	result2 = ft_printf("%%-010d = |%-010d|\n", 1000000);
	check_return(result1, result2);
	printf("--------------------------------\n");
	result1 = printf("%%5.3d = |%5.3d|\n", 1000000);
	result2 = ft_printf("%%5.3d = |%5.3d|\n", 1000000);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 10:\n"));
	result1 = printf("%%10.3d = |%10.3d|\n", -1000);
	result2 = ft_printf("%%10.3d = |%10.3d|\n", -1000);
	check_return(result1, result2);
}