/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myreversebits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:11:41 by gacalaza          #+#    #+#             */
/*   Updated: 2023/07/27 18:19:43 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

unsigned char	reverse_bits(unsigned char octet)
{
	int				i = 8;
	unsigned char	result = 0;

	while (i > 0)
	{
		printf("func result: %c':", result);
		printBinary(result);
		result = result * 2 + octet % 2;
		printf("func octet: %c':", octet);
		printBinary(octet);
		printf("\n");
		octet /= 2;
		i--;
	}
	return (result);
}

unsigned char	reverse_bits_bitwise(unsigned char octet)
{
	int				i = 7;
	unsigned char	result = 0;

	printf("func-bitwise RESULT: %c\n", result);
	printf("func-bitwise OCTET: %c\n", octet);
	while (i >= 0)
	{
		printf("func-bitwise RESULT:");
		printBinary(result);

		result = result | (octet & 1) << i;

		printf("func-bitwise OCTET:");
		printBinary(octet);
		printf("\n");

		octet = octet >> 1;
		i--;
	}
	return (result);
}

int	main()
{
	char character = 'A';
	printf("Valor binário do caractere ANTES-MAIN: %c':", character);
	printBinary(character);
	printf("Valor binário do caractere DEPOIS DA FUNC REV-MAIN");
	printBinary(reverse_bits(character));
	printf("\n");
	printf("Valor binário do caractere DEPOIS DA FUNC REV_bitwise-MAIN");
	printBinary(reverse_bits_bitwise(character));

	return (0);
}
