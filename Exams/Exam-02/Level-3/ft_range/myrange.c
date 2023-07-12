/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myrange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:45:20 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/10 17:25:12 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int	len = 0;
	int	count;
	int	*result;

	int	i = start;
	if(start == 0 && end == 0)
	{
		result = malloc(sizeof(int) * 1);
		result[0] = 0;
	}
	if (start < end)
	{
		while (i++ < end)
			len++;
	}
	if (end < start)
	{
		while (i-- > end)
			len++;
	}
	result = malloc(sizeof(int) * len);
	if (!result)
		return (0);
	i = 0;
	count = start;
	if (start < end)
	{
		while (len >= i)
			result[i++] = count++;
	}
	if (end < start)
	{
		while (len >= i)
			result[i++] = count--;
	}
	return (result);
}

// int	main()
// {
// 	int	*tab = ft_range(0, -3);
// 	int	i = 0;

// 	while (i < 5)
// 	{
// 		printf("%d, ", tab[i]);
// 		if (i == 5)
// 			printf("\n");
// 		i++;
// 	}
// 	free(tab);
// 	return 0;
// }
