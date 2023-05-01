/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myreversebits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:11:41 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/01 20:05:09 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	// int				i = 7;
	// unsigned char	temp = 0;
	// unsigned char	temp2 = 0;

	octet = (octet & 0xF0) >> 4 | (octet & 0xF0) << 4;
	octet = (octet & 0xCC) >> 2 | (octet & 0xCC) << 2;
	octet = (octet & 0xAA) >> 1 | (octet & 0xAA) << 1;

	return (octet);
	// while (i >= 0)
	// {
	// 	if((128 << i) | octet)
	// 		temp = 128 << i;
	// 	i--;
	// }
	// i = 0;
	// 	while (i < 7)
	// {
	// 	if((128 >> i) | octet)
	// 		temp2 = 128 >> i | temp;
	// 	i++;
	// }
	// return (temp2);
}

void	printBinary(unsigned char c)
{
	int i = 0;

	while (i < 8)
	{
		if ((128 >> i) & c)
			printf("1");
		else
			printf("0");
		i++;
	}
	if (i == 8)
		printf("\n");
}


int	main()
{
	char character = '3';
	printf("Valor binário do caractere '%c': \n", character);
	printBinary(character);

	printBinary(reverse_bits(character));

	return (0);
}
