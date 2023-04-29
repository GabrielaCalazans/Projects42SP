/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mydo_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:33:09 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/29 11:46:47 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int	num1;
	int	num2;

	if (argc == 4)
	{
		num1 = atoi(argv[1]);
		num2 = atoi(argv[3]);
	
		if (argv[2][0] == '-')
			printf("%d", num1 - num2);
		else if (argv[2][0] == '+')
			printf("%d", num1 + num2);
		else if (argv[2][0] == '*')
			printf ("%d", num1 * num2);
		else if (argv[2][0] == '/')
			printf("%d", num1 / num2);
		else if (argv[2][0] == '%')
			printf("%d", num1 % num2);
	}
	printf("\n");
	return(0);
}