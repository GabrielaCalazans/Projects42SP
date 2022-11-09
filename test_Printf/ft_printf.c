/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:16:25 by gacalaza          #+#    #+#             */
/*   Updated: 2022/11/09 23:34:53 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		write(fd, &s[count], 1);
		count++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n < 10)
	{
		ft_putchar_fd(n + 48, fd);
		return ;
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
	}		
	ft_putnbr_fd(n % 10, fd);
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

char	*ft_strdup(const char *s)
{
	int		src_size;
	char	*str_dest;

	src_size = ft_strlen(s);
	str_dest = (char *) malloc(sizeof(char) * (src_size + 1));
	ft_strlcpy(str_dest, s, src_size + 1);
	return (str_dest);
}

int	ft_printf(const char *format, ...)
{
	int		count_char;
	va_list	args;
	const char	*str;

	if(!format || *format == '\0')
		return (0);
	str = ft_strdup(format);
	count_char = 0;
	va_start(args, format);
	count_char = //alguma coisa ainda não sei ainda
	va_end(args);
	free((char *) str);
	return (count_char);
}

char	*make_message(const char *format, ...)
{
	int n = 0;
	size_t size = 0;
	char *p = NULL;
	va_list ap;

	/* Determine required size. */
	va_start(ap, fmt);
	n = vsnprintf(p, size, fmt, ap); /*read about vsnprintf*/
	va_end(ap);

	if (n < 0)
		return NULL;

	size = (size_t) n + 1;	/* One extra byte for '\0' */
	p = malloc(size);
	if (p == NULL)
		return NULL;

	va_start(ap, fmt);
	n = vsnprintf(p, size, fmt, ap);
	va_end(ap);

	if (n < 0)
	{
		free(p);
		return NULL;
	}
	return (p);
}
