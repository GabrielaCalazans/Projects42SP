/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letfunbegin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:36:31 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/25 18:17:22 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	sorting_it(t_stack **a, t_stack	**b, int len)
{
	if (len == 3)
		sort_three(a);
	if (len == 6)
		sort_six(a, b);
}

void	sort_six(t_stack **a, t_stack	**b)
{
	t_stack	*ptr;
	t_stack	*last;
	int		check;

	// (void)b;
	check = 1;
	ptr = NULL;
	last = NULL;
	while (check)
	{
		check = 0;
		last = ft_last(*a);
		ptr = *a;
		if (ptr->next == NULL)
			return ;
		if (ptr->nbr > ptr->next->nbr)
		{
			// if (ptr->nbr > last->nbr)
			// {
			// 	ft_rev_rotate_ab(&*a, 97);
			// 	check = 1;
			// }
			// else
			// {
				ft_swap_ab(&*a, 97);
				check = 1;
			// }
		}
		if (ptr->nbr > last->nbr)
		{
			ft_rev_rotate_ab(&*a, 97);
			check = 1;
		}
		if (ptr->nbr < last->nbr)
		{
			ft_rev_rotate_ab(&*a, 97);
			check = 1;
		}
		else
		{
			ft_push_b(&*a, &*b, 98);
			check = 1;
		}
		if (check == 0)
			break ;
	}
}

void	sort_three(t_stack **a)
{
	if (ft_min(*a) == (*a)->nbr)
	{
		ft_rev_rotate_ab(a, 97);
		ft_swap_ab(a, 97);
	}
	else if (ft_max(*a) == (*stack_a)->nbr)
	{
		ft_rotate_ab(a, 97);
		if (!ft_checksorted(*a))
			ft_sa(a, 97);
	}
}

// Func checks if the stack is sorted.
int	checksorted(t_stack *a)
{
	int	i;

	i = a->nbr;
	while (a)
	{
		if (i > a->nbr)
			return (0);
		i = a->nbr;
		a = a->next;
	}
	return (1);
}
