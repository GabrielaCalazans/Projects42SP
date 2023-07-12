/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystrrev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:51:03 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/29 18:06:01 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return(i);
}

char	*ft_strrev(char *str)
{
	int		i = 0;
	int		len = ft_strlen(str) - 1;
	char	tempc;

	if (!str)
		return (NULL);
	while ((len + 1) / 2  > i)
	{
		tempc = str[i];
		str[i] = str[len - i];
		str[len - i] = tempc;
		i++;
	}
	return (str);
}

// int	main()
// {
// 	char s[] = "HELL Gabriela";
// 	ft_strrev(s);
// 	printf("%s\n", s);
// 	return (0);
// }
