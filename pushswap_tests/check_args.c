/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:20:47 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/25 21:16:44 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	ft_issign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

// ** Checks if the given arguments is valid
int	check_error(char *argv[], int i, int j)
{
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j] != '\0'))
		{
			if (ft_issign(argv[i][j]))
			{
				j++;
				if (!ft_isdigit(argv[i][j]))
					return (0);
			}
			else if (ft_isdigit(argv[i][j]))
			{
				j++;
				if (argv[i][j] == '\0')
					break ;
				if (!ft_isdigit(argv[i][j]) && !ft_isspace(argv[i][j]))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	check_int(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j]) != '\0')
		{
			if (!ft_isdigit(argv[i][j]) &&
				!ft_isspace(argv[i][j]) && \
				!ft_issign(argv[i][j]))
				ft_puterror();
			j++;
		}
		i++;
	}
}

int	check_args(int argc, char *argv[])
{
	if (argc < 2)
		ft_puterror();
	check_int(argv);
	if (!check_error(argv, 1, 0))
		ft_puterror();
	return (1);
}

// Func checks if the stack includes
// duplicate nbr.
int	ft_checkdup(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}