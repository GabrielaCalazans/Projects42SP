/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myparamsum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:37:27 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/10 19:47:35 by gacalaza         ###   ########.fr       */
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
		ft_putnbr(nbr/ 10);
	ft_putnbr(nbr % 10);
}

int	main(int argc, char *argv[])
{
	(void)argv;
	ft_putnbr(argc - 1);
	ft_putchar('\n');
	return 0;
}