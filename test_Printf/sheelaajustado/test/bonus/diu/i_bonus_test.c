/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_bonus_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 04:16:12 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/21 20:35:27 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/test.h"

void	i_bonus_test()
{
	int	result1;
	int	result2;

	printf(LIGHT_RED("\nBonus test: printing signed int with flags - specifier i:\n"));
	printf(PINK("\nBasic tests:\n"));
	printf(LIGHT_BLUE2("test 1: width\n"));
	result1 = printf("%10s = |%5i|\n", "%5i", -42);
	result2 = ft_printf("%10s = |%5i|\n", "%5i", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%5i|\n", "%5i", 42);
	result2 = ft_printf("%10s = |%5i|\n", "%5i", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 2: left padding\n"));
	result1 = printf("%10s = |%-5i|\n", "%-5i", -42);
	result2 = ft_printf("%10s = |%-5i|\n", "%-5i", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%-5i|\n", "%-5i", 42);
	result2 = ft_printf("%10s = |%-5i|\n", "%-5i", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 3: zero padding\n"));
	result1 = printf("%10s = |%05i|\n", "%05i", -42);
	result2 = ft_printf("%10s = |%05i|\n", "%05i", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%05i|\n", "%05i", 42);
	result2 = ft_printf("%10s = |%05i|\n", "%05i", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%-05i|\n", "%-05i", -42);
	result2 = ft_printf("%10s = |%-05i|\n", "%-05i", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%-05i|\n", "%-05i", 42);
	result2 = ft_printf("%10s = |%-05i|\n", "%-05i", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%0-5i|\n", "%0-5i", -42);
	result2 = ft_printf("%10s = |%0-5i|\n", "%0-5i", -42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 4: sign flags\n"));
	result1 = printf("%10s = |%+5i|\n", "%+5i", -42);
	result2 = ft_printf("%10s = |%+5i|\n", "%+5i", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%+5i|\n", "%+5i", 42);
	result2 = ft_printf("%10s = |%+5i|\n", "%+5i", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |% 5i|\n", "% 5i", -42);
	result2 = ft_printf("%10s = |% 5i|\n", "% 5i", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |% 5i|\n", "% 5i", 42);
	result2 = ft_printf("%10s = |% 5i|\n", "% 5i", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 5: other flags\n"));
	result1 = printf("%10s = |%#5i|\n", "%#5i", -42);
	result2 = ft_printf("%10s = |%#5i|\n", "%#5i", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%#5i|\n", "%#5i", 42);
	result2 = ft_printf("%10s = |%#5i|\n", "%#5i", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(PINK("\nFlags combinations:\n"));
	printf(LIGHT_BLUE2("test 6.1:\n"));
	result1 = printf("%10s = |%5-0i|\n", "%5-0i", -42);
	result2 = ft_printf("%10s = |%5-0i|\n", "%5-0i", -42);
	check_return(result1, result2);
	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 6.2:\n"));
	result1 = printf("%10s = |%+05i|\n", "%+05i", -42);
	result2 = ft_printf("%10s = |%+05i|\n", "%+05i", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%+05i|\n", "%+05i", 42);
	result2 = ft_printf("%10s = |%+05i|\n", "%+05i", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%0+5i|\n", "%0+5i", -42);
	result2 = ft_printf("%10s = |%0+5i|\n", "%0+5i", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%0+5i|\n", "%0+5i", 42);
	result2 = ft_printf("%10s = |%0+5i|\n", "%0+5i", 42);
	check_return(result1, result2);
	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 6.3:\n"));
	result1 = printf("%10s = |% 05i|\n", "% 05i", -42);
	result2 = ft_printf("%10s = |% 05i|\n", "% 05i", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |% 05i|\n", "% 05i", 42);
	result2 = ft_printf("%10s = |% 05i|\n", "% 05i", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%0 5i|\n", "%0 5i", -42);
	result2 = ft_printf("%10s = |%0 5i|\n", "%0 5i", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%0 5i|\n", "%0 5i", 42);
	result2 = ft_printf("%10s = |%0 5i|\n", "%0 5i", 42);
	check_return(result1, result2);
	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 6.4:\n"));
	result1 = printf("%10s = |%-+05i|\n", "%-+05i", -42);
	result2 = ft_printf("%10s = |%-+05i|\n", "%-+05i", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%-+05i|\n", "%-+05i", 42);
	result2 = ft_printf("%10s = |%-+05i|\n", "%-+05i", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%+-05i|\n", "%+-05i", -42);
	result2 = ft_printf("%10s = |%+-05i|\n", "%+-05i", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%+-05i|\n", "%+-05i", 42);
	result2 = ft_printf("%10s = |%+-05i|\n", "%+-05i", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%0+-5i|\n", "%0+-5i", -42);
	result2 = ft_printf("%10s = |%0+-5i|\n", "%0+-5i", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%0+-5i|\n", "%0+-5i", 42);
	result2 = ft_printf("%10s = |%0+-5i|\n", "%0+-5i", 42);
	check_return(result1, result2);
	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 6.5:\n"));
	result1 = printf("%10s = |%- 05i|\n", "%- 05i", -42);
	result2 = ft_printf("%10s = |%- 05i|\n", "%- 05i", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%- 05i|\n", "%- 05i", 42);
	result2 = ft_printf("%10s = |%- 05i|\n", "%- 05i", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 6.6: #\n"));
	result1 = printf("%10s = |%+ 05i|\n", "%+ 05i", -42);
	result2 = ft_printf("%10s = |%+ 05i|\n", "%+ 05i", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%+ 05i|\n", "%+ 05i", 42);
	result2 = ft_printf("%10s = |%+ 05i|\n", "%+ 05i", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |% +05i|\n", "% +05i", -42);
	result2 = ft_printf("%10s = |% +05i|\n", "% +05i", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |% +05i|\n", "% +05i", 42);
	result2 = ft_printf("%10s = |% +05i|\n", "% +05i", 42);

	printf("--------------------------------\n");
	printf(PINK("\nPrecision flag tests:\n"));
	printf(LIGHT_BLUE2("test 7.1:\n"));
	result1 = printf("%10s = |%.4i|\n", "%.4i", -42);
	result2 = ft_printf("%10s = |%.4i|\n", "%.4i", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%.04i|\n", "%.04i", -42);
	result2 = ft_printf("%10s = |%.04i|\n", "%.04i", -42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 7.2: precision and width\n"));
	result1 = printf("%10s = |%5.3i|\n", "%5.3i", -42);
	result2 = ft_printf("%10s = |%5.3i|\n", "%5.3i", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%5.4i|\n", "%5.4i", -42);
	result2 = ft_printf("%10s = |%5.4i|\n", "%5.4i", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%5.4i|\n", "%5.4i", 42);
	result2 = ft_printf("%10s = |%5.4i|\n", "%5.4i", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 7.3: precision > width\n"));
	result1 = printf("%10s = |%5.8i|\n", "%5.8i", -42);
	result2 = ft_printf("%10s = |%5.8i|\n", "%5.8i", -42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 7.4: precision, width and sign\n"));
	result1 = printf("%10s = |%+5.4i|\n", "%+5.4i", 42);
	result2 = ft_printf("%10s = |%+5.4i|\n", "%+5.4i", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |% 5.4i|\n", "% 5.4i", 42);
	result2 = ft_printf("%10s = |% 5.4i|\n", "% 5.4i", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 7.5: precision and 0 padding\n"));
	result1 = printf("%10s = |%05.3i|\n", "%05.3i", -42);
	result2 = ft_printf("%10s = |%05.3i|\n", "%05.3i", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%05i|\n", "%05i", -42);
	result2 = ft_printf("%10s = |%05i|\n", "%05i", -42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 7.6: precision and left padding\n"));
	result1 = printf("%10s = |%-5.3i|\n", "%-5.3i", -42);
	result2 = ft_printf("%10s = |%-5.3i|\n", "%-5.3i", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%-5.4i|\n", "%-5.4i", 42);
	result2 = ft_printf("%10s = |%-5.4i|\n", "%-5.4i", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 7.7: presision = 0\n"));
	result1 = printf("%10s = |%05.-i|\n", "%05.-i", -42);
	result2 = ft_printf("%10s = |%05.-i|\n", "%05.-i", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%05.-i|\n", "%05.-i", 42);
	result2 = ft_printf("%10s = |%05.-i|\n", "%05.-i", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%05. i|\n", "%05. i", -42);
	result2 = ft_printf("%10s = |%05. i|\n", "%05. i", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%05. i|\n", "%05. i", 42);
	result2 = ft_printf("%10s = |%05. i|\n", "%05. i", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(PINK("\nnumber = 0\n"));
	result1 = printf("%%i = |%i|\n", 0);
	result2 = ft_printf("%%i = |%i|\n", 0);
	check_return(result1, result2);
	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 8.1:\n"));
	result1 = printf("%%5i = |%5i|\n", 0);
	result2 = ft_printf("%%5i = |%5i|\n", 0);
	result1 = printf("%%05i = |%05i|\n", 0);
	result2 = ft_printf("%%05i = |%05i|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%-5i = |%-5i|\n", 0);
	result2 = ft_printf("%%-5i = |%-5i|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%-05i = |%-05i|\n", 0);
	result2 = ft_printf("%%-05i = |%-05i|\n", 0);
	check_return(result1, result2);
	printf("--------------------------------\n");
	result1 = printf("%%+05i = |%+05i|\n", 0);
	result2 = ft_printf("%%+05i = |%+05i|\n", 0);
	check_return(result1, result2);
	result1 = printf("%% 05i = |% 05i|\n", 0);
	result2 = ft_printf("%% 05i = |% 05i|\n", 0);
	check_return(result1, result2);
	printf("--------------------------------\n");
	result1 = printf("%%#5i = |%#5i|\n", 0);
	result2 = ft_printf("%%#5i = |%#5i|\n", 0);
	check_return(result1, result2);
	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 8.2: precision\n"));
	result1 = printf("%%.5i = |%.5i|\n", 0);
	result2 = ft_printf("%%.5i = |%.5i|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%.i = |%.i|\n", 0);
	result2 = ft_printf("%%.i = |%.i|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%#.5i = |%#.5i|\n", 0);
	result2 = ft_printf("%%#.5i = |%#.5i|\n", 0);
	check_return(result1, result2);
	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 8.3: precision and width\n"));
	result1 = printf("%%+5.i = |%+5.i|\n", 0);
	result2 = ft_printf("%%+5.i = |%+5.i|\n", 0);
	check_return(result1, result2);
	result1 = printf("%10s = |%05.3i|\n", "%05.3i", 0);
	result2 = ft_printf("%10s = |%05.3i|\n", "%05.3i", 0);
	check_return(result1, result2);
	result1 = printf("%10s = |%-5.3i|\n", "%-5.3i", 0);
	result2 = ft_printf("%10s = |%-5.3i|\n", "%-5.3i", 0);
	check_return(result1, result2);
	result1 = printf("%10s = |%+-5.2i|\n", "%+-5.2i", 0);
	result2 = ft_printf("%10s = |%+-5.2i|\n", "%+-5.2i", 0);
	check_return(result1, result2);
	result1 = printf("%10s = |% -5.2i|\n", "% -5.2i", 0);
	result2 = ft_printf("%10s = |% -5.2i|\n", "% -5.2i", 0);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(PINK("\nBigger number\n"));
	printf(LIGHT_BLUE2("test 9:\n"));
	result1 = printf("%%10i = |%10i|\n", 1000000);
	result2 = ft_printf("%%10i = |%10i|\n", 1000000);
	check_return(result1, result2);
	result1 = printf("%%010i = |%010i|\n", 1000000);
	result2 = ft_printf("%%010i = |%010i|\n", 1000000);
	check_return(result1, result2);
	result1 = printf("%%-010i = |%-010i|\n", 1000000);
	result2 = ft_printf("%%-010i = |%-010i|\n", 1000000);
	check_return(result1, result2);
	printf("--------------------------------\n");
	result1 = printf("%%5.3i = |%5.3i|\n", 1000000);
	result2 = ft_printf("%%5.3i = |%5.3i|\n", 1000000);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 10:\n"));
	result1 = printf("%%10.3i = |%10.3i|\n", -1000);
	result2 = ft_printf("%%10.3i = |%10.3i|\n", -1000);
	check_return(result1, result2);
}
