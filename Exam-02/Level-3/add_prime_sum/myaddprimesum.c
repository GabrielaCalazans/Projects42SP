/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myaddprimesum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:44:59 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/04 19:54:14 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
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

int	ft_atoi(char *str)
{
	int	i = 0;
	int	result = 0;

	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		result = result * 10;
		result += (str[i] - '0');
		i++;
	}
	return (result);
}

int	ft_isprime(int nbr)
{
	int	i = 3;

	if (nbr < 2 || (nbr % 2 == 0 && nbr > 2))
		return (0);
	while (i < (nbr / 2))
	{
		if (nbr % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int	nbr;
	int	result = 0;
	
	if (argc != 2 || argv[1][0] == '-')
	{
		ft_putchar('0');
		ft_putchar('\n');
	}
	else
	{
		nbr = ft_atoi(argv[1]);

		while (nbr > 0)
		{
			if (ft_isprime(nbr))
				result += nbr;
			nbr--;
		}
		ft_putnbr(result);
		ft_putchar('\n');
	}
	return (0);
}
