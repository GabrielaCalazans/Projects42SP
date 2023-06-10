/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letthefunbegin_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:52:26 by gacalaza          #+#    #+#             */
/*   Updated: 2023/06/10 18:53:03 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	push_all_b_to_a(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_size(*b);
	while (len > 0)
	{
		ft_push_a(a, b, 97);
		len--;
	}
}

void	push_half_to_b(t_stack **a, t_stack **b, int size)
{
	while(size > 0)
	{
		ft_push_b(a, b, 98);
		size--;
	}
}


