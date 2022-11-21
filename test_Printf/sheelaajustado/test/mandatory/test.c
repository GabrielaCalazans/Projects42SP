/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:40:46 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/21 04:11:04 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/test.h"

int	main(void){
	/* ************************* Printf ******************************** */
	// int	printf(const char *format, ...)

	printf(LIGHT_PURPLE("\nFT_PRINTF TESTER\n\n"));

	text_tests();

	printf(LIGHT_RED("Specifiers: c, s, d, i, u, p, and x\n"));

	empty_var_test();
	percentage_test();
	c_test();
	s_test();
	di_test();
	u_test();
	lowerhex_test();
	upperhex_test();
	p_test();

	return (0);
}