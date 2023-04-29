/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystrdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:06:53 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/29 13:22:16 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len = ft_strlen(src);
	int		i = 0;
	char	*newstr;
	
	if (!src)
		return (NULL);
	newstr = malloc(len + 1);
	if (!newstr)
		return (NULL);
	while (src[i] != '\0')
	{
		newstr[i] = src[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

// int	main()
// {
// 	char *original = strdup("GABRIELA");
// 	char *fake = ft_strdup("GaBrIeLa");

// 	printf("ORIGINAL: %s\n", original);
// 	printf("   FAKE: %s\n", fake);
// 	free (original);
// 	free (fake);
	
// }
