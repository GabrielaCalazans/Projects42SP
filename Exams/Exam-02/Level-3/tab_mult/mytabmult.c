/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mytabmult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:22:14 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/12 17:57:24 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnbr(int nbr)
{
	if (nbr < 10)
	{
		ft_putchar(nbr + '0');
		return ;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putnbr(nbr % 10);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_itoa(char *str)
{
	int	i = 0;
	int	result = 0;
	
	if(!str)
		return (0);
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}

int	main(int argc, char *argv[])
{
	int	nbr;
	int	result = 0;
	int	i = 1;

	if (argc != 2)
		ft_putchar('\n');
	if (argc == 2)
	{
		nbr = ft_itoa(argv[1]);
		while (i < 10)
		{
			ft_putnbr(i);
			ft_putstr(" x ");
			ft_putnbr(nbr);
			ft_putstr(" = ");
			result = nbr * i;
			ft_putnbr(result);
			i++;
			ft_putchar('\n');
		}
	}
	return (0);
}