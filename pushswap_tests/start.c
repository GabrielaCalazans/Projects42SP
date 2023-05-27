/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:58:26 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/26 17:56:33 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	sub_starting(t_stack **a, char **str, int i)
{
	t_stack	*newnode;

	*a = createnode(ft_atoi_error(str[i]));
	while (str[++i] != NULL)
	{
		newnode = createnode(ft_atoi_error(str[i]));
		if (!newnode)
			break ;
		ft_add_back(a, newnode);
	}
}

t_stack	*starting(t_stack **a, int argc, char *argv[])
{
	int		i;
	char	**str;

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
	if (!ft_checkdup(str, i))
		ft_puterror();
	sub_starting(a, str, i);
	if (argc == 2)
		ft_freearray(str);
	return (*a);
}
