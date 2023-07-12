/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystrcspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:17:13 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/29 18:25:34 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int		i = 0;
	int		j;

	while(s[i] != '\0')
	{
		j = 0;
		while(reject[j] != '\0')
		{
			if (reject[j] == s[i])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int	main()
{
	printf("ORIGINAL: %ld\n", strcspn(" e-    HADFSDFxSDFSD  +=     AS   ) '#¨¨", "\\\\+++dasdx"));
	printf("   FAKE: %ld\n", ft_strcspn(" e-    HADFSDFxSDFSD  +=     AS   ) '#¨¨", "\\\\+++dasdx"));
	printf("ORIGINAL: %ld\n", strcspn(" e-    HADFSDFxSDFSD1  +=     AS   ) '#¨¨", "123"));
	printf("   FAKE: %ld\n", ft_strcspn(" e-    HADFSDFxSDFSD1  +=     AS   ) '#¨¨", "123"));

}
