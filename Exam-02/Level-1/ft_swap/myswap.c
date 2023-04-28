/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myswap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 01:10:15 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/28 01:39:00 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	// int	*temp;

	// temp = a;
	// *a = *b;
	// *b = *temp;
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

int	main()
{
	int	a = 10;
	int	b = 200;
	int	*c;
	int	*d;

	c = &a;
	d = &b;
	printf("ANTES c:%d\n", *c);
	ft_swap(c, d);
	printf("DEPOIS c:%d\n", *c);
}