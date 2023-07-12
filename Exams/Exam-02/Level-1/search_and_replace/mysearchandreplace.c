/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysearchandreplace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 03:24:24 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/28 16:37:56 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int		ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	int		i = 0;
	char	*str;

	if (argc == 4)
	{
		if (ft_strlen(argv[2]) == 1 && ft_strlen(argv[3]) == 1)
		{
			str = argv[1];
			while (str[i] != '\0')
			{
				if (str[i] == argv[2][0])
				{
					ft_putchar(argv[3][0]);
					i++;
				}
				ft_putchar(str[i]);
				i++;
			}
			
		}
	}
	ft_putchar('\n');
}
