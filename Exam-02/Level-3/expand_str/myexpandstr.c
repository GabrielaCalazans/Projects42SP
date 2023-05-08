/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myexpandstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:21:36 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/08 18:38:10 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		i = 0;
	char	*str;

	if (argc == 2)
	{
		str = argv[1];

		while (ft_isspace(str[i]) && str[i] != '\0')
			i++;
		while (str[i] != '\0')
		{
			if(ft_isspace(str[i]))
			{
				while (ft_isspace(str[i]) && str[i] != '\0')
					i++;
				if (!(ft_isspace(str[i])) && str[i] != '\0')
				{
					ft_putchar(' ');
					ft_putchar(' ');
					ft_putchar(' ');
				}
			}
			if (str[i] != '\0')
			{
				ft_putchar(str[i]);
				i++;
			}
		}
	}
	ft_putchar('\n');
}
