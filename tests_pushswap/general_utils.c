/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:27:45 by gacalaza          #+#    #+#             */
/*   Updated: 2023/08/02 15:16:20 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ft_freearray(char **array)
{
	int		i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}

// ** Outputs the string msg to the standard output followed by an exit of the
// ** program with a custom return value.

void	ft_puterror(void)
{
	ft_putendl_fd("Error", 1);
	exit(1);
}

int	ft_atoi_error(const char *nptr)
{
	long	result;
	int		count;
	int		sign;

	count = 0;
	result = 0;
	sign = 1;
	while ((nptr[count] >= 9 && nptr[count] <= 13) || nptr[count] == 32)
		count++;
	if (nptr[count] == '-' || nptr[count] == '+')
	{
		if (nptr[count] == '-')
			sign = -1;
		count++;
	}
	while (nptr[count] != '\0' && ft_isdigit(nptr[count]))
	{
		result = (result * 10) + (nptr[count] - '0');
		count++;
	}
	if ((sign * result) > 2147483647 || (sign * result) < -2147483648)
		ft_puterror();
	return (result * sign);
}

void	push_all_b_to_a(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_size(*b);
	while (len > 0)
	{
		ft_push_a(a, b, 97);
		len--;
	}
}

// ** Display a usage message on how to run and use push_swap

// static void	fdf_usage(void)
// {
// 	ft_putstr_fd("Push_swap Usage:\n\t", 1);
// 	ft_putstr_fd("Pleae input a random amount of negative and/or ", 1);
// 	ft_putstr_fd("positive numbers which cannot be duplicated.:\n\t", 1);
// 	ft_putstr_fd("Then, run ex.: ./push_swap 1 2 3 4\n\t", 1);
// 	ft_putstr_fd("Or, ex.: ./push_swap \"1 2 3 4\"\n\t", 1);
// }
