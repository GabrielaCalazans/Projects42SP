/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:16:25 by gacalaza          #+#    #+#             */
/*   Updated: 2022/11/11 00:25:28 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	int		count_char;
	int		i;
	va_list	args;

	if(!format)
		return (-1);
	va_start(args, format);
	count_char = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			count_char += print_message(format[i + i], args);
		else
			count_char = write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count_char);
}

int	print_message(char c, va_list args)
{
	if (c == 'c')
	{
		return (intputchar(va_arg(args, int)));
		printf("aqui1");
	}
	if (c == 's')
		return (intputstr(va_arg(args, char *)));
	else
		return ((int)write(1, "%", 1) + (int)write(1, &c, 1));
}



int	intputstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return ((int)write(1, "(null)", 6));
	while (s[count] != '\0')
	{
		write(1, &s[count], 1);
		count++;
	}
	return (count);
}

int	intputnbr(int n)
{
	int	count_char;
	
	count_char = 0;
	if (n == -2147483648)
	{
		count_char += intputchar('-');
		count_char += intputchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		count_char += intputchar('-');
		n = n * -1;
	}
	if (n < 10)
	{
		count_char += intputchar(n + 48);
		return (count_char);
	}
	else
	{
		intputnbr(n / 10);
	}		
	intputnbr(n % 10);
	return (count_char);
}

int	intstrlen(const char *str)
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


