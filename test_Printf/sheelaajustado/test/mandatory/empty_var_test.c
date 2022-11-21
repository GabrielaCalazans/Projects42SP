/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_var_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 01:36:35 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/20 04:09:58 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/test.h"

void	empty_var_test()
{
	int	result1;
	int	result2;

	/* the next texts give error in printf when compiled with the flags -Wall -Wextra -Werror*/
	printf(PINK("\nwhen we do not indicate the variable, it prints anything from a place in the memory according with the variable type:\n"));
	printf(LIGHT_BLUE2("%%c: %c\n"));
	ft_printf(LIGHT_BLUE2("%%c: %c\n"));
	printf(LIGHT_BLUE2("%%i: %i\n"));
	ft_printf(LIGHT_BLUE2("%%i: %i\n"));
	printf(LIGHT_BLUE2("%%x: %x\n"));
	ft_printf(LIGHT_BLUE2("%%x: %x\n"));
}