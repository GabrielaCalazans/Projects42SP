/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_bonus_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 04:24:22 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/21 20:59:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/test.h"

void	u_bonus_test()
{
	int	result1;
	int	result2;

	printf(LIGHT_RED("\nBonus test: printing unsigned int with flags- specifier u:\n"));
	printf(PINK("\nBasic tests:\n"));
	printf(LIGHT_BLUE2("test 1: width\n"));
	result1 = printf("%10s = |%5u|\n", "%5u", 42);
	result2 = ft_printf("%10s = |%5u|\n", "%5u", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%5u|\n", "%5u", -42);
	result2 = ft_printf("%10s = |%5u|\n", "%5u", -42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 2: left padding\n"));
	result1 = printf("%10s = |%-5u|\n", "%-5u", 42);
	result2 = ft_printf("%10s = |%-5u|\n", "%-5u", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 3: zero padding\n"));
	result1 = printf("%10s = |%05u|\n", "%05u", 42);
	result2 = ft_printf("%10s = |%05u|\n", "%05u", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%-05u|\n", "%-05u", 42);
	result2 = ft_printf("%10s = |%-05u|\n", "%-05u", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%0-5u|\n", "%0-5u", 42);
	result2 = ft_printf("%10s = |%0-5u|\n", "%0-5u", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 4: sign flags\n"));
	result1 = printf("%10s = |%+5u|\n", "%+5u", -42);
	result2 = ft_printf("%10s = |%+5u|\n", "%+5u", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |%+5u|\n", "%+5u", 42);
	result2 = ft_printf("%10s = |%+5u|\n", "%+5u", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |% 5u|\n", "% 5u", -42);
	result2 = ft_printf("%10s = |% 5u|\n", "% 5u", -42);
	check_return(result1, result2);
	result1 = printf("%10s = |% 5u|\n", "% 5u", 42);
	result2 = ft_printf("%10s = |% 5u|\n", "% 5u", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 5: other flags\n"));
	result1 = printf("%10s = |%#5u|\n", "%#5u", 42);
	result2 = ft_printf("%10s = |%#5u|\n", "%#5u", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(PINK("\nFlags combinations:\n"));
	printf(LIGHT_BLUE2("test 6.1:\n"));
	result1 = printf("%10s = |%5-0u|\n", "%5-0u", 42);
	result2 = ft_printf("%10s = |%5-0u|\n", "%5-0u", 42);
	check_return(result1, result2);
	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 6.2:\n"));
	result1 = printf("%10s = |%+05u|\n", "%+05u", 42);
	result2 = ft_printf("%10s = |%+05u|\n", "%+05u", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%0+5u|\n", "%0+5u", 42);
	result2 = ft_printf("%10s = |%0+5u|\n", "%0+5u", 42);
	check_return(result1, result2);
	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 6.3:\n"));
	result1 = printf("%10s = |% 05u|\n", "% 05u", 42);
	result2 = ft_printf("%10s = |% 05u|\n", "% 05u", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%0 5u|\n", "%0 5u", 42);
	result2 = ft_printf("%10s = |%0 5u|\n", "%0 5u", 42);
	check_return(result1, result2);
	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 6.4:\n"));
	result1 = printf("%10s = |%-+05u|\n", "%-+05u", 42);
	result2 = ft_printf("%10s = |%-+05u|\n", "%-+05u", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%+-05u|\n", "%+-05u", 42);
	result2 = ft_printf("%10s = |%+-05u|\n", "%+-05u", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%0+-5u|\n", "%0+-5u", 42);
	result2 = ft_printf("%10s = |%0+-5u|\n", "%0+-5u", 42);
	check_return(result1, result2);
	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 6.5:\n"));
	result1 = printf("%10s = |%- 05u|\n", "%- 05u", 42);
	result2 = ft_printf("%10s = |%- 05u|\n", "%- 05u", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 6.6: #\n"));
	result1 = printf("%10s = |%+ 05u|\n", "%+ 05u", 42);
	result2 = ft_printf("%10s = |%+ 05u|\n", "%+ 05u", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |% +05u|\n", "% +05u", 42);
	result2 = ft_printf("%10s = |% +05u|\n", "% +05u", 42);

	printf("--------------------------------\n");
	printf(PINK("\nPrecision flag tests:\n"));
	printf(LIGHT_BLUE2("test 7.1:\n"));
	result1 = printf("%10s = |%.4u|\n", "%.4u", 42);
	result2 = ft_printf("%10s = |%.4u|\n", "%.4u", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%.04u|\n", "%.04u", 42);
	result2 = ft_printf("%10s = |%.04u|\n", "%.04u", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 7.2: precision and width\n"));
	result1 = printf("%10s = |%5.3u|\n", "%5.3u", 42);
	result2 = ft_printf("%10s = |%5.3u|\n", "%5.3u", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%5.4u|\n", "%5.4u", 42);
	result2 = ft_printf("%10s = |%5.4u|\n", "%5.4u", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 7.3: precision > width\n"));
	result1 = printf("%10s = |%5.8u|\n", "%5.8u", 42);
	result2 = ft_printf("%10s = |%5.8u|\n", "%5.8u", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 7.4: precision, width and sign\n"));
	result1 = printf("%10s = |%+5.4u|\n", "%+5.4u", 42);
	result2 = ft_printf("%10s = |%+5.4u|\n", "%+5.4u", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |% 5.4u|\n", "% 5.4u", 42);
	result2 = ft_printf("%10s = |% 5.4u|\n", "% 5.4u", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 7.5: precision and 0 padding\n"));
	result1 = printf("%10s = |%05.3u|\n", "%05.3u", 42);
	result2 = ft_printf("%10s = |%05.3u|\n", "%05.3u", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%05u|\n", "%05u", 42);
	result2 = ft_printf("%10s = |%05u|\n", "%05u", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 7.6: precision and left padding\n"));
	result1 = printf("%10s = |%-5.3u|\n", "%-5.3u", 42);
	result2 = ft_printf("%10s = |%-5.3u|\n", "%-5.3u", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%-5.4u|\n", "%-5.4u", 42);
	result2 = ft_printf("%10s = |%-5.4u|\n", "%-5.4u", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 7.7: presision = 0\n"));
	result1 = printf("%10s = |%05.-u|\n", "%05.-u", 42);
	result2 = ft_printf("%10s = |%05.-u|\n", "%05.-u", 42);
	check_return(result1, result2);
	result1 = printf("%10s = |%05. u|\n", "%05. u", 42);
	result2 = ft_printf("%10s = |%05. u|\n", "%05. u", 42);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(PINK("\nnumber = 0\n"));
	result1 = printf("%%u = |%u|\n", 0);
	result2 = ft_printf("%%u = |%u|\n", 0);
	check_return(result1, result2);
	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 8.1:\n"));
	result1 = printf("%%5u = |%5u|\n", 0);
	result2 = ft_printf("%%5u = |%5u|\n", 0);
	result1 = printf("%%05u = |%05u|\n", 0);
	result2 = ft_printf("%%05u = |%05u|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%-5u = |%-5u|\n", 0);
	result2 = ft_printf("%%-5u = |%-5u|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%-05u = |%-05u|\n", 0);
	result2 = ft_printf("%%-05u = |%-05u|\n", 0);
	check_return(result1, result2);
	printf("--------------------------------\n");
	result1 = printf("%%+05u = |%+05u|\n", 0);
	result2 = ft_printf("%%+05u = |%+05u|\n", 0);
	check_return(result1, result2);
	result1 = printf("%% 05u = |% 05u|\n", 0);
	result2 = ft_printf("%% 05u = |% 05u|\n", 0);
	check_return(result1, result2);
	printf("--------------------------------\n");
	result1 = printf("%%#5u = |%#5u|\n", 0);
	result2 = ft_printf("%%#5u = |%#5u|\n", 0);
	check_return(result1, result2);
	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 8.2:\n"));
	result1 = printf("%%.5u = |%.5u|\n", 0);
	result2 = ft_printf("%%.5u = |%.5u|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%.u = |%.u|\n", 0);
	result2 = ft_printf("%%.u = |%.u|\n", 0);
	check_return(result1, result2);
	result1 = printf("%%#.5u = |%#.5u|\n", 0);
	result2 = ft_printf("%%#.5u = |%#.5u|\n", 0);
	check_return(result1, result2);
	printf("--------------------------------\n");
	printf(LIGHT_BLUE2("test 8.3:\n"));
	result1 = printf("%10s = |%05.3u|\n", "%05.3u", 0);
	result2 = ft_printf("%10s = |%05.3u|\n", "%05.3u", 0);
	check_return(result1, result2);
	result1 = printf("%10s = |%-5.3u|\n", "%-5.3u", 0);
	result2 = ft_printf("%10s = |%-5.3u|\n", "%-5.3u", 0);
	check_return(result1, result2);
	result1 = printf("%10s = |%+-5.2u|\n", "%+-5.2u", 0);
	result2 = ft_printf("%10s = |%+-5.2u|\n", "%+-5.2u", 0);
	check_return(result1, result2);
	result1 = printf("%10s = |% -5.2u|\n", "% -5.2u", 0);
	result2 = ft_printf("%10s = |% -5.2u|\n", "% -5.2u", 0);
	check_return(result1, result2);

	printf("--------------------------------\n");
	printf(PINK("\nBigger number\n"));
	printf(LIGHT_BLUE2("test 9:\n"));
	result1 = printf("%%10u = |%10u|\n", 1000000);
	result2 = ft_printf("%%10u = |%10u|\n", 1000000);
	check_return(result1, result2);
	result1 = printf("%%010u = |%010u|\n", 1000000);
	result2 = ft_printf("%%010u = |%010u|\n", 1000000);
	check_return(result1, result2);
	result1 = printf("%%-010u = |%-010u|\n", 1000000);
	result2 = ft_printf("%%-010u = |%-010u|\n", 1000000);
	check_return(result1, result2);
	printf("--------------------------------\n");
	result1 = printf("%%5.3u = |%5.3u|\n", 1000000);
	result2 = ft_printf("%%5.3u = |%5.3u|\n", 1000000);
	check_return(result1, result2);
}