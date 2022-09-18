/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stdlibH.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:47:10 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/18 01:24:53 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char escape[] = {9, 10, 11, 12, 13, 0};
	/* 1 */ printf("%d\n", ft_atoi(" 1"));
	/* 2 */ printf("%d\n", ft_atoi("a1"));
	/* 3 */ printf("%d\n", ft_atoi("--1"));
	/* 4 */ printf("%d\n", ft_atoi("++1"));
	/* 5 */ printf("%d\n", ft_atoi("+1"));
	/* 6 */ printf("%d\n", ft_atoi("-1"));
	/* 7 */ printf("%d\n", ft_atoi("0"));
	/* 8 */ printf("%d\n", ft_atoi("+42lyon"));
	/* 9 */ printf("%d\n", ft_atoi("+101"));
	/* 10 */ printf("%d\n", ft_atoi("2147483647"));
	/* 11 */ printf("%d\n", ft_atoi("-2147483648"));
	/* 12 */ printf("%d\n", ft_atoi("-+42"));
	/* 13 */ printf("%d\n", ft_atoi("+-42"));
	// /* 14 */ printf("%d", ft_atoi("+","42"));
	// /* 15 */ printf("%d", ft_atoi("-","42"));
	// /* 16 */ printf("%d", ft_atoi("1","42"));
	// /* 17 */ printf("%d", ft_atoi("-1","42"));
	
	return (0);
}
