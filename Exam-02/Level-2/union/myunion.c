/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myunion.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:05:36 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/03 17:55:44 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i = 0;

	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	checkchar(char *str, char c, int i)
{
	int	j = 0;

	while (j < i)
	{
		if (str[j] == c)
			return (0);
		j++;
	}
	return (1);
}

int	main (int argc, char *argv[])
{
	char	*str1;
	char	*str2;
	int		i = 0;
	int		len1;

	if (argc == 3)
	{
		str1 = argv[1];
		str2 = argv[2];
		len1 = ft_strlen(str1) - 1;

		while (str1[i] != '\0')
		{
			if (checkchar(str1, str1[i], i))
				ft_putchar(str1[i]);
			i++;
		}
		i = 0;
		while (str2[i] != '\0')
		{
			if (checkchar(str1, str2[i], len1) && checkchar(str2, str2[i], i))
				ft_putchar(str2[i]);
			i++;
		}
	}
	ft_putchar('\n');
}
