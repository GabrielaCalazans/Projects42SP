/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myispowerof2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:28:26 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/30 12:54:15 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n > 1 && n != 0)
	{
		if (n % 2 != 0)
			return (0);
		n = n / 2;
	}
	return (1);
}

// int	main()
// {
// 	printf("%d\n", is_power_of_2(3));
// 	printf("%d\n", is_power_of_2(128));
// 	printf("MATH:%f\n", pow(2, 10));
// }