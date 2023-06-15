/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:50:00 by gacalaza          #+#    #+#             */
/*   Updated: 2023/06/15 15:43:40 by gacalaza         ###   ########.fr       */
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
int	check_its_sorted_a(t_stack **head)
{
	int		i;
	t_stack	*temp;

	temp = *head;
	i = temp->index;
	while (temp)
	{
		if (i > temp->index)
			return (0);
		i = temp->index;
		temp = temp->next;
	}
	return (1);
}

// Func checks if the stack a is sorted.
int	check_its_sorted_a_len(t_stack **a)
{
	int		i;
	int		len;
	t_stack	*temp;

	temp = *a;
	i = temp->nbr;
	len = 0;
	while (temp)
	{
		len++;
		if (i > temp->nbr)
			return (len);
		i = temp->nbr;
		temp = temp->next;
	}
	return (0);
}

// Func checks if the stack is sorted.
int	check_its_sorted_b_len(t_stack **b)
{
	int		i;
	int		len;
	t_stack	*temp;

	temp = *b;
	i = temp->nbr;
	len = 1;
	while (temp)
	{
		if (i < temp->nbr)
			return (len);
		i = temp->nbr;
		temp = temp->next;
		len++;
	}
	return (0);
}

// Func checks if the stack is sorted.
int	check_its_sorted_b(t_stack **b)
{
	int		i;
	t_stack	*temp;

	temp = *b;
	i = temp->index;
	while (temp)
	{
		if (i < temp->index)
			return (0);
		i = temp->index;
		temp = temp->next;
	}
	return (1);
}