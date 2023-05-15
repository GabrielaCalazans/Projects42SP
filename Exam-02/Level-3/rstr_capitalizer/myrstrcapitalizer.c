/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myrstrcapitalizer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 01:00:44 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/12 12:10:26 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_strj(char *str)
{
	int	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	islastletter(char c, char after)
{
	if (c >= 'a' && c <= 'z' && after == '\0')
		return (1);
	if (c >= 'A' && c <= 'Z' && after == '\0')
		return (1);
	if (c >= 'A' && c <= 'Z' && (after == 32 || (after >= 9 && after <= 13)))
		return (1);
	if (c >= 'a' && c <= 'z' && (after == 32 || (after >= 9 && after <= 13)))
		return (1);
	return (0);
}

int	isupletter(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	islowletter(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		i = 1;
	int		j;
	int		len = 0;
	char	*str;

	if (argc < 2)
		ft_putchar('\n');

	while (argc > i)
	{
		str = argv[i];
		len = ft_strj(str);
		j = 0;
		while (len > j)
		{
			if (islastletter(str[j], str[j+1]) && islowletter(str[j]))
				str[j] -= 32;
			else if (!(islastletter(str[j], str[j+1])) && isupletter(str[j]))
				str[j] += 32;
			ft_putchar(str[j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}
