/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myrotone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 02:40:37 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/28 03:23:42 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar (char c)
{
	write (1, &c, 1);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int		i = 0;
		char	*str = argv[1];
		while(str[i] != '\0')
		{
			if ((str[i] >= 'a' && str[i] <= 'y') || (str[i] >= 'A' && str[i] <= 'Y'))
				str[i] += 1;
			else if (str[i] == 'z' || str[i] == 'Z')
				str[i] -= 25;
			ft_putchar(str[i]);
			i++;
		}
	}
	ft_putchar('\n');
}