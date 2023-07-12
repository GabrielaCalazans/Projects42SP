/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mypgcd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:51:01 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/10 23:06:47 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int hcd(int num1, int num2)
{
	if (num2 == 0)
		return num1;
	else
		return hcd(num2, num1 % num2);
}

int	main(int argc, char *argv[])
{
	int	num1;
	int	num2;
	int	denominator;

	if (argc != 3)
	{
		printf("\n");
		return (0);
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	if ((num1 && num2) > 0)
	{
		denominator = hcd(num1, num2);
		printf("%d\n", denominator);
	}
	return (0);
}
