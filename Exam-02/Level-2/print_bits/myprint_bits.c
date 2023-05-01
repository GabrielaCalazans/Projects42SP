/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myprint_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:50:43 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/01 16:10:00 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	print_bits(unsigned char octet)
{
	int	i = 0;
	
	while (i < 8)
	{
		if ((128 >> i) & octet)
			ft_putchar('1');
		else
			ft_putchar('0');
		i++;
	}
}

// int	main()
// {
// 	print_bits(1);
// 	ft_putchar('\n');
// 	print_bits(2);
// 	ft_putchar('\n');
// 	print_bits(3);
// 	ft_putchar('\n');
// 	print_bits(4);
// 	ft_putchar('\n');
// 	print_bits(5);
// 	ft_putchar('\n');
// 	print_bits(6);
// 	ft_putchar('\n');
// 	return (0);
// }