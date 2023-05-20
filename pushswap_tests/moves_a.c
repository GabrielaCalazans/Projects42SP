/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:19:16 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/19 18:32:35 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_swap_a(t_stack *a_head)
{
	t_stack	*ptr;
	t_stack	temp;
	t_stack	*last;

	last = NULL;
	if(a_head == NULL)
		return ;
	while (ptr->next != last)
	{
		if (ptr->nbr > ptr->next->nbr)
		{
			temp = ptr->nbr;
			ptr->nbr = ptr->next->nbr;
			ptr->next->nbr = temp;
			ft_putstr_fd("sa\n");
			break ;
		}
		else
			break ;
	}
}