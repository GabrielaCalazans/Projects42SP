/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myinter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:46:55 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/30 12:25:22 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	checkrepet(char *str, char c, int len)
{
	int	i = 0;

	while (i < len && str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
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

int	main(int argc, char *argv[])
{
	int		i = 0;
	int		lenstatic;
	char	*str1;
	char	*str2;

	if (argc == 3)
	{
		str1 = argv[1];
		str2 = argv[2];
		lenstatic = ft_strlen(str2);

		while (str1[i] != '\0')
		{
			if ((!(checkrepet(str1, str1[i], i))) && checkrepet(str2, str1[i], lenstatic))
				ft_putchar(str1[i]);
			i++;
		}
	}
	ft_putchar('\n');
}
