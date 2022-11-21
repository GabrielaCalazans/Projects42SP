/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 01:59:01 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/16 01:59:10 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	check_return(int n1, int n2){
	if (n1 == n2)
		printf(GREEN("OK\n"));
	else
	{
		printf(RED("NOT OK\n"));
		printf(RED("printf return = %i\n"), n1);
		printf(RED("ft_printf return = %i\n"), n2);
	}

}