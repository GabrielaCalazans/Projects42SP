/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 01:09:44 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/21 21:18:26 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/test.h"

int	main(){

	printf(LIGHT_PURPLE("\nFT_PRINTF TESTER - BONUS\n\n"));
	printf(LIGHT_RED("Flags: \'-0. #+\' and minimum width\n"));

	d_bonus_test();
	i_bonus_test();
	u_bonus_test();

	return (0);
}
