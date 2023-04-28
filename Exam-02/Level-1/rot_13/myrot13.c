/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myrot13.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 02:22:59 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/28 02:33:09 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	main(int argc, char *argv[])
{
	char	*str;
	int		i;

	if (argc == 2)
	{
		str = argv[1];
		i = 0;
		while (str[i] != '\0')
		{
			if ((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M') )
				str[i] += 13;
			else if ((str[i] >= 'n' && str[i] <= 'z') || (str[i] >= 'N' && str[i] <= 'Z'))
				str[i] -= 13;
			ft_putchar(str[i]);
			i++;
		}
	}
	ft_putchar('\n');
}
