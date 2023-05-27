/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:20:47 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/26 22:02:14 by gacalaza         ###   ########.fr       */
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
			return (1);
		i = a->nbr;
		a = a->next;
	}
	return (0);
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