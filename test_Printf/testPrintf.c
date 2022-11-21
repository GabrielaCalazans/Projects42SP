/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testPrintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:36:44 by gacalaza          #+#    #+#             */
/*   Updated: 2022/11/21 13:54:27 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	// int	total;
	// char	testchar;
	// char	*str;
	// int		*ptr;

	// total = sumnum(5, 3, 5, 7, 6, 4);
	// printf("total = %d\n", total);
	// //printf("%d", printf("Gabi"));
	// printstr(2, "one", "two", "tree");

	// printf("max: %d\n", max(2, 4, 8));
	// printf("max: %d\n", max(4, 10, 12, 14, 16));
	
	// printf("percents: %d\n", check_percent("tex", "tex%to2%", "tex%%to3"));
	// print("ddfd", 4, 2, 10.5, 3);
	// print("fffd", -1.4, 2, 10.5, 3);
	
	// testchar = 'D';
	// str = "Gabriela";
	
	// check_percent("as%d%c%asa%s", testchar, str);
	// printf(0);

	char	c;
	int		n;
	unsigned int un;
	int		n2;
	char	*str;
	void	*ptr;
	
	c = 'D';
	un = -1;
	n = -3;
	n2 = 300;
	str = NULL;
	// printf("\nFAKE: %d\n", ft_printf("printa char:%c carai dec:%d. str:%s faz k int:%i un:%u parte.\n", c, n, str, n2, un));
	// printf("\nFAKE: %d\n", ft_printf("1 printa char:%c carai dec:%d. str:%s faz k int:%i un:%u\n", c, n, str, n2, n));
	// printf("\nORIGINAL: %d\n", printf("2 printa char:%c carai dec:%d. str:%s faz k int:%i un:%u\n", c, n, str, n2, n));
	
	//printf("O:%d", printf("o%p\n", str));
	printf(" O:%d\n", printf ("ORIG: MAX_NEG:%x MAX_POS:%x", -2147483648, 2147483647));
	printf(" F:%d\n", ft_printf ("FAKE: MAX_NEG:%x MAX_POS:%x", -2147483648, 2147483647));
	//printf("F:%d", ft_printf("f%p\n", str));
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

int sumnum(int num, ...)
{
	int		sum;
	int		count;
	va_list	argptr;

	count = 0;
	sum = 0;
	va_start(argptr, num);
	while (count < num)
	{
		sum += va_arg(argptr, int);
		count++;
	}
	va_end(argptr);
	return (sum);
}

void	printstr(int num, ...)
{
	int	count;
	char *str;
	va_list	argptr;

	va_start(argptr, num);
	count = 0;
	while (count < num)
	{
		str = va_arg(argptr, char *);
		//printf("str = %d\n", str);
		printf("str = %s\n", str);
		count++;
	}
	va_end(argptr);
}

int	max(int num_args, ...)
{
	va_list	args;
	int		i;
	int		x;
	int		max;

	i = 0;
	va_start(args, num_args);
	max = 0;
	while (i < num_args)
	{
		x = va_arg(args, int);
		if(i == 0)
			max = x;
		else if (x > max)
			max = x;
		i++;
		printf("x: %d\n", x);
		printf("max: %d\n", max);
	}
	va_end(args);
	return (max);
}

void	print(char *placeholders, ...)
{
	int		num_args;
	int		i;
	int		x;
	double	d;
	va_list	args;
	
	num_args = ft_strlen(placeholders);
	va_start(args, placeholders);
	i = 0;
	while (i < num_args)
	{
		if (placeholders[i] == 'd')
		{
			x = va_arg(args, int);
			printf("%d\n", x);
		}
		else if (placeholders[i] == 'f')
		{
			d = va_arg(args, double);
			printf("%f\n", d);
		}
		i++;
	}
	va_end(args);
}

// int main() {
// 	long int decimalNumber,remainder,quotient;
// 	int i=1,j,temp;
// 	char hexadecimalNumber[100];
// 	printf("Enter any decimal number: ");
// 	scanf("%ld",&decimalNumber);
// 	quotient = decimalNumber;
// 	while(quotient!=0) {
// 		temp = quotient % 16;
// 		//To convert integer into character
// 		if( temp < 10)
// 		           temp =temp + 48; else
// 		         temp = temp + 55;
// 		hexadecimalNumber[i++]= temp;
// 		quotient = quotient / 16;
// 	}
// 	printf("Equivalent hexadecimal value of decimal number %d: ",decimalNumber);
// 	for (j = i -1 ;j> 0;j--)
// 	      printf("%c",hexadecimalNumber[j]);
// 	return 0;
// }

// rodar o loop de um ptr até achar um % e contar quantos temos
// int	check_percent(const char *fmt, ...)
// {
// 	va_list	args;
// 	size_t	i;
// 	char	c;
// 	char	*s;
// 	int		percents;
// 	size_t	num_args;

// 	num_args = ft_strlen(fmt);
// 	va_start(args, fmt);
// 	percents = 0;
// 	i = 0;
// 	while (i < num_args)
// 	{
// 		if (fmt[i] == '%')
// 			percents++;
// 		if (fmt[i] == '%' && fmt[i + 1] == 'c')
// 		{
// 			c = va_arg(args, int);
// 			//write(1, &c, 1);
// 			ft_putchar_fd(c, 1);
// 			ft_putchar_fd('\n', 1);
// 			//printf("char:%c\n", c);
// 		}
// 		if (fmt[i] == '%' && fmt[i + 1] == 's')
// 		{
// 			s = va_arg(args, char *);
// 			//write(1, &c, 1);
// 			ft_putstr_fd(s, 1);
// 			ft_putchar_fd('\n', 1);
// 			//printf("char:%c\n", c);
// 		}
// 		i++;
// 	}
// 	va_end(args);
// 	printf("percents:%i\n", percents);
// 	return (percents);
// }

char	*make_message(const char *format, ...)
{
	int n = 0;
	size_t size = 0;
	char *p = NULL;
	va_list ap;

	/* Determine required size. */
	va_start(ap, format);
	n = vsnprintf(p, size, format, ap); /*read about vsnprintf*/
	va_end(ap);

	if (n < 0)
		return NULL;

	size = (size_t) n + 1;	/* One extra byte for '\0' */
	p = malloc(size);
	if (p == NULL)
		return NULL;

	va_start(ap, format);
	n = vsnprintf(p, size, format, ap);
	va_end(ap);

	if (n < 0)
	{
		free(p);
		return NULL;
	}
	return (p);
}
