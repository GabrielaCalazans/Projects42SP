/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:33:19 by coder             #+#    #+#             */
/*   Updated: 2022/09/06 19:42:45 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<ctype.h>
#include"libft.h"

int	main(void)
{
	char	text[] = "GabCal%*+@as\\t351989	\bMeu =-seu.\n";
	char	var;
	
	/*var = '1';
	printf("\nResult when 1 is passed to ft_tolower: %c", ft_tolower(var));
	var = 'A';
	printf("\nResult when A is passed to ft_tolower: %c", ft_tolower(var));
	var = '+';
	printf("\nResult when + is passed to ft_tolower: %c", ft_tolower(var));
	var = 'a';
	printf("\nResult when a is passed to ft_tolower: %c\n", ft_tolower(var));

	var = '\n';
	printf("\nResult when barra n is passed to ft_toupper: %c", ft_toupper(var));
	var = '\b';
	printf("\nResult when barra b is passed to ft_toupper: %c", ft_toupper(var));
	var = '+';
	printf("\nResult when + is passed to ft_toupper: %c", ft_toupper(var));
	var = 'a';
	printf("\nResult when a is passed to ft_toupper: %c\n", ft_toupper(var));*/
	
	printf("%s", ft_strdup("Gabriela\n"));
	return (0);
}
