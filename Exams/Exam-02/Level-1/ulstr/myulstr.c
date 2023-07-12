/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myulstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:38:50 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/28 17:00:37 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int		i = 0;
	char	*str;

	if (argc == 2)
	{
		str = argv[1];

		while (str[i] != '\0')
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				ft_putchar(str[i] - 32);
			}
			else if (str[i] >= 'A' && str[i] <= 'Z')
			{
				ft_putchar(str[i] + 32);
			}
			else
				ft_putchar(str[i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
