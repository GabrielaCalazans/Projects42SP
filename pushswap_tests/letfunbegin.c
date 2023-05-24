/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letfunbegin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:36:31 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/24 17:33:26 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	sortingit(t_stack **a, t_stack	**b)
{
	t_stack	*ptr;
	t_stack	*last;
	int		check;

	check = 1;
	(void)b;
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
			if (ptr->nbr > last->nbr)
			{
				ft_rotate_ab(&*a, 97);
				check = 1;
			}
			else
			{
				ft_swap_ab(&*a, 97);
				check = 1;
			}
		}
		break ;
	}
}
