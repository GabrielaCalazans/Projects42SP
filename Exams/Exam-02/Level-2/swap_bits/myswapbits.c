/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myswapbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:02:43 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/03 17:03:38 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	swap_bits(unsigned char octet)
{
	octet = (octet >> 4 & 0xFF) | (octet << 4 & 0xFF);
	return (octet);
}

// void	printbinary(char c)
// {
// 	int	i = 0;

// 	while (i < 8)
// 	{
// 		if ((128 >> i) & c)
// 			printf("1");
// 		else
// 			printf("0");
// 		i++;
// 	}
// 	if (i == 8)
// 		printf("\n");
// }

// int	main()
// {
// 	char	c = 'A';

// 	printf("char %c: ", c);
// 	printbinary(c);
// 	printf("SWAP\n");
// 	printbinary(swap_bits(c));
	
// }