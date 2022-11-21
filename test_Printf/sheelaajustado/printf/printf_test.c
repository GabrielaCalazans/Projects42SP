/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 22:46:27 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/19 19:11:33 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_printf.h"

int	main(void){
	/* ************************* Printf ******************************** */
	// int	printf(const char *format, ...)
	// formatation tags: [flags][width][.precision][length]specifier
	// return value: the total number of characters written. On failure, return a negative number.

	printf(LIGHT_PURPLE("\nLet's see how printf function works?\n\n"));
	/*printf(LIGHT_BLUE2("formatation tags: %%[flags][width][.precision][length]specifier\n\n"));
	printf(LIGHT_PURPLE("************************************* Mandatory *************************************\n\n"));
	printf(LIGHT_RED("Printf return:\n\n"));
	int	result;
	result = printf("printing with printf\n");
	printf("printf return = %i\n", result);
	result = printf("printing %s", "with printf\n");
	printf("printf return = %i\n", result);
	result = printf("%25s", "printing with printf\n");
	printf("printf return = %i\n", result);
	result = printf(LIGHT_BLUE2("%25s"), "printing with printf\n"); // LIGHT_BLUE2 = 10 + 4
	printf("printf return = %i = 25 (width) + 14 (LIGHT_BLUE2 format size)\n", result);*/

	/*printf(LIGHT_RED("Specifiers: c, s, d, i, u, p, x and X\n\n"));*/

	char	c = 'a';
	char	str[13] = "Hello World!";
	int		i = -42;
	unsigned int	j = 42;
	int *ptr = &i;
/*
	// ***************** basic printing tests ************************ \\

	// printing %
	printf(PINK("printing %%:\n"));
	printf(LIGHT_BLUE2("test %% without flags, width, precision or a specifier after - it prints just the %:\n"));
	printf(LIGHT_BLUE2("%_this is a test\n"));
	printf(LIGHT_BLUE2("%kanother test\n"));

	printf(PINK("\nwhen we do not indicate the variable, it prints anything from a place in the memory according with the variable type:\n"));
	printf(LIGHT_BLUE2("%%c: %c\n"));
	printf(LIGHT_BLUE2("%%i: %i\n"));
	printf(LIGHT_BLUE2("%%x: %x\n"));

	// printing char - specifier c
	printf(LIGHT_RED("\n\nprinting char - specifier c:\n"));
	printf(LIGHT_BLUE2("char %%c = %c\n"), c);
	printf(LIGHT_BLUE2("char %%c < 0: %c\n"), -1);
	printf(LIGHT_BLUE2("char %%c > 256: %c\n"), 257);
	printf(PINK("\n------------------------------- Testing Flags ----------------------------\n\n"));
	printf(LIGHT_BLUE2("%15s = |%c|\n"), "%%c", c);
	printf(LIGHT_BLUE2("%15s = |%5c|\n"), "%%5c", c);
	printf(LIGHT_BLUE2("%15s = |%-5c|\n"), "%%-5c", c);
	printf(LIGHT_BLUE2("%15s = |%05c|\n"), "%%05c", c);
	printf(LIGHT_BLUE2("%15s = |%-05c|\n"), "%%-05c", c);
	printf(LIGHT_BLUE2("%15s = |%0-5c|\n"), "%%0-5c", c);

	// printing string - specifier s
	printf(LIGHT_RED("\n\nprinting string - specifier s:\n"));
	printf(LIGHT_BLUE2("string %%s = %s\n"), str);
	printf(PINK("\n------------------------------- Testing Flags ----------------------------\n\n"));
	printf(LIGHT_BLUE2("%30s |%-010s|\n"), "%%-010s =", str);
	printf(LIGHT_BLUE2("%30s |%-012s|\n"), "%%-012s =", str);
	printf(LIGHT_BLUE2("%30s |%20s|\n"), "%%20s =", str);
	printf(LIGHT_BLUE2("%30s |%-20s|\n"), "%%-20s =", str);
	printf(LIGHT_BLUE2("%30s |%020s|\n"), "%%020s =", str);
	printf(LIGHT_BLUE2("%30s |%20s|\n"), "%%20s =", str);
	printf(LIGHT_BLUE2("%30s |%-020s|\n"), "%%-020s =", str);


	// printing signed decimal integer - specifiers d and i
	printf(LIGHT_RED("\n\nprinting signed decimal integer - specifiers d and i:\n"));
	printf(LIGHT_BLUE2("number %%d = %d\n"), i);
	printf(LIGHT_BLUE2("number %%d using pointer = %d\n"), *ptr);
	printf(LIGHT_BLUE2("number %%d > maximum signed integer = %d\n"), 2147483648);
	printf(LIGHT_BLUE2("number %%d < minimum signed integer = %d\n"), -2147483649);
	printf(LIGHT_BLUE2("number %%i = %i\n"), i);
	printf(LIGHT_BLUE2("number %%i using pointer = %i\n"), *ptr);
	printf(LIGHT_BLUE2("number %%i > maximum signed integer = %i\n"), 2147483648);
	printf(LIGHT_BLUE2("number %%i < minimum signed integer = %i\n"), -2147483649);*/
	printf(PINK("\n------------------------------- Testing Flags ----------------------------\n\n"));
	printf(LIGHT_BLUE2("%15s = |%5i|\n"), "%5i", i);
	printf(LIGHT_BLUE2("%15s = |%5i|\n"), "%5i", 42);
	printf("-------------------------------------\n");
	printf(LIGHT_BLUE2("%15s = |%-5i|\n"), "%05i", i);
	printf(LIGHT_BLUE2("%15s = |%-5i|\n"), "%05i", 42);
	printf(LIGHT_BLUE2("%15s = |%05i|\n"), "%05i", i);
	printf(LIGHT_BLUE2("%15s = |%05i|\n"), "%05i", 42);
	printf(LIGHT_BLUE2("%15s = |%+5i|\n"), "%+5i", i);
	printf(LIGHT_BLUE2("%15s = |%+5i|\n"), "%+5i", 42);
	printf(LIGHT_BLUE2("%15s = |% 5i|\n"), "% 5i", i);
	printf(LIGHT_BLUE2("%15s = |% 5i|\n"), "% 5i", 42);
	printf("-------------------------------------\n");
	printf(LIGHT_BLUE2("%15s = |%-05i|\n"), "%-05i", i);
	printf(LIGHT_BLUE2("%15s = |%-05i|\n"), "%-05i", 42);
	printf(LIGHT_BLUE2("%15s = |%0-5i|\n"), "%0-5i", i);
	printf("-------------------------------------\n");
	printf(LIGHT_BLUE2("%15s = |%5-0i|\n"), "%5-0i", i);
	printf("-------------------------------------\n");
	printf(LIGHT_BLUE2("%15s = |%+05i|\n"), "%+05i", i);
	printf(LIGHT_BLUE2("%15s = |%+05i|\n"), "%+05i", 42);
	printf(LIGHT_BLUE2("%15s = |%0+5i|\n"), "%0+5i", i);
	printf(LIGHT_BLUE2("%15s = |%0+5i|\n"), "%0+5i", 42);
	printf("-------------------------------------\n");
	printf(LIGHT_BLUE2("%15s = |% 05i|\n"), "% 05i", i);
	printf(LIGHT_BLUE2("%15s = |% 05i|\n"), "% 05i", 42);
	printf(LIGHT_BLUE2("%15s = |%0 5i|\n"), "%0 5i", i);
	printf(LIGHT_BLUE2("%15s = |%0 5i|\n"), "%0 5i", 42);
	printf("-------------------------------------\n");
	printf(LIGHT_BLUE2("%15s = |%-+05i|\n"), "%-+05i", i);
	printf(LIGHT_BLUE2("%15s = |%-+05i|\n"), "%-+05i", 42);
	printf(LIGHT_BLUE2("%15s = |%+-05i|\n"), "%+-05i", i);
	printf(LIGHT_BLUE2("%15s = |%+-05i|\n"), "%+-05i", 42);
	printf(LIGHT_BLUE2("%15s = |%0+-5i|\n"), "%0+-5i", i);
	printf(LIGHT_BLUE2("%15s = |%0+-5i|\n"), "%0+-5i", 42);
	printf("-------------------------------------\n");
	printf(LIGHT_BLUE2("%15s = |%- 05i|\n"), "%- 05i", i);
	printf(LIGHT_BLUE2("%15s = |%- 05i|\n"), "%- 05i", 42);
	printf("-------------------------------------\n");
	printf(LIGHT_BLUE2("%15s = |%5.3i|\n"), "%5.3i", i);
	printf(LIGHT_BLUE2("%15s = |%5.4i|\n"), "%5.4i", i);
	printf(LIGHT_BLUE2("%15s = |%5.4i|\n"), "%5.4i", 42);
	printf(LIGHT_BLUE2("%15s = |%+5.4i|\n"), "%+5.4i", 42);
	printf(LIGHT_BLUE2("%15s = |% 5.4i|\n"), "% 5.4i", 42);
	printf(LIGHT_BLUE2("%15s = |%-5.4i|\n"), "%-5.4i", 42);
	printf("-------------------------------------\n");
	printf(LIGHT_BLUE2("%15s = |%#5i|\n"), "%#5i", 42);
	printf("-------------------------------------\n");
	printf(LIGHT_BLUE2("%15s = |%+ 05i|\n"), "%+ 05i", i);
	printf(LIGHT_BLUE2("%15s = |%+ 05i|\n"), "%+ 05i", 42);
	printf(LIGHT_BLUE2("%15s = |% +05i|\n"), "% +05i", i);
	printf(LIGHT_BLUE2("%15s = |% +05i|\n"), "% +05i", 42);
	printf("-------------------------------------\n");
	printf(LIGHT_BLUE2("%15s = |%05.3i|\n"), "%05.3i", i);
	printf(LIGHT_BLUE2("%15s = |%05i|\n"), "%05i", i);
	printf("-------------------------------------\n");
	printf(LIGHT_BLUE2("%15s = |%05.i|\n"), "%05.i", i);
	printf(LIGHT_BLUE2("%15s = |%05.i|\n"), "%05.i", 0);
	printf(LIGHT_BLUE2("%15s = |%-5.3i|\n"), "%-5.3i", i);
	printf(LIGHT_BLUE2("%15s = |%5.8i|\n"), "%5.8i", i);

	/*printf(LIGHT_BLUE2("%15s = |%5i|\n"), "%5i", 1000000);
	printf(LIGHT_BLUE2("%15s = |%-5i|\n"), "%05i", 1000000);
	printf(LIGHT_BLUE2("%15s = |%05i|\n"), "%05i", 1000000);
	printf(LIGHT_BLUE2("%15s = |%-05i|\n"), "%-05i", 1000000);*/

	// printing unsigned integer - specifier u:
	printf(LIGHT_RED("\n\nprinting unsigned integer - specifier u:\n"));
	printf(LIGHT_BLUE2("%15s = |%+5u|\n"), "%+5u", i);
	printf(LIGHT_BLUE2("%15s = |%+5u|\n"), "%+5u", 42);
	printf(LIGHT_BLUE2("%15s = |% 5u|\n"), "% 5u", i);
	printf(LIGHT_BLUE2("%15s = |% 5u|\n"), "% 5u", 42);
	printf(LIGHT_BLUE2("%15s = |%5.3u|\n"), "%5.3u", i);
	printf(LIGHT_BLUE2("%15s = |%5.3u|\n"), "%5.3u", 42);
	/*printf(LIGHT_BLUE2("number %%u = %u\n"), j);
	printf(LIGHT_BLUE2("number %%u negative = %u\n"), i);
	printf(LIGHT_BLUE2("number %%u < 0 = %u\n"), -1);
	printf(LIGHT_BLUE2("number %%u > maximum unsigned integer = %u\n"), 4294967296);
	printf(LIGHT_BLUE2("number %%u > maximum unsigned integer = %u\n"), 4294967297);
	printf(PINK("\n------------------------------- Testing Flags ----------------------------\n\n"));
	printf(LIGHT_BLUE2("%%10u = |%10u|\n"), j);
	printf(LIGHT_BLUE2("width with flag   %%010u = |%010u|\n"), j);
	printf(LIGHT_BLUE2("width with flag   %%-010u = |%-010u|\n"), j);*/

	// printing pointer - specifier p
	/*printf(LIGHT_RED("\n\nprinting pointer - specifier p:\n"));
	printf(LIGHT_BLUE2("char pointer %%p = %p\n"), &c);
	printf(LIGHT_BLUE2("string pointer %%p = %p\n"), &str[0]);
	printf(LIGHT_BLUE2("int pointer %%p = %p\n"), ptr);
	printf(LIGHT_BLUE2("unsigned int pointer %%p = %p\n"), &j);
	printf(PINK("\n------------------------------- Write function ----------------------------\n\n"));
	int **pptr = &ptr;
	write(1, &pptr, 14);
	// printing unsigned hex integer lowercase - specifier x
	printf(LIGHT_RED("\n\nprinting unsigned hex integer lowercase - specifier x:\n"));
	printf(LIGHT_BLUE2("unsigned hex integer %%x = %x\n"), j);
	printf(LIGHT_BLUE2("unsigned hex integer with negative number %%x = %x\n"), i);
	printf(PINK("\n------------------------------- Testing Flags ----------------------------\n\n"));

	// printing unsigned hex integer uppercase - specifier X
	printf(LIGHT_RED("\n\nprinting unsigned hex integer uppercase - specifier X:\n"));
	printf(LIGHT_BLUE2("unsigned hex integer %%X = %X\n"), j);
	printf(LIGHT_BLUE2("unsigned hex integer with negative number %%X = %X\n"), i);
	printf(PINK("\n------------------------------- Testing Flags ----------------------------\n\n"));*/


	/* ************************ Bonus ****************************** */
	//printf(LIGHT_PURPLE("\n************************ BONUS ******************************\n\n"));

	// Flags:

	// Width:
	/* number - minimum number of charcters to be printed. If the value to be printed is shorter than this number,
	the result is padded with blank spaces. The value is not truncated even if the result is larger */

	// The flag '-' left-justifies within the given field width. Right justification is the default
	// The flag 0 left-pads the number with zeroes instead of spaces, where padding is specified

	// Precision
	// .number
	/* When no precision is specified, the default is 1.
	If the period is specified without an explicit value for precision, 0 is assumed */
	/* For integer specifiers d, i, o, u, x and X specifies the minimum number of digits to be written.
	If the value to be written is shorter than this number, the result is padded with leading zeros.
	The value is not truncated even if the result is longer.
	A precision of 0 means that no character is written for the value of 0 */
	/* For s is the maximum number of significant digits to be printed
	(By default all characters are printed until the ending null character is encountered) */
	/* For c it is has no effect */

	// test any combination of the flags '-0.' and minimum field with all conversions

	// flag '+' --> forces to precede the result with a plus or minus sign, even for positive numbers
	// flag (space) --> if no sign is going to be written, a blank space is inserted before the value
	// flag '#' --> used with o, x or X specifiers - the value is preceded with 0, 0x or 0X for values different than zero

	/* ************************ Plus ****************************** */
	// Specifiers
	// specifier n - nothing printed
	// printing decimal floating point - specifier f
	// printing scientific notation using 'e' character - specifier e
	// printing shorter of %e or %f - specifier g
	// printing signed octal - specifier o
	// printing scientific notation using 'E' character - specifier E
	// printing shorter of %E or %f - specifier G

	// Width:
	/* '*' - the width is not specified in the format string, but as an additional integer value argument preceding
	the argument that has to be formatted */

	// Precision
	// .number
	/* When no precision is specified, the default is 1.
	If the period is specified without an explicit value for precision, 0 is assumed */
	/* For e, E and f: is the number of digits to be printed after the decimal point */
	/* For g an G - is the maximum number of significant digits to be printed */
	// '.*' --> the precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted

	// flag '#' --> used with e, E and f specifiers - it forces the written output to contain a decimal point even if no digit would follow
	// flag '#' --> used with g, G - the result is the same as with e or E, but trailing zeros are removed

	// Length
	// h - the argument is interpreted as a short int or unsigned short int (only for i, d, o, u, x, X)
	// hh - ??
	// l - the argument is interpreted as a long int or unsigned long int (only for i, d, o, u, x, X)
	// and as a wide character or wide character string (c and s)
	// ll - ??
	// L - the argument is interpreted as a long double (only for e, E, f, g, G)

	return (0);
}