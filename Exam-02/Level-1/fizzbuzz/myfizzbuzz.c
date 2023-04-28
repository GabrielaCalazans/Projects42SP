/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myfizzbuzz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 00:08:20 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/28 00:34:56 by gacalaza         ###   ########.fr       */
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
		write (1, str, 1);
		++str;
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

int	main()
{
	int	count = 1;

	while (count <= 100)
	{
		if (!(count % 3))
			ft_putstr("fizz\n");
		else if (!(count % 5))
			ft_putstr("buzz\n");
		else if (!(count % 3) && !(count % 5))
			ft_putstr("fizzbuzz\n");
		else
		{
			ft_putnbr(count);
			ft_putchar('\n');
		}
		count++;
	}
	return 0;
}