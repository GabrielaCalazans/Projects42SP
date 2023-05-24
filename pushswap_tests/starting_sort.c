/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:58:26 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/23 17:54:13 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

t_stack	*starting_a(t_stack **a, int argc, char *argv[])
{
	int		i;
	int		n;
	char	**str;
	t_stack	*newnode;

	i = 1;
	n = ft_atoi_error(argv[i]);
	if (argc == 2)
		str = ft_split(argv[1], 32);
	else
		str = argv;
	*a = createnode(n);
	while (str[++i] != NULL)
	{
		n = ft_atoi_error(str[i]);
		newnode = createnode(n);
		if (!newnode)
			break ;
		ft_add_back(a, newnode);
	}
	if (argc == 2)
		freearray(str);
	return (*a);
}