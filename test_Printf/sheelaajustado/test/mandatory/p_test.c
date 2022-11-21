/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_test.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 04:38:11 by sguilher          #+#    #+#             */
/*   Updated: 2021/08/20 04:45:38 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/test.h"

void	p_test()
{
	int		result1;
	int		result2;
	int		i = 42;
	int		*p = &i;
	char	c = 'a';
	char	*pc = &c;
	char	**ppc = &pc;
	char	*str = "Hello World";
	unsigned int	u = 17923818;

	// printing pointer - specifier p
	printf(LIGHT_RED("\n\nprinting pointer - specifier p:\n"));
	printf(PINK("\nbasic tests:\n"));
	result1 = printf(LIGHT_BLUE2("char pointer %%p = |%p|\n"), pc);
	result2 = ft_printf(LIGHT_BLUE2("char pointer %%p = |%p|\n"), pc);
	check_return(result1, result2);
	result1 = printf(LIGHT_BLUE2("char pointer of pointer %%p = |%p|\n"), ppc);
	result2 = ft_printf(LIGHT_BLUE2("char pointer of pointer %%p = |%p|\n"), ppc);
	check_return(result1, result2);
	result1 = printf(LIGHT_BLUE2("string pointer %%p = |%p|\n"), &str[0]);
	result2 = ft_printf(LIGHT_BLUE2("string pointer %%p = |%p|\n"), &str[0]);
	check_return(result1, result2);
	result1 = printf(LIGHT_BLUE2("int pointer %%p = |%p|\n"), p);
	result2 = ft_printf(LIGHT_BLUE2("int pointer %%p = |%p|\n"), p);
	check_return(result1, result2);
	result1 = printf(LIGHT_BLUE2("unsigned int pointer %%p = |%p|\n"), &u);
	result2 = ft_printf(LIGHT_BLUE2("unsigned int pointer %%p = |%p|\n"), &u);
	check_return(result1, result2);
}