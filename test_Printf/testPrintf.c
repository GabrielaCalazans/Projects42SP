/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testPrintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:36:44 by gacalaza          #+#    #+#             */
/*   Updated: 2022/11/06 04:04:14 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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

int	check_percent(const char *fmt, ...)
{
	va_list	args;
	int		i;
	char	*str;
	int		percents;

	i = 0;
	va_start(args, fmt);
	percents = 0;
	str = va_arg(args, char *);
	printf("str ANTES loop: %s\n", str);
	while (str)
	{
		str = va_arg(args, char *);
		printf("str args loop: %s\n", str);
		// if (str[i] == '%')
		// 	percents++;
		// else if(str[i + 1] == '\0' && str[i])
		// {
		// 	str = va_arg(args, char *);
		// 	printf("str args loop: %s\n", str);
		// }
		// i++;
		// printf("str depois loop: %s\n", str);
	}
	va_end(args);
	return (percents);
}
// rodar o loop de um ptr até achar um % e contar quantos temos

int	main()
{
	// int	total;

	// total = sumnum(5, 3, 5, 7, 6, 4);
	// printf("total = %d\n", total);
	// //printf("%d", printf("Gabi"));
	// printstr(2, "one", "two", "tree");

	// printf("max: %d\n", max(2, 4, 8));
	// printf("max: %d\n", max(4, 10, 12, 14, 16));
	
	printf("percents: %d\n", check_percent("tex", "tex%to2%", "tex%%to3"));

	return (0);
}
