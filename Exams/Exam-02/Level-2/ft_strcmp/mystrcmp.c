/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystrcmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:06:49 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/29 12:14:46 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i = 0;

	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '0')
	{
		i++;
	}
	return(s1[i] - s2[i]);
}

// int	main()
// {
// 	printf("ORIGINAL: %d\n", strcmp("GAb", "gab"));
// 	printf("   FAKE: %d\n", ft_strcmp("GAb", "gab"));
// 	printf("ORIGINAL: %d\n", strcmp("gabi", "gabi"));
// 	printf("   FAKE: %d\n", ft_strcmp("gabi", "gabi"));
// 	printf("ORIGINAL: %d\n", strcmp("gabi", "gABbi"));
// 	printf("   FAKE: %d\n", ft_strcmp("gabi", "gABi"));

// }