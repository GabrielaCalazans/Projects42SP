/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 04:52:47 by sguilher          #+#    #+#             */
/*   Updated: 2022/11/21 13:21:16 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "../../../ft_printf.h"
#include "./others/colors.h"
#include <stdio.h>

# define NOT_OK	0
# define OK		1

void	check_return(int n1, int n2);
void	text_tests();
void	percentage_test();
void	empty_var_test();

#endif