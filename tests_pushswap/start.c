/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:58:26 by gacalaza          #+#    #+#             */
/*   Updated: 2023/06/03 16:55:27 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	find_index(char **str, int nbr, int j)
{
	int	index;
	int	comp;
	int	i;

	index = 0;
	i = j;
	if (!str)
		return (0);
	while (str[i] != NULL)
	{
		comp = ft_atoi_error(str[i]);
		if (comp < nbr)
			index++;
		i++;
	}
	return (index);
}

void	sub_starting(t_stack **a, char **str, int i)
{
	t_stack	*newnode;
	int		index;
	int		nbr;
	int		j;

	j = i;
	nbr = ft_atoi_error(str[i]);
	index = find_index(str, nbr, j);
	*a = createnode(nbr, index);
	while (str[++i] != NULL)
	{
		nbr = ft_atoi_error(str[i]);
		index = find_index(str, nbr, j);
		newnode = createnode(nbr, index);
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
