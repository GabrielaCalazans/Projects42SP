/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_no_specifier_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 03:33:33 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/21 20:14:58 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/test.h"

void	flags_no_specifier_test()
{
	int	result1;
	int	result2;

	printf(LIGHT_RED("\n\n%% plus flags but no specifier:\n"));
	printf(LIGHT_BLUE2("%20s"), "printf result:\n");
	result1 = printf("test %-0#.7@queijo\n");
	printf(LIGHT_BLUE2("%20s"), "ft_printf result: ");
	printf("\n");
	result2 = ft_printf("test %-0#.7@queijo\n");
	check_return(result1, result2);
}
