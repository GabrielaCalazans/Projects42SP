/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percentage_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 01:30:39 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/21 02:04:02 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/test.h"

void	percentage_test()
{
	int	result1;
	int	result2;

	printf(PINK("\n\nTest 3: Specifier %%:\n"));
	printf(LIGHT_BLUE2("%20s"), "printf result:\n");
	result1 = printf("100%%\n");
	printf(LIGHT_BLUE2("%20s"), "ft_printf result: ");
	printf("\n");
	result2 = ft_printf("100%%\n");
	check_return(result1, result2);
	/* Tests with % that give error in printf when compiled with the flags -Wall -Wextra -Werror*/
	result1 = printf("%\\this is_a test\n");
	result2 = ft_printf("%\\this is_a test\n");
	check_return(result1, result2);
	result1 = printf("bbbb%kanother test\n");
	result2 = ft_printf("bbbb%kanother test\n");
	check_return(result1, result2);
}
