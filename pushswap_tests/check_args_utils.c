/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:50:00 by gacalaza          #+#    #+#             */
/*   Updated: 2023/06/01 16:54:57 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	check_args(int argc, char *argv[])
{
	if (argc < 2)
		exit(1);
	check_int(argv);
	if (!check_error(argv, 1, 0))
		ft_puterror();
	return (1);
}

// Func checks if the stack includes
// duplicate nbr.
int	ft_checkdup(char **str, int i)
{
	int	j;
	int	nbr;
	int	nbr_comp;

	while (str[i] != NULL)
	{
		nbr = ft_atoi_error(str[i]);
		j = i + 1;
		while (str[j] != NULL)
		{
			nbr_comp = ft_atoi_error(str[j]);
			if (nbr == nbr_comp)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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

// Func checks if the stack is sorted.
int	checksorted_len(t_stack *a)
{
	int	i;
	int	len;

	i = a->nbr;
	len = 2;
	while (a)
	{
		if (i > a->nbr)
			return (len - 1);
		i = a->nbr;
		a = a->next;
		len++;
	}
	return (0);
}
