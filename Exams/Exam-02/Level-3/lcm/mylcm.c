/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylcm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:01:53 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/10 19:28:41 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	max;

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		max = a;
	else
		max = b;
	while (1)
	{
		if ((max % a == 0) && max % b == 0)
			return (max);
		max++;
	}
}

// int	main()
// {
// 	int	numb1 = 72;
// 	int	numb2 = 120;
// 	int	max = lcm(numb1, numb2);
	
// 	printf("The LCM of %d and %d is %d.\n", numb1, numb2, max);

// 	return (0);
// }
