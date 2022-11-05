/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testPrintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:36:44 by gacalaza          #+#    #+#             */
/*   Updated: 2022/11/05 00:54:46 by gacalaza         ###   ########.fr       */
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

int	main()
{
	// int	total;

	// total = sumnum(5, 3, 5, 7, 6, 4);
	// printf("total = %d\n", total);
	// //printf("%d", printf("Gabi"));
	// printstr(2, "one", "two", "tree");

	printf("max: %d\n", max(2, 4, 8));
	printf("max: %d\n", max(4, 10, 12, 14, 16));

	return (0);
}
