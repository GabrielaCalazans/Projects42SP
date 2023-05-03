/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysnaketocamel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:48:14 by gacalaza          #+#    #+#             */
/*   Updated: 2023/05/03 11:59:52 by gacalaza         ###   ########.fr       */
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
			if(str[i] == '_')
			{
				i++;
				str[i] -= 32;
			}
			ft_putchar(str[i]);
			i++;
		}
	}
	ft_putchar('\n');
}