/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:16:25 by gacalaza          #+#    #+#             */
/*   Updated: 2022/11/13 00:46:42 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		{
			i++;
			count_char += print_message(format[i], args);
		}
		else
			count_char += (int)write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count_char);
}

int	print_message(char c, va_list args)
{
	if (c == 'c')
		return (intputchar(va_arg(args, int)));
	else if (c == 's')
		return (intputstr(va_arg(args, char *)));
	else if (c == 'p')
		return (intputnbr(va_arg(args, int)));
	else if (c == 'd' || c == 'i')
		return (intputnbr(va_arg(args, int)));
	else if (c == 'u')
		return (unsputnbr(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (puthex(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (intputnbr(va_arg(args, unsigned int)));
	else if (c == '%')
		return ((int)write(1, "%", 1));
	else
		return ((int)write(1, "%", 1) + (int)write(1, &c, 1));
}

int	intputchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	intputstr(char *s)
{
	int	count;
	int	count_char;

	count = 0;
	count_char = 0;
	if (!s)
		return ((int)write(1, "(null)", 6));
	while (s[count])
	{
		count_char += (int)write(1, &s[count], 1);
		count++;
	}
	return (count_char);
}



int	intputnbr(int n)
{
	static int	count_char = 0;
	
	if (n == -2147483648)
	{
		count_char += intputchar('-');
		count_char += intputchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		count_char += intputchar('-');
		n *= -1;
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

int	unsputnbr(unsigned int n)
{
	static int	count_char = 0;

	if (n < 10)
	{
		count_char += intputchar(n + 48);
		return (count_char);
	}
	else
	{
		unsputnbr(n / 10);
	}		
	unsputnbr(n % 10);
	return (count_char);
}

int	puthex(unsigned long n)
{
	long int	quotient;
	static int	count_char;
	
	quotient = n;
	count_char = 0;
	if(quotient < 10)
	{
		count_char += intputchar(quotient + 48);
		return (count_char);
	}
	else
		puthex(quotient / 16);
	puthex(quotient % 16);
	return (count_char);
}
