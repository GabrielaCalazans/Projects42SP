/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_Part2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:32:18 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/27 18:46:18 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	// ****************** TESTE SUBSTR ***********************
	// char *s = ft_substr("tripouille", 100, 1);
	// /* 5 */ printf("%s", !strcmp(s, ""));
	// /* 6 */ printf("%s", s, 1);
	// free(s);

	// ****************** TESTE ATOI ***********************
	// char * s = ft_itoa(2147483647);
	// /* 1 */ printf("[%s] ", s);
	// /* 2 */ printf("TEM QUE SER 10: [%zu]\n", ft_strlen(s));
	// free(s);

	// s = ft_itoa(-2147483648);
	// /* 3 */ printf("[%s] ", s);
	// /* 4 */ printf("TEM QUE SER 11: [%zu]\n", ft_strlen(s));
	// free(s);

	// s = ft_itoa(0);
	// /* 5 */ printf("[%s] ", s);
	// /* 6 */ printf("TEM QUE SER 1: [%zu]\n", ft_strlen(s));
	// free(s);

	// s = ft_itoa(1);
	// /* 7 */ printf("[%s] ", s);
	// /* 8 */ printf("TEM QUE SER 1: [%zu]\n", ft_strlen(s));
	// free(s);

	// s = ft_itoa(-1);
	// /* 9 */ printf("[%s] ", s);
	// /* 10 */ printf("TEM QUE SER 2: [%zu]\n", ft_strlen(s));
	// free(s);

	// s = ft_itoa(42);
	// /* 11 */ printf("[%s] ", s);
	// /* 12 */ printf("TEM QUE SER 2: [%zu]\n", ft_strlen(s));
	// free(s);
	
	// ****************** TESTE STRTRIM ***********************
	// char * s = ft_strtrim("Gabriel", "l");
	// /* 1 */ printf("%s", s);
	// /* 2 */ printf(s, strlen("tripouille") + 1); free(s);

	// s = ft_strtrim("tripouille   xxx", " x");
	// /* 3 */ printf(!strcmp(s, "tripouille"));
	// /* 4 */ printf(s, strlen("tripouille") + 1); free(s);

	// s = ft_strtrim("   xxxtripouille   xxx", " x");
	// /* 5 */ printf(!strcmp(s, "tripouille"));
	// /* 6 */ printf(s, strlen("tripouille") + 1); free(s);

	// s = ft_strtrim("   xxx   xxx", " x");
	// /* 7 */ printf(!strcmp(s, ""));
	// /* 8 */ printf(s, 1); free(s);

	// s = ft_strtrim("", "123");
	// /* 9 */ printf(!strcmp(s, ""));
	// /* 10 */ printf(s, 1); free(s);

	// s = ft_strtrim("123", "");
	// /* 11 */ printf(!strcmp(s, "123"));
	// /* 12 */ printf(s, 4); free(s);

	// s = ft_strtrim("", "");
	// /* 13 */ printf(!strcmp(s, ""));
	// /* 14 */ printf(s, 1); free(s);

	// s = ft_strtrim("abcdba", "acb");
	// /* opsec-infosec 15 */ printf(!strcmp(s, "d"));
	// /* opsec-infosec 16 */ printf(s, 2); free(s);

	
	
	return (0);
}
