/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:20:47 by gacalaza          #+#    #+#             */
/*   Updated: 2023/06/01 16:54:15 by gacalaza         ###   ########.fr       */
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
				!ft_isspace(argv[i][j]) &&
				!ft_issign(argv[i][j]))
				ft_puterror();
			if (ft_isalpha(argv[i][j]))
				ft_puterror();
			j++;
		}
		i++;
	}
}
