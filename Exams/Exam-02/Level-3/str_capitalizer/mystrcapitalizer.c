/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystrcapitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:15:32 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/12 17:19:53 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	isfirtletter(char c, char befor, int pos)
{
	if (c >= 'a' && c <= 'z' && pos == 0)
		return (1);
	if ((c >= 'a' && c <= 'z') && (befor == 32 || (befor >= 9 && befor <= 13)))
		return (1);
	if ((c >= 'A' && c <= 'Z') && (befor == 32 || (befor >= 9 && befor <= 13)))
		return (1);
	return (0);
}

int	islowerletter(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	isupperletter(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		i = 1;
	int		j;
	char	*str;

	if (argc < 2)
	{
		ft_putchar('\n');
		return (0);
	}
	while (argc > i)
	{
		str = argv[i];
		j = 0;
		while (str[j] != '\0')
		{
			if (isfirtletter(str[j], str[j - 1], j) && islowerletter(str[j]))
				str[j] -= 32;
			else if (!(isfirtletter(str[j], str[j - 1], j)) && isupperletter(str[j]))
				str[j] += 32;
			ft_putchar(str[j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	
}
