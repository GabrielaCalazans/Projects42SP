/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myrepeat_alpha.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 01:40:49 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/28 02:12:03 by gacalaza         ###   ########.fr       */
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
	int		len;
	char	*str;
	
	if (argc == 2)
	{
		str = argv[1];
		while (str[i] != '\0')
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				len = str[i] - 'a' + 1;
			else if (str[i] >= 'A' && str[i] <= 'Z')
				len = str[i] - 'A' + 1;
			else if (!(str[i] >= 'A' && str[i] <= 'Z') || !(str[i] >= 'a' && str[i] <= 'z'))
				ft_putchar(str[i]);
			while (len > 0)
			{
				ft_putchar(str[i]);
				len--;
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
