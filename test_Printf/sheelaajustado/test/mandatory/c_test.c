/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_test.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 04:37:50 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/20 04:39:02 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/test.h"

void	c_test()
{
	int	result1;
	int	result2;

	// printing char - specifier c
	char	c = 'a';
	printf(LIGHT_RED("\nprinting char - specifier c:\n"));
	result1 = printf(LIGHT_BLUE2("char %%c = |%c|\n"), c);
	result2 = ft_printf(LIGHT_BLUE2("char %%c = |%c|\n"), c);
	printf(PINK("\nprinting c = \\0:\n"));
	result1 = printf(LIGHT_BLUE2("char %%c = |%c|\n"), '\0');
	result2 = ft_printf(LIGHT_BLUE2("char %%c = |%c|\n"), '\0');
	check_return(result1, result2);
	printf(PINK("\nprinting more than one element:\n"));
	result1 = printf(LIGHT_BLUE2("element 1: |%c|\nelement 2: |%c|\nelement 3: |%c|\n"), c, 'b', 'c');
	printf("--------------\n");
	result2 = ft_printf(LIGHT_BLUE2("element 1: |%c|\nelement 2: |%c|\nelement 3: |%c|\n"), c, 'b', 'c');
	check_return(result1, result2);
}
