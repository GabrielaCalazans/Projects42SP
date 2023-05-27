/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letfunbegin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:36:31 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/26 22:43:53 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	sorting_it(t_stack **a, t_stack	**b, int len)
{
	(void)b;
	if (len == 3)
		sort_three(a);
	if (len >= 4 && len <= 8)
		sort_uptosix(a);
}

void	sort_three(t_stack **a)
{
	if (checksorted(*a))
		return ;
	if (ft_min(*a) == (*a)->nbr)
	{
		ft_rev_rotate_ab(a, 97);
		ft_swap_ab(a, 97);
	}
	else if (ft_max(*a) == (*a)->nbr)
	{
		ft_rotate_ab(a, 97);
		if (!checksorted(*a))
			ft_swap_ab(a, 97);
	}
	else
	{
		ft_swap_ab(a, 97);
		sort_three(a);
	}
}

void	sort_uptosix(t_stack **a)
{
	if (!checksorted(*a))
		return ;
	if (ft_max(*a) == (*a)->nbr)
		ft_rotate_ab(a, 97);
	else if (ft_max(*a) == ft_prevlast(*a)->nbr)
		ft_rev_rotate_ab(a, 97);
	else if ((*a)->nbr > (*a)->next->nbr)
		ft_swap_ab(a, 97);
	else
		ft_rotate_ab(a, 97);
	if (checksorted(*a))
		sort_uptosix(a);
}
