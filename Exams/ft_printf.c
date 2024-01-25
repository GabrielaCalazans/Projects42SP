/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:33:11 by gacalaza          #+#    #+#             */
/*   Updated: 2024/01/25 18:06:32 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

static void	ft_putchar (char c, int *len)
{
	*len += write(1, &c, 1);
}

static void	ft_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
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
	if (nbr < 10)
	{
		ft_putchar(nbr + '0', len);
		return ;
	}
	if (nbr >= 16)
		ft_puthex(nbr / 16, len);
	ft_putchar(hex [nbr % 16], len);

}

int	ft_printf(const char *format, ...)
{
	int	i = 0;
	int	len = 0;
	va_list	ptr;
	va_start(ptr, format);
	
	if (!format)
		return (-1);
	while (format[i])
	{
		if ((format[i] == '%' && format[i + 1] == 's') || (format[i] == '%' && format[i + 1] == 'd') || (format[i] == '%' && format[i + 1] == 'x'))
		{
			i++;
			if (format[i] == 's')
				ft_putstr(va_arg(ptr, char *), &len);
			else if (format[i] == 'd')
				ft_putnbr(va_arg(ptr, int), &len);
			else if (format[i] == 'x')
				ft_puthex(va_arg(ptr, int), &len);
			else if (format[i] == '%')
				ft_putstr(va_arg(ptr, char *), &len);
		}
		else
			ft_putchar(format[i], &len);
		i++;
	}
	printf("LEN: %i\n", len);
	return (va_end(ptr), len);
}


int	main (void)
{
	// ft_putstr("Gabriela\n");
	// // printf("%d\n", INT_MIN);
	// ft_putnbr(-2147483648);
	// ft_putchar('\n', );
	// ft_puthex(4588);
	// ft_putchar('\n');
	// ft_putchar('\n');

	printf("ORIGINAL: %x\n", 4588);

	ft_printf("coisas\n");
	int	len = printf("coisas\n");
	printf("LEN ORIGINAL: %i", len);
}