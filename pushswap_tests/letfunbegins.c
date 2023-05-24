/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letfunbegins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:36:31 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/23 20:26:16 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	sortingit(t_stack **a, t_stack	**b)
{
	t_stack	*ptr;
	int		check;
	
	check = 1;
	while (check)
	{
		check = 0;
		ptr = *a;
		while (ptr->next != NULL)
		{
			if (ptr->nbr > ptr->next->nbr)
			{
				if (ptr->nbr > ft_last(ptr))
					ft_rotate_ab(ptr, 97);
				else
					ft_swap_ab(ptr, 97);
				check = 1;
				break ;
			}
			break ;
		}

	}
}