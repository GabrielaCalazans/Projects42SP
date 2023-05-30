/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:54:05 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/29 22:08:07 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main()
{
	int	r;

	// r = 9 & 5;
	// 	  a b
	// // 0 0 = 0	-	a & b (a AND b)
	// // 0 1 = 0	-	a & b (a AND b)
	// // 1 0 = 0	-	a & b (a AND b)
	// // 1 1 = 1	-	a & b (a AND b)

	// r = 9 | 5;
	// 	  a b
	// // 0 0 = 0	-	a | b (a OR b)
	// // 0 1 = 1	-	a | b (a OR b)
	// // 1 0 = 1	-	a | b (a OR b)
	// // 1 1 = 1	-	a | b (a OR b)

	// r = 9 ^ 5;
	// 	  a b
	// // 0 0 = 0	-	a ^ b (a XOR b)
	// // 0 1 = 1	-	a ^ b (a XOR b)
	// // 1 0 = 1	-	a ^ b (a XOR b)
	// // 1 1 = 0	-	a ^ b (a XOR b)

	// r = ~5;
	// 	  a b FLIP all the bits
	// // 0 = 1	-	bitwise NOT (one's complement) (unary) 
	// // 1 = 0	-	bitwise NOT (one's complement) (unary) 


	printf("Result: %d\n", r);

	return 0;
}