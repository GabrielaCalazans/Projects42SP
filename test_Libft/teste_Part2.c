/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_Part2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:32:18 by gacalaza          #+#    #+#             */
/*   Updated: 2022/09/23 21:09:48 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char *s = ft_substr("tripouille", 100, 1);
	/* 5 */ printf("%s", !strcmp(s, ""));
	/* 6 */ printf("%s", s, 1);
	free(s);
	
	
	return (0);
}
