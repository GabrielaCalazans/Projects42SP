/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystrcpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 00:37:44 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/28 01:00:43 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	len = 0;

	if (!str)
		return (0);
	while(str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strcpy(char *s1, char *s2)
{
	int	i = 0;

	int	lens1 = ft_strlen(s1);
	int	lens2 = ft_strlen(s2);
	if (!s2 || !s1)
		return (s1);
	if (lens1 < lens2)
	{
		while(s2[i] != '\0')
		{
			s1[i] = s2[i];
			i++;
		}
		s1[i] = '\0';
	}
	return (s1);
}

int	main()
{
	char	str[5];
	char	str1[5];
	
	printf("ORIGINAL: %s\n", strcpy(str, "test"));
	// printf("ORIGINAL: %s\n", strcpy("    ", "test"));
	printf("ORIGINAL: %s\n", ft_strcpy(str1, "test"));
	// printf("ORIGINAL: %s\n", ft_strcpy("", "test"));
}