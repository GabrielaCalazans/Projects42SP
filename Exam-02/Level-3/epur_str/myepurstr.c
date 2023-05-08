/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myepurstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:59:00 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/08 18:16:05 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	checkspace(char c)
{
	if ((c >= 8 && c <= 13) || c == 32)
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

		while(checkspace(str[i]) && str[i] != '\0')
			i++;
		while (str[i] != '\0')
		{
			ft_putchar(str[i]);
			i++;
			if (checkspace(str[i]))
			{
				while (checkspace(str[i]) && str[i] != '\0')
					i++;
				if (!(checkspace(str[i])) && str[i] != '\0')
					i--;
			}
		}
	}
	ft_putchar('\n');
}
