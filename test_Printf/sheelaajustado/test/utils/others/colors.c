/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:46:13 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/20 22:51:14 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./colors.h"
#include <stdio.h>

int	main(void){
	printf(PURPLE("PURPLE\n"));
	printf(PURPLE2("PURPLE2\n"));
	printf(LIGHT_PURPLE("LIGHT_PURPLE\n"));
	printf(PINK("PINK\n"));
	printf(LIGHT_RED("LIGHT_RED\n"));
	printf(RED("RED\n"));
	printf(GREEN("GREEN\n"));
	printf(GREEN2("GREEN2\n"));
	printf(GREEN_BOLD("GREEN_BOLD\n"));
	printf(GREEN3("GREEN3\n"));
	printf(BLUE("BLUE\n"));
	printf(LIGHT_BLUE("LIGHT_BLUE\n"));
	printf(LIGHT_BLUE2("LIGHT_BLUE2\n"));
	printf(CYAN("CYAN\n"));
	printf(LIGHT_CYAN("LIGHT_CYAN\n"));
	printf(YELLOW("YELLOW\n"));
	printf(BROWN("BROWN\n"));
	printf(BLACK("BLACK\n"));
	printf(DARK_GREY("DARK_GREY\n"));
	printf(GREY("GREY\n"));
	printf(LIGHT_GREY("LIGHT_GREY\n"));
	printf(WHITE("WHITE\n"));

	return (0);
}
