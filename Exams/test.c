/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:49:26 by gacalaza          #+#    #+#             */
/*   Updated: 2024/01/26 13:20:49 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#include <limits.h>
#include <stdio.h>

// malloc, free, write, va_start, va_arg, va_copy and va_end

static void	ft_putchar(char c, int *len)
{
	*len += write(1, &c, 1);
}

static void	ft_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		str = "(null)";
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i], len);
		i++;
	}
}

static void	ft_putnbr(int nbr, int *len)
{
	if (nbr == -2147483648)
	{
		ft_putstr("-2", len);
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		ft_putstr("-", len);
		nbr *= -1;
	}
	if (nbr >= 0 && nbr < 10)
	{
		ft_putchar(nbr + '0', len);
		return ;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10, len);
	ft_putnbr(nbr % 10, len);
}

static void	ft_puthex(unsigned int nbr, int *len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nbr >= 16)
		ft_puthex(nbr / 16, len);
	ft_putchar(hex[nbr % 16], len);
}

int	ft_printf(const char *format, ...)
{
	int		len = 0;
	int		i = 0;
	va_list	arg;

	if (!format)
		return (-1);
	va_start(arg, format);
	while (format[i] != '\0')
	{
		if ((format[i] == '%' && format[i + 1] == 's') || (format[i] == '%' && format[i + 1] == 'd') || (format[i] == '%' && format[i + 1] == 'x'))
		{
			i++;
			if (format[i] == 's')
				ft_putstr(va_arg(arg, char *), &len);
			else if (format[i] == 'd')
				ft_putnbr(va_arg(arg, int), &len);
			else if (format[i] == 'x')
				ft_puthex(va_arg(arg, unsigned int), &len);
		}
		else
			ft_putchar(format[i], &len);
		i++;

	}
	return (va_end(arg), len);
}

int	main(void)
{
	int	nbr = 342;
	int	len_original;
	int	len_fake;

	// ft_putstr("GABI\n");
	// ft_putstr("-");
	// ft_putnbr(-42341);
	// ft_putchar('\n');
	// ft_putchar('\n');
	// ft_puthex(nbr);

	len_original = printf("ORIGITAL: %d MIN: %s %x\n", INT_MAX, "Gabriela", nbr);
	len_fake = ft_printf("ORIGITAL: %d MIN: %s %x\n", INT_MAX, "Gabriela", nbr);

	printf("fake: %d ORIGINAL: %d", len_fake, len_original);
}
