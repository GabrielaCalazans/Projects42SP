/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystrcspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:17:13 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/29 13:04:49 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int		i = 0;
	int		j;
	size_t	result = 0;

	while(s[i] != '\0')
	{
		j = 0;
		while(reject[j] != '\0')
		{
			if (reject[j] != s[i])
				result++;
			if (reject[j] == s[i])
				return (result);
			j++;
		}
		i++;
	}
	return (result);
}

// int	main()
// {
// 	printf("ORIGINAL: %ld\n",strcspn(" e-    HADFSDFxSDFSD  +=     AS   ) '#¨¨", "\\\\+++dasdx"));
// 	printf("   FAKE: %ld\n",strcspn(" e-    HADFSDFxSDFSD  +=     AS   ) '#¨¨", "\\\\+++dasdx"));
// 	printf("ORIGINAL: %ld\n",strcspn(" e-    HADFSDFxSDFSD1  +=     AS   ) '#¨¨", "123"));
// 	printf("   FAKE: %ld\n",strcspn(" e-    HADFSDFxSDFSD1  +=     AS   ) '#¨¨", "123"));

// }
