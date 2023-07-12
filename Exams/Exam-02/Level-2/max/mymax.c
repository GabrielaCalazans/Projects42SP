/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymax.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:30:02 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/01 15:48:12 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	unsigned int	i = 0;
	int				max = 0;

	if (!tab || len < 1)
		return (0);
	while (len >= i)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

// int	main()
// {
// 	int	tab[] = {12, 5, 4, 70, 8, 50, 80, 100};
// 	int	tab2[] = {};
// 	printf("max:%d\n", max(tab, 4));
// 	printf("max:%d\n", max(tab, 0));
// 	printf("max2:%d\n", max(tab2, 0));
// 	return 0;
// }
