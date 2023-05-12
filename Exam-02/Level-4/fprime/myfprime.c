/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myfprime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:02:19 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/12 20:01:05 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	nbr;
	int	i = 2;

	if (argc == 2)
	{
		nbr = atoi(argv[1]);
		if (nbr == 1)
			printf("1");
		while (i <= nbr)
		{
			if (nbr % i == 0)
			{
				printf("%d", i);
				if (nbr == i)
					break ;
				printf("*");
				nbr /= i;
				i = 2;
			}
			i++;
		}
	}
	printf("\n");
	return (0);
}
