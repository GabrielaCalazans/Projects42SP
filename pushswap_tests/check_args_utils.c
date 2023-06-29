/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:50:00 by gacalaza          #+#    #+#             */
/*   Updated: 2023/06/28 16:26:40 by gacalaza         ###   ########.fr       */
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
