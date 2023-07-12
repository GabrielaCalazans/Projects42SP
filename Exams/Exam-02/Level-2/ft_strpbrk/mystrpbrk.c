/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystrpbrk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:25:31 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/29 16:48:11 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i = 0;
	int	j;

	if (!(s1) || !(s2))
		return (NULL);
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (s2[j] == s1[i])
				return ((char*)s1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

// int	main()
// {
// 	printf("ORIGINAL: %s\n", strpbrk("NHSDJOANJgkjhjkdkdkdabX", "fsdxcsaX"));
// 	printf("    FAKE: %s\n", ft_strpbrk("NHSDJOANJgkjhjkdkdkdabX", "fsdxcsaX"));
// 	printf("ORIGINAL: %s\n", strpbrk("", "fsdxcsaX"));
// 	printf("    FAKE: %s\n", ft_strpbrk("", "fsdxcsaX"));
// 	return (0);
// }