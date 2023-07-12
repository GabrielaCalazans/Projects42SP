/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myreversebits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:11:41 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/03 11:43:54 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int				i = 8;
	unsigned char	result = 0;

	while (i > 0)
	{
		result = result * 2 + octet % 2;
		octet /= 2;
		i--;
	}
	return (result);
}

// void	printBinary(unsigned char c)
// {
// 	int i = 0;

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
// 	char character = '3';
// 	printf("Valor binário do caractere '%c': \n", character);
// 	printBinary(character);

// 	printBinary(reverse_bits(character));

// 	return (0);
// }
