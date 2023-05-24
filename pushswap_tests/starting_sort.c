/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:58:26 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/24 16:45:13 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

t_stack	*starting_a(t_stack **a, int argc, char *argv[])
{
	int		i;
	char	**str;
	t_stack	*newnode;

	if (argc == 2)
	{
		i = 0;
		str = ft_split(argv[1], 32);
	}
	else
	{
		i = 1;
		str = argv;
	}
	*a = createnode(ft_atoi_error(str[i]));
	while (str[++i] != NULL)
	{
		newnode = createnode(ft_atoi_error(str[i]));
		if (!newnode)
			break ;
		ft_add_back(a, newnode);
	}
	if (argc == 2)
		freearray(str);
	return (*a);
}
