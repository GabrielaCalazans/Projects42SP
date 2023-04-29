/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystrspn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:08:18 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/29 20:41:26 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	int	i = 0;
	int	result = 0;
	int	check = 0;
	int	j = 0;
	int	m;

	while(accept[i] != '\0')
	{
		if (accept[i] == s[j])
		{
			m = 0;
			while (s[m] != '\0')
			{
				j = 0;
				check = 1;
				while (accept[j] != '\0')
				{
					if (accept[m] == s[j] && check == 1)
					{
						result++;
						check = 0;
					}
					j++;
				}
				m++;
			}
		}
		i++;
	}
	return (result);
}

// int	main()
// {
// 	printf("ORIGINAL: %d\n", strspn("Gabi 1", "imdaskdm1GGGG"));
// 	printf("    FAKE: %d\n", ft_strspn("Gabi 1", "imdask1dmGGGG"));
// 	printf("ORIGINAL: %d\n", strspn("", "imdaskdm1GGGG"));
// 	printf("    FAKE: %d\n", ft_strspn("", "imdask1dmGGGG"));
// 	printf("ORIGINAL: %d\n", strspn("Gabi 1", ""));
// 	printf("    FAKE: %d\n", ft_strspn("Gabi 1", ""));
// 	printf("ORIGINAL: %d\n", strspn("", ""));
// 	printf("    FAKE: %d\n", ft_strspn("", ""));
	
// 	return (0);
// }
